#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main()
{
    int fd = open("foo.txt", O_RDONLY | O_CREAT) ; // O_RDONLY is for reading the file (read only)
    //O_CREAT :- creating
    printf("%d\n",fd);//fd :- file descriptor 
    // fd = 0 for stdin
    //fd = 1 for stdout
    // fd = 2 for stderr
    if(fd == -1)
    {
        //print which type of error have in the code
        printf("Error  Number %d\n",errno);
        
        // print program detail success or failure
        perror("Program");
    }
    return 0;
}