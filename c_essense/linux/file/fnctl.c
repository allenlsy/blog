#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int val;
    if (argc != 2) {
        fputs("usage: a.out <descriptor#>\n", stderr);
        exit(1);
    }
    int i = 0;
    for (i = 0; i<argc; i++)
        printf("%d: %s\n",i,  argv[i]);
    printf("F_GETFL: %d\n", F_GETFL);

    if ( (val = fcntl(atoi(argv[1]), F_GETFL)) < 0 ) {
        printf("fcntl error for rd %d\n", atoi(argv[1]));
        exit(1);
    }
    printf("val: %d\n", val);
    
    printf("O_ACCMODE: %d\n", O_ACCMODE);
    switch (val & O_ACCMODE) {
    case O_RDONLY:
        printf("read only");
        break;
    case O_WRONLY:
        printf("write only");
        break;
    case O_RDWR:
        printf("read write");
        break;
    default:
        fputs("invalud access mode\n", stderr);
        exit(1);
    }
    
    if (val & O_APPEND)
        printf(", append");
    if (val & O_NONBLOCK)
        printf(", nonblocking");
    putchar('\n');
    return 0;
}


