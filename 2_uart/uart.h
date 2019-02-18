#include <stdint.h>
#define UART_INIT_FAILURE (uart_status_t)-1

typedef uint32_t uart_status_t;
typedef uint32_t cuart_t;

uart_status_t   uart_init(void);
uart_status_t   uart_send(char c);
cuart_t         uart_read(void);
