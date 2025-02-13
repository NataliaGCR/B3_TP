#ifndef Q1_EMETTRICE_H
#define Q1_EMETTRICE_H


// Function prototypes
void OnTxDone(void);
void OnTxTimeout(void);
void OnFhssChangeChannel( uint8_t channelIndex );
void OnCadDone( void );

#endif // Q1_EMETTRICE_H