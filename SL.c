#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <termio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <math.h>
#include <unistd.h>

void writelog(FILE *fp, char *str);
void jmpstring(const char* mylog);
struct termios SerialPortSettings;



void log(char* strlog){
FILE *fp;
fp = fopen ("test.txt","w+");

fprintf("%s",strlog);
fclose(fp);
}



int main(void) {
  
log("dasdsd");
}