#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc , char * argv[])
{
    int fdr,fdw,fdr1,fdr2,sizer,sizew;
    mkdir("Assignment",0700);
    
    fdr = open(argv[1],O_RDONLY);
    if(fdr < 0){ perror("Program"); exit; }

    char * status = (char *)calloc(100,sizeof(char));
    char * outputfile = (char *)calloc(100,sizeof(char));
    sprintf(outputfile,"Assignment/2_%s",argv[1]);

    fdw = open(outputfile,O_RDONLY|O_WRONLY|O_CREAT|O_TRUNC,0600);
    if(fdw < 0) { perror("Program"); exit; }
    
    int chunk = 1e6,cnt = 1,complete = 0,c= 0;
    int start = atoi(argv[2]) , end =   atoi(argv[3]);
    
    long double acutalsize = lseek(fdr,0,SEEK_END);
    long double done = 0;

    int totalsize = start;// from strating to argv[2]
    while(1)
    {
      char * BUFFER = (char *)calloc(chunk+10,sizeof(char));
      char * BUFFER2 = (char *)calloc(chunk+10,sizeof(char));
      
      if(totalsize >= chunk*cnt)
      lseek(fdr,totalsize-chunk*cnt,SEEK_SET);
      else {
        lseek(fdr,0,SEEK_SET);
        c = 1;
      }
      if(c) sizer = read(fdr,BUFFER,totalsize-chunk*(cnt-1));
      else
      sizer = read(fdr,BUFFER,chunk);
      BUFFER[sizer] = '\0';
      
      
      for(int i=0;BUFFER[i]!='\0';++i) BUFFER2[i] = BUFFER[sizer-i-1];
      write(fdw,BUFFER2,sizer);
      
      done += sizer;
      sprintf(status,"Progress:-%Lf\r",done*100/acutalsize);
      write(STDOUT_FILENO,status,strlen(status));

      if(sizer < chunk || totalsize - chunk*cnt == 0) break;
      cnt++;
    }
    
    // from argv[2] to argv[3] 
    complete = start ;
    while(complete <= end)
    {
      char * safety = (char *)calloc(chunk+10,sizeof(char));
      lseek(fdr,complete,SEEK_SET);
      if(complete + chunk <= end+1){
        sizer = read(fdr,safety,chunk);
        write(fdw,safety,chunk);
        complete += chunk;
      }
      else{
        sizer = read(fdr,safety,end+1-complete);
        write(fdw,safety,end+1-complete);
        complete = end+1;
      }
      
      done += sizer;
      sprintf(status,"Progress:-%Lf\r",done*100/acutalsize);
      write(STDOUT_FILENO,status,strlen(status));
    }
   
    // from argv[3] to ending  
    totalsize = lseek(fdr,0,SEEK_END);
    cnt = 1;
    c = 0;
    while(1)
    {
      char * BUFFER = (char *)calloc(chunk+10,sizeof(char));
      char * BUFFER2 = (char *)calloc(chunk+10,sizeof(char));
      
      if(totalsize >= complete+chunk*cnt)
      lseek(fdr,totalsize-chunk*cnt,SEEK_SET);
      else {
        lseek(fdr,complete,SEEK_SET);
        c = 1;
      }
      if(c) sizer = read(fdr,BUFFER,totalsize-complete-chunk*(cnt-1));
      else sizer = read(fdr,BUFFER,chunk);
      BUFFER[sizer] = '\0';

      for(int i=0;BUFFER[i]!='\0';++i) BUFFER2[i] = BUFFER[sizer-i-1];
      write(fdw,BUFFER2,sizer);
      
      done += sizer;
      sprintf(status,"Progress:-%Lf\r",done*100/acutalsize);
      write(STDOUT_FILENO,status,strlen(status));

      if(sizer < chunk || totalsize -complete - chunk*cnt == 0) break;
      cnt++;
    }
    write(STDOUT_FILENO,"\n",1);
    if(close(fdr) < 0) { perror("Program"); exit(1); }
    if(close(fdw) < 0) { perror("Program"); exit(1); }
    return 0;
}




