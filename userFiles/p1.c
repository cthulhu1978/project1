#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void printBufferLine(unsigned char buffer[], int filedesc);

int main(int argc, char const *argv[]) {
  int filedesc, n;
  // Create buffer to hold file in.
  unsigned char buffer[1024];
  // exit if too few args::::
  if (argc < 2) {exit(0);}
  // Handle hello world scenario
  if(strcmp(argv[1], "-hw") == 0) { printf("%s\n","Hello world" ); exit(0); }

  //Open the file in read only mode
  filedesc = open(argv[1], O_RDONLY);

  printBufferLine(buffer, filedesc);
  return 0;
}

void printBufferLine(unsigned char buffer[], int filedesc){
  int fileBytes;
  fileBytes = read(filedesc, buffer, 16);
  while(fileBytes > 0){
    for (int i=0; i < fileBytes; i++)
    {
        printf("%02x",buffer[i]);
        if(i % 2 == 1){printf(" ");}
    }

      if(fileBytes < 16){
        //printf(" FILEBYTES: %d ",fileBytes);
        for (int i = 0; i < (36 - fileBytes); i++) {
          printf(" ");
        }
      }

    printf(" " );
    for(int j=0; j < fileBytes; j++){
      if(isprint(buffer[j])){
        printf("%c", buffer[j] );
      } else {
        printf("." );
      }
    }
      printf("\n");
    fileBytes = read(filedesc, buffer, 16);
    //printf("%d fileBytes read \n", fileBytes);
  }
}
