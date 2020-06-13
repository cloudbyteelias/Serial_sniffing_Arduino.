#include <stdio.h>
#include <fcntl.h>   
#include <termios.h> 
#include <unistd.h>  
#include <errno.h>   
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

 int serial_log();
 int deamon(); 
  
  int serial_log(void){
      FILE  *out;
      struct termios serial;	                      
      int fd;
      const char port[] = "/dev/ttyUSB0";       
      fd = open(port,O_RDWR | O_NOCTTY);								
        if(fd == -1){						
        	  printf("error to open serial port %s",port);
        }else
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
		
    char read_buffer[100];   
		long int  bytes_read = 0;    
 		int i = 0;

		bytes_read = read(fd,&read_buffer,100); 
		
    for(i=0;i<bytes_read;i++){
         out = fopen("log","a");
         fprintf(out,"%c",read_buffer[i]);
         fclose(out);
         
    }	 
     
		close(fd); 

    return 0;
  }

    int deamon(void){
    FILE *fp = NULL;
    pid_t process_id = 0;
    pid_t sid = 0;

    process_id = fork();

    if(process_id < 0){printf("Error to create fork \n");exit(1);}
    if(process_id > 0){printf("Running %d", process_id);exit(0);}
    umask(0);
    sid = setsid();

    if(sid < 0){exit(1);}
    chdir("/tmp");
    close(STDIN_FILENO);
    close(STDERR_FILENO);
    close(STDOUT_FILENO);

    fp = fopen("SERIALd.log","w+");
      while(1){ 
          sleep(10);
          fprintf(fp, "SERIAL LOG RUNNING \n");
          fflush(fp);
          serial_log();
        }
    fclose(fp);
    return 0;
    
    }


  int main(void){
    deamon();      
      
  }
