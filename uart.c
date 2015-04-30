#include <avr/io.h>


#define BAUDRATE 9600UL


#define UBRR_VAL (F_CPU / 16 / BAUDRATE - 1)


static void uart_putchar(char c) {
	while(!(UCSR0A & _BV(UDRE0)));
	UDR0 = c;
}

static char uart_getchar() {
	while(!(UCSR0A & _BV(RXC0)));
	return UDR0;
}


void uart_init() {
	UBRR0L = (unsigned char)(UBRR_VAL & 0xff);
	UBRR0H = (unsigned char)(UBRR_VAL >> 0x8);

	/* Enable receiver and transmitter */
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);

	/* Set frame format: 8data, 1stop bit */

	/* needed for AVR USART */
	UCSR0C = (3 << UCSZ00);
}

int uart_write(char *buf, int len) {
	int i;
	i = 0;
	while(i < len) {
		uart_putchar(buf[i]);
		++i;
	}
	return i;
}

int uart_read(char *buf, int len) {
	int i;
	i = 0;
	while(i < len) {
		buf[i] = uart_getchar();
		++i;
	}
	return i;
}

