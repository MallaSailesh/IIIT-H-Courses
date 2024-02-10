#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fdr,fdw , sizer,sizew ;
    mkdir("Assignment/",0700);
    fdr = open(argv[1],O_RDONLY);
    char * outputfile = (char *)calloc(1000,sizeof(char));
    char * status = (char *)calloc(100,sizeof(char));
    sprintf(outputfile,"Assignment/1_%s",argv[1]);
    // fdw = open("1_A.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);// read :- 0400 , write :- 0200 , execute :- 0100 fro the owner
    // 0040 :- read ,0020 :- write , 0010 :- execute for the groups :- 0070 to give all permissions for groups 
    // 0004 :-- read ,0002 :- write , 0001 :- execute for others :- 0007 to give all permissions for others
    // thats why chmod +x 777 is used to give permissions for all (first 7 for user , second one for their gorup , third one for all).
    fdw = open(outputfile,O_RDONLY|O_WRONLY|O_CREAT|O_TRUNC,0600);
    if(fdr < 0) { perror("c1"); exit(1); };
    if(fdw < 0) { perror("c1"); exit(1); };
    long double totalsize = lseek(fdr,0,SEEK_END);
    long double done = 0;
    int cnt = 1,c = 0,chunk = 5;
    while(1)
    {
       char *BUFFER = (char *)calloc(chunk+5,sizeof(char));
       char *BUFFER2 = (char *)calloc(chunk+5,sizeof(char));
       if(totalsize > chunk*cnt)
       lseek(fdr,totalsize-(chunk)*cnt,SEEK_SET);
       else {
           lseek(fdr,0,SEEK_SET);
           c = 1;
       }
       if(c)
       sizer = read(fdr,BUFFER,totalsize-chunk*(cnt-1));
       else 
       sizer = read(fdr,BUFFER,chunk);
       BUFFER[sizer] = '\0';
       done += sizer;
       sprintf(status ,"Progress:-%Lf\r",done*100/totalsize);
       write(STDOUT_FILENO,status,strlen(status));
       for(int i=0;BUFFER[i]!='\0';i++)
       BUFFER2[sizer-i-1] = BUFFER[i];
       write(fdw,BUFFER2,sizer); 
       if(sizer < chunk || totalsize - chunk*cnt == 0) break;
       cnt++;
    }
    write(STDOUT_FILENO,"\n",1);
    if(close(fdr) < 0) { perror("c1"); exit(1); }
    if(close(fdw) < 0) { perror("c1"); exit(1); }
    return 0;
}


