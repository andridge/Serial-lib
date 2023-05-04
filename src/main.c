#include "serial-lib/serial_port.h"
#include <stdio.h>

#define BUFFER_SIZE 256

int main (){

SerialPort port;
const char* port_name = "/dev/tty.usbserial-110";  // Change this to the correct port name
speed_t baudrate = 9600;
SerialPort_init(&port, port_name, baudrate);

// Check if the object was created successfully
if (SerialPort_get_fd(&port) == -1) {
  return 1;
}

char buffer[BUFFER_SIZE];
int bytes_read;
float numberone;
float numbertwo;
 // Read data from the serial port
    bytes_read = SerialPort_read(&port, buffer, BUFFER_SIZE);
    
     if (bytes_read > 0) {
     //change scanf to carter to how serial is sent  
       sscanf(buffer, "%*s %*s %f %*s %*s %*s %f",&numberone ,&numbertwo);
       printf("number one : ", numberone);
       printf("number two : ", numbertwo);
       SerialPort_flush(&port);
     }
     return 0 ;
}
