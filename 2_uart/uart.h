#ifndef UART_H
#define UART_H

#include <stdint.h>
#define UART_INIT_SUCCESS ((uart_status_t) 0)
#define UART_INIT_FAILURE ((uart_status_t) -1)
#define UART_READ_ERROR   ((cuart_t) 255)
#define UART ((NRF_UART_REG*)0x40002000)

#define RXD_PIN (25)
#define TXD_PIN (24)

typedef int32_t uart_status_t;
typedef char cuart_t;

typedef struct {
    volatile uint32_t STARTRX;
    volatile uint32_t STOPRX;
    volatile uint32_t STARTTX;
    volatile uint32_t STOPTX;
    volatile uint32_t RESERVED0[3];
    volatile uint32_t SUSPEND;
    volatile uint32_t RESERVED1[56];
    volatile uint32_t CTS;
    volatile uint32_t NCTS;
    volatile uint32_t RXDRDY;
    volatile uint32_t RESERVED2[4];
    volatile uint32_t TXDRDY;
    volatile uint32_t RESERVED3[1];
    volatile uint32_t ERROR;
    volatile uint32_t RESERVED4[7];
    volatile uint32_t RXTO;
    volatile uint32_t RESERVED5[110];
    volatile uint32_t INTEN;
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR;
    volatile uint32_t RESERVED6[93];
    volatile uint32_t ERRORSRC;
    volatile uint32_t RESERVED7[31];
    volatile uint32_t ENABLE;
    volatile uint32_t RESERVED8[1];
    volatile uint32_t PSELRTS;
    volatile uint32_t PSELTXD;
    volatile uint32_t PSELCTS;
    volatile uint32_t PSELRXD;
    volatile uint32_t RXD;
    volatile uint32_t TXD;
    volatile uint32_t RESERVED9[1];
    volatile uint32_t BAUDRATE;
    volatile uint32_t RESERVED10[17];
    volatile uint32_t CONFIG;

} NRF_UART_REG;

uart_status_t   uart_init(void);
uart_status_t   uart_send(char c);
cuart_t         uart_read(void);
//Deprecated!! Use iprintf instead
uart_status_t   uart_write(char* msg, int size);

#endif //UART_H
