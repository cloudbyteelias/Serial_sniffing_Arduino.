#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <termio.h>
#include <unistd.h>
#include <errno.h>
#define FILE *fp;


struct termios SerialPortSettings;






void banner(){


}

void open(){


}


void log(txt){
fp = fopen ("test.txt","w+");
fputs()

}



int main(void) {
   FILE *fp;

   fp = fopen("test.txt", "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);
}