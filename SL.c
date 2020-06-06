#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <termio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <math.h>
#include <unistd.h>

const unsigned int BR = 0;
const char *buffer;
const short char *lport;

void writelog(FILE *fp, char *str){fprintf(fp, "%s", str);};

void openserialport(){
   
      struct termios PORT;
      tcgetattr(fd, &SerialPortSettings);	
		cfsetispeed(&SerialPortSettings,B9600);                      
		cfsetospeed(&SerialPortSettings,B9600); 
		SerialPortSettings.c_cflag &= ~PARENB;   
		SerialPortSettings.c_cflag &= ~CSTOPB;   
		SerialPortSettings.c_cflag &= ~CSIZE;
		SerialPortSettings.c_cflag |=  CS8;  
		SerialPortSettings.c_cflag &= ~CRTSCTS; 
		SerialPortSettings.c_cflag |= CREAD | CLOCAL; 
		SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);
		SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);  
		SerialPortSettings.c_oflag &= ~OPOST;
		SerialPortSettings.c_cc[VMIN] = 10; 
		SerialPortSettings.c_cc[VTIME] = 0; 
}





void banner(){
printf("=====|SR-INO|=====");
};

int main(void) {
   banner();

}