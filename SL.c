#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <termio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <math.h>
#include <unistd.h>

const BR = 0;
const char *buffer;

void writelog(FILE *fp, char *str){fprintf(fp, "%s", str);};
void jmpstring(const char* mylog);
struct termios SerialPortSettings;




int main(void) {
  
log("dasdsd");
}