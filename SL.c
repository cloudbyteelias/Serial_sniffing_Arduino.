#include <stdio.h>
#include <fcntl.h>   
#include <termios.h> 
#include <unistd.h>  
#include <errno.h>   
#include <time.h>
#include <stdlib.h>


 int serial_log();

  
  int serial_log(void){
      FILE  *out;
      char line [50];
      struct termios serial;	                      
      int fd;
      const char port[] = "/dev/ttyUSB0";      // Edit for other port 
      fd = open(port,O_RDWR | O_NOCTTY);			//O_RDWR Read and write,					
        if(fd == -1)						
        	   printf("\n  Error Fail open port %s",port);
        else
             printf("\n  %s Opened Successfully", port);

		if(tcgetattr(fd, &serial) < 0) {printf("ERROR IN C_FLAG CONFIG %s",port);}
		
    tcgetattr(fd, &serial);	
		cfsetispeed(&serial,B9600); 
		cfsetospeed(&serial,B9600); 
		serial.c_cflag &= ~PARENB;   
		serial.c_cflag &= ~CSTOPB;  
		serial.c_cflag &= ~CSIZE;	 
		serial.c_cflag |=  CS8;      
		serial.c_cflag &= ~CRTSCTS;                          
		serial.c_cflag |= CREAD | CLOCAL; 
		serial.c_iflag &= ~(IXON | IXOFF | IXANY);          
		serial.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);                           
		serial.c_oflag &= ~OPOST;
		serial.c_cc[VMIN] = 10; 
		serial.c_cc[VTIME] = 0; 
		
    if(cfsetispeed(&serial, B9600) < 0 || cfsetospeed(&serial, B9600) < 0) {printf("SPEED ERROR IN %s",port);}
    if(tcsetattr(fd, TCSAFLUSH, &serial) < 0) {printf(" %s ERROR TO SET attributes",port);}else{printf("%s Read Okay",port);}
		
    char read_buffer[10];   
		int  bytes_read = 0;    
 		int i = 0;

		bytes_read = read(fd,&read_buffer,10); 
		
    for(i=0;i<bytes_read;i++){
         out = fopen("log","a");
         fprintf(out,"%c",read_buffer[i]);
         fclose(out);
         
    }	 
     


		close(fd); 


  }

  //int get_time(void){
  //  const time_t timer = time(NULL);
  //  time = ("ctime is %s\n", ctime(&timer));
  //  printf("%d",time);
 // }



  int main(void){
          
  serial_log();    

  
  }
