#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

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
  //printf("rc from open %d\n",filedesc);
  
  n = read(filedesc, buffer, 8);
  //printf("n %d\n",n);

  for (int i=0; i < strlen(buffer); i++)
  {
      printf("%02x ",buffer[i]);
  }
  printf("\n");
  //FILE *file = fopen( argv[1], "r" );
  return 0;
}
