#include "headers.h"

void tokeniseamp(char * text, char * dir , char * prevdir , char * homedir){
    char temp[1000];
    strcpy(temp,text);
    char * tokens[1000];
    char * start = tokens[0];
    int ampi = 0;
    tokens[0] = strtok(text,"&");
    for(ampi = 0;;ampi++){
        if(tokens[ampi] == NULL)
        break;
        else tokens[ampi+1] = strtok(NULL,"&");
    }
    if(ampi == 1){
        int len = strlen(temp);
        while(temp[len-1]==' ') len--;
        if( temp[len-1] =='&' )     tokenise_sc(1,tokens[0],1,dir,prevdir,homedir);
        else    tokenise_sc(1,tokens[0],0,dir,prevdir,homedir);
    }
    else{
        for(int i=0;i<ampi;++i){
            if( (i+1)!=ampi )   tokenise_sc(i+1,tokens[i],1,dir,prevdir,homedir);
            else if(temp[strlen(temp)-1] == '&')  tokenise_sc(i+1,tokens[i],1,dir,prevdir,homedir);// sc :- semicolon
            else tokenise_sc(i+1,tokens[i],0,dir,prevdir,homedir);
        }
    }
}

void tokenise_sc(int  index,char * text ,int bg , char * dir , char * prevdir, char * homedir)
{
    char temp[1000];
    strcpy(temp,text);
    char * tokens[1000];
    int ti = 0 ;
    tokens[0] = strtok(text,";");
    for(ti=0;;++ti){
        if(tokens[ti]==NULL){
            break;
        }
        else tokens[ti+1] = strtok(NULL,";");  
    }
    for(int i=0;i<ti;++i){
        tokenise_space(index,temp,tokens[i],bg,dir,prevdir, homedir);
    }
}

void tokenise_space(int index ,char * temp,char * text ,int bg, char * dir , char * prevdir, char * homedir)
{
    char * tokens[10000];
    int si=0;
    tokens[0] = strtok(text," \t");    
    for(si=0;;++si){
        if(tokens[si]==NULL){
            break;
        }
        else tokens[si+1] = strtok(NULL," \t");  
    }
    if(strcmp(tokens[0],"cd") == 0){
        char store[10000] = "";
        strcpy(store,dir);
        cd1(prevdir,dir,tokens,si,homedir);
        strcpy(prevdir,store);
    }
    else if(strcmp(tokens[0],"pwd") == 0){
        pwd1();
    }
    else if(strcmp(tokens[0],"clear") == 0){
        system("clear");
    }
    else if(strcmp(tokens[0],"echo") == 0){
        echo1(tokens);
    }
    else if(strcmp(tokens[0],"ls") == 0){
        ls1(tokens,si);
    }
    else if(strcmp(tokens[0],"pinfo") == 0){
        pinfo1(tokens,si,homedir);
    }
    else if(strcmp(tokens[0],"history") == 0){
        history1(homedir);
    }
    else if(strcmp(tokens[0],"discover") == 0){
        discover1(tokens,si);
    }
    else sys_commands(index,temp,tokens,bg);
}