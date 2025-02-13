const uint8_t Msg[] = "Air Quality Data";
const uint8_t Identifier = 0x01; // Replace with your identifier between 01 and 13

uint16_t BufferSize = BUFFER_SIZE;
uint8_t Buffer[BUFFER_SIZE];

Air_Quality airQuality(A2, A1); // Initialize Air_Quality with Vsensor on A2 and Vheater on A1

int main(void) 
{
    // Initialize Radio driver
    RadioEvents.TxDone = OnTxDone;
    RadioEvents.RxDone = OnRxDone;
    RadioEvents.RxError = OnRxError;
    RadioEvents.TxTimeout = OnTxTimeout;
    RadioEvents.RxTimeout = OnRxTimeout;
    Radio.Init(&RadioEvents);

    // Verify the connection with the board
    while (Radio.Read(REG_VERSION) == 0x00) 
    {
        debug("Radio could not be detected!\n\r", NULL);
        wait(1);
    }

    Radio.SetChannel(RF_FREQUENCY);
    Radio.SetTxConfig(MODEM_LORA, TX_OUTPUT_POWER, 0, LORA_BANDWIDTH,
                       LORA_SPREADING_FACTOR, LORA_CODINGRATE,
                       LORA_PREAMBLE_LENGTH, LORA_FIX_LENGTH_PAYLOAD_ON,
                       LORA_CRC_ENABLED, LORA_FHSS_ENABLED, LORA_NB_SYMB_HOP,
                       LORA_IQ_INVERSION_ON, 2000);

    Radio.SetRxConfig(MODEM_LORA, LORA_BANDWIDTH, LORA_SPREADING_FACTOR,
                       LORA_CODINGRATE, 0, LORA_PREAMBLE_LENGTH,
                       LORA_SYMBOL_TIMEOUT, LORA_FIX_LENGTH_PAYLOAD_ON, 0,
                       LORA_CRC_ENABLED, LORA_FHSS_ENABLED, LORA_NB_SYMB_HOP,
                       LORA_IQ_INVERSION_ON, true);

    debug("Starting Transmission\r\n");
    
    while (1) 
    {
        // Read air quality index (Q) and sensor voltage (Vsensor)
        uint16_t Q = airQuality.getAirQualityIndex();
        float Vsensor = airQuality.avgVoltage();

        // Prepare the message to send
        Buffer[0] = Identifier;
        Buffer[1] = Q; // Assuming Q fits in a uint8_t, adjust if necessary
        memcpy(&Buffer[2], &Vsensor, sizeof(Vsensor)); // Copy Vsensor to Buffer

        // Send the data
        Radio.Send(Buffer, BufferSize);
        wait_ms(10000); // Send every 10 seconds
    }
}