#include "headers.h"
#include "shellprompt.h"
#include "token.h"
#include "history.h"


char dir[1000];
char prevdir[1000] = "~";
char homedir[1000];
char dir_store[1000] = "";


void func(int check)
{
    if (check == SIGCHLD)
        zombie_check(); // checks if process exits normally or abnormally
}

int create_fir = 1;
int main(int argc, char *argv[])
{
    entershell();
    int c = 1;
    char x[1000];
    strcpy(dir, dirctry());
    getcwd(homedir, sizeof(homedir));
    FILE * history_file;
    char path[1000];
    strcpy(path, homedir);
    strcat(path, "/history.txt");
    if(history_file = fopen(path,"r")){
        fclose(history_file);
    }
    else {
        history_file = fopen(path,"w");
        fclose(history_file);
    }
    extern char *str[21];
    for (int i = 0; i < 21; ++i)
    {
        str[i] = (char *)malloc(sizeof(str[i]));
    }

    char timetaken[100];
    strcpy(timetaken,"");
    time_t start,end;

    while (1)
    {
        printf("<\033[1;32m%s\033[01;00m:\033[1;34m%s%s\033[01;00m> ", shellprompt(), dir,timetaken);
        strcpy(timetaken,"");
        x[0] = '\0';// for making length of x is equal to zero so that previous input is cleared out
        scanf("%[^\n]s",x);
        getchar();
        signal(SIGCHLD, func);
        store_info(x, homedir);
        if (strcmp(x, "quit") == 0)
        {
            // exitshell();
            break;
        }
        strcpy(dir_store,dir);
        time(&start);
        tokeniseamp(x, dir, prevdir, homedir);
        time(&end);
        if(end-start >= 1){
            int val = floor(end-start);
            sprintf(timetaken,"took %ds",val);
        }
        // printf("%s\n",timetaken);
    }
    return 0;
}