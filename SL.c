#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <termio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

const unsigned int BR = 0;
const char *buffer;
const short char *lport;

void writelog(FILE *fp, char *str){fprintf(fp, "%s", str);};

void openserialport(){
  int p; 

  p = open("%s",lport);
  if(p = -1){
     printf("Error to open port");
  }else{
     printf("Porta aberta com sucesso");
  }    
            
      struct termios PORT;
      tcgetattr(fd, &PORT);	
		cfsetispeed(&PORT,B9600);                      
		cfsetospeed(&PORT,B9600); 
		PORT.c_cflag &= ~PARENB;   
		PORT.c_cflag &= ~CSTOPB;   
		PORT.c_cflag &= ~CSIZE;
		PORT.c_cflag |=  CS8;  
		PORT.c_cflag &= ~CRTSCTS; 
		PORT.c_cflag |= CREAD | CLOCAL; 
		PORT.c_iflag &= ~(IXON | IXOFF | IXANY);
		PORT.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);  
		PORT.c_oflag &= ~OPOST;
		PORT.c_cc[VMIN] = 10; 
		PORT.c_cc[VTIME] = 0; 

   if((tcsetattr(fd,TCSANOW,&SerialPortSettings)) != 0){
		printf("OKAY");    
   }else{
      printf("falha");
   }
            
   tcflush(p,TCIFLUSH);
   



}





void banner(){
printf("=====|SR-INO|=====");
};

int main(void) {
   banner();

}