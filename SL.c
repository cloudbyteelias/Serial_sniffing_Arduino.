#include <stdio.h>
#include <fcntl.h>   
#include <termios.h> 
#include <unistd.h>  
#include <errno.h>   
	
    void main(void){
    	
        	int fd;
        	fd = open("/dev/ttyUSB0",O_RDWR | O_NOCTTY);								
        	if(fd == -1)						
            	   printf("\n  Error! in Opening ttyUSB0  ");
        	else
            	   printf("\n  ttyUSB0 Opened Successfully ");

		
        
        struct termios SerialPortSettings;	                      
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
		if((tcsetattr(fd,TCSANOW,&SerialPortSettings)) != 0) 
		    printf("\n  ERROR ! in Setting attributes");
		else
             puts("read port");

		tcflush(fd, TCIFLUSH);   

		char read_buffer[32];   
		int  bytes_read = 0;    
 		int i = 0;

		bytes_read = read(fd,&read_buffer,32); 
		for(i=0;i<bytes_read;i++)	 
		    printf("%c",read_buffer[i]);

		close(fd); 

    	}