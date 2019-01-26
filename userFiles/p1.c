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
  int sum = 0;
  fileBytes = read(filedesc, buffer, 16);
  while(fileBytes > 0){
    printf("%08x: ",sum);

    int spaces = 0;
    for (int i=0; i < fileBytes; i++)
    {
        printf("%02x",buffer[i]);
        spaces+=2;
        if(i % 2 == 1){printf(" "); spaces+=1;}
    }
    //printf(" spaces: %d ",spaces );

    sum+= fileBytes;
      if(fileBytes < 16){
        //printf(" FILEBYTES: %d ",fileBytes);
        for (int i = 0; i < (40 - spaces); i++) {
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
