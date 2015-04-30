UART
====

UART driver for Arduino Uno

###Usage


* Set up your baudrate definition in *uart.c* 
```c

#define BAUDRATE 9600UL
```
* Write your code, e.g. in *main.c*

```c
...
#include <uart.h>

int main() {

  char c;
  c = ANY_UART_DATA_BYTE;
  
  uart_write(&c, 1);
  uart_read(&c, 1);
  
  return 0;
}
```
