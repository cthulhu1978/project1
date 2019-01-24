#include <stdio.h>

int main(int argc, char const *argv[]) {
  unsigned char buffer[1024];

  FILE *fPointer = fopen( argv[1], "r" );

  while(!feof(fPointer)){
    
  }

  fclose(fPointer);
  return 0;
}
