#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

#include "p0.h"


int main(int argc, char *argv[])
{
    int i, j, rc;
    int x[100];
    char s[100] = "harry potter";

    printf("FOO became %d\n",FOO);
    j = 32;
    fprintf(stderr,"j=%d  \n",j);
    write(1,&j,sizeof(int));
    return 0;
}
