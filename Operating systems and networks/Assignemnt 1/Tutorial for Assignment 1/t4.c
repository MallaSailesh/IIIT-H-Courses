#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int fd , size ;
    fd = open("foo.txt",O_WRONLY | O_CREAT | O_TRUNC , 0644);
    // O_CREAT is for creating the file if not created 
    // O_WRONLY is for writing only
    // O_TRUNC is for truncating 
    if(fd < 0) {perror("c1"); exit(1);};

    size = write(fd,"hello world1234\n",strlen("hello world1234\n")); // read function returns the number of bytes succesfully read 
    // like if size is 100 bytes and as we took 10 as max size it will return 10 (10 bytes read succesfully read)
    // if size of file is 5 bytes it will return 5 (as 5 bytes read succesfully)
    printf("called function write(%d,\"hello world1234\\n\",%d)." 
            "\nIt returned %d bytes\n",fd,strlen("hello world1234\n"),size);
    close(fd); 
}