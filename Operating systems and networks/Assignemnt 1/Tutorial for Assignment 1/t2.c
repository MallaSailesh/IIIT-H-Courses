#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
    int fd1 = open("foo.txt", O_RDONLY ) ; // O_RDONLY is for reading the file (read only)

    if(fd1 < 0)
    {
        // print program detail success or failure
        perror("c1");// perror is used for writing to stderr
        exit(1);
    }
    // printing the file desciptor 
    printf("opened the fd = %d\n",fd1);
    
    if(close(fd1) < 0)
    {
        perror("c1");
        exit(1);
    }

    printf("closed the fd.\n");
    return 0;
}