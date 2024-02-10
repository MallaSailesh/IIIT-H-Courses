#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
    int fd , size ;
    char *BUFFER = (char *)calloc(100,sizeof(char));
    fd = open("foo.txt",O_RDONLY);
    if(fd < 0) {perror("c1"); exit(1);};

    size = read(fd, BUFFER,10); // read function returns the number of bytes succesfully read 
    // like if size is 100 bytes and as we took 10 as max size it will return 10 (10 bytes read succesfully read)
    // if size of file is 5 bytes it will return 5 (as 5 bytes read succesfully)
    printf("called function read(%d,c,10). \nreturned that" 
            " %d bytes were read.\n",fd,size);
    BUFFER[size] = '\0';
    printf("Those bytes are as follows: %s\n", BUFFER);
}