#ifndef Q1_RECEPTRICE_H
#define Q1_RECEPTRICE_H


// Function prototypes
void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr);
void OnRxTimeout(void);
void OnRxError(void);
void OnFhssChangeChannel( uint8_t channelIndex );
void OnCadDone( void );

#endif // Q1_RECEPTRICE_H