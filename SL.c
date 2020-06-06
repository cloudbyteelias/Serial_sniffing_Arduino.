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
void writelog(FILE *fp, char *str){fprintf(fp, "%s", str);};

void openserialport(){
   
}





void banner(){
printf("=====|SR-INO|=====");
};

int main(void) {
   banner();

}