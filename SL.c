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

void writelog(FILE *fp, char *str){fprintf(fp, "%s", str);};



void openserialport(){
  
const unsigned int BR = 0;
const char *buffer;
const char *lport = "/dev/ttyUSB0";
int p; 

  p = open("%s",lport,O_RDWR | O_NOCTTY);
  if(p = -1){
     printf("Error to open port");
  }else{
     printf("Porta aberta com sucesso");
  }    
            
      struct termios PORT;
      tcgetattr(p, &PORT);	
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

   if((tcsetattr(p,TCSANOW,&PORT)) != 0){
		printf("OKAY");    
   }else{
      printf("falha");
   }
            
   tcflush(p,TCIFLUSH);
   BR = read(p,&buffer);

   for (int i=0; i < BR; i++){
      printf("%c",BR[i]);
   }
   
   close(p);
      
}





void banner(){
printf("=====|SR-INO|=====");
};

int main(void) {
   banner();

}