
#ifndef UART_H
#define UART_H

void uart_init();

int uart_read(char *buf, int len);
int uart_write(char *buf, int len);

#endif /* UART_H */
