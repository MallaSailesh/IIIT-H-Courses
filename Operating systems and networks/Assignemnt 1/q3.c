#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
    int fdr1, fdr2 , sizer;
    char * newfile = (char *)calloc(100,sizeof(char));
    sprintf(newfile,"%s/%s",argv[3],argv[1]);
    fdr1 = open(newfile,O_RDONLY); // newfile 
    fdr2 = open(argv[2],O_RDONLY); // oldfile 
    if(fdr1 < 0) { perror("Program"); exit(1); }
    if(fdr2 < 0) { perror("Program"); exit(1); }
    int oldfilesize  = lseek(fdr2,0,SEEK_END);
    int newfilesize = lseek(fdr1,0,SEEK_END);
    int check = 0, chunk = 5, cnt = 1 , c = 0;
    
    struct stat datastorage;
    // checking if directory is created or not
    if(stat(argv[3],&datastorage) == 0 & (S_ISDIR(datastorage.st_mode)) ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Directory is created: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Directory is created: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(oldfilesize != newfilesize) check = 1;
    
    while(check == 0)
    {
        char * BUFFER = (char *)calloc(chunk+10,sizeof(char));
        char * checking = (char *)calloc(chunk+10,sizeof(char));
        if(oldfilesize - chunk * cnt >= 0)   lseek(fdr2,oldfilesize-chunk*cnt,SEEK_SET);
        else {
            lseek(fdr2,0,SEEK_SET);
            c = 1;
        }
        lseek(fdr1,chunk*(cnt-1),SEEK_SET);
        if(c) sizer = read(fdr2,BUFFER,oldfilesize-chunk*(cnt-1));
        else sizer = read(fdr2,BUFFER,chunk);
        BUFFER[sizer] = '\0'; 
        read(fdr1,checking,chunk);
        for(int i=0;BUFFER[i]!='\0';++i)
        {
            if(BUFFER[sizer-i-1]!=checking[i]){
                check = 1;
                break;
            }
        }
        if(sizer < chunk || oldfilesize - chunk*cnt == 0) break;
        cnt++;
    }
    
    char * printing = (char *)calloc(100,sizeof(char));
    if(check){
        sprintf(printing,"Whether file contents are reversed in newfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        sprintf(printing,"Whether file contents are reversed in newfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    
    // checking permissions for new file
    stat(newfile,&datastorage); 
    write(STDOUT_FILENO,"\t\t\t\e[1mPermissions for New File\n\e[m",strlen("\t\t\t\e[1mPermissions for New File\n\e[m"));
    if( datastorage.st_mode & S_IRUSR ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has read permissions on newfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has read permissions on newfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IWUSR ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has write permissions on newfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has write permissions on newfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IXUSR ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has execute permissions on newfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has execute permissions on newfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IRGRP ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has read permissions on newfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has read permissions on newfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IWGRP ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has write permissions on newfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has write permissions on newfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IXGRP ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has execute permissions on newfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has execute permissions on newfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IROTH ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has read permissions on newfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has read permissions on newfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IWOTH ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has write permissions on newfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has write permissions on newfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IXOTH ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has execute permissions on newfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has execute permissions on newfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    
    
    
    // Permissions for directory
    stat(argv[3],&datastorage); 
    write(STDOUT_FILENO,"\t\t\t\e[1mPermissions for Directory\n\e[m",strlen("\t\t\t\e[1mPermissions for Directory\n\e[m"));
    if( datastorage.st_mode & S_IRUSR ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has read permissions on directory: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has read permissions on directory: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IWUSR ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has write permissions on directory: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has write permissions on directory: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IXUSR ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has execute permissions on directory: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has execute permissions on directory: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IRGRP ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has read permissions on directory: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has read permissions on directory: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IWGRP ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has write permissions on directory: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has write permissions on directory: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IXGRP ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has execute permissions on directory: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has execute permissions on directory: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IROTH ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has read permissions on directory: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has read permissions on directory: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IWOTH ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has write permissions on directory: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has write permissions on directory: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IXOTH ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has execute permissions on directory: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has execute permissions on directory: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }


    
    //Permissions for oldfile 
    stat(argv[2],&datastorage); 
    write(STDOUT_FILENO,"\t\t\t\e[1mPermissions for Old file\n\e[m",strlen("\t\t\t\e[1mPermissions for Old file\n\e[m"));
    if( datastorage.st_mode & S_IRUSR ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has read permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has read permissions on oldfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IWUSR ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has write permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has write permissions on oldfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IXUSR ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has execute permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"User has execute permissions on oldfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IRGRP ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has read permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has read permissions on oldfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IWGRP ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has write permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has write permissions on oldfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IXGRP ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has execute permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Group has execute permissions on oldfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IROTH ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has read permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has read permissions on oldfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IWOTH ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has write permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has write permissions on oldfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    if(datastorage.st_mode & S_IXOTH ){ 
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has execute permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }
    else {
        char * printing = (char *)calloc(100,sizeof(char));
        sprintf(printing,"Others has execute permissions on oldfile: No\n");
        write(STDOUT_FILENO,printing,strlen(printing));
    }

    if(close(fdr1) < 0) { perror("c1"); exit(1); }
    if(close(fdr2) < 0) { perror("c1"); exit(1); }

    return 0;
}



