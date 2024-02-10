#include "headers.h"

int cnt_bg = 0;

void zombie_check() {
    struct dirent *file;
    DIR *navigate_dir = opendir("/proc");
    if (navigate_dir == NULL) return;
    char *str[1000]; 
    int status,check,pids[1000],child = 0;
    // checking for all running process
    while ((file = readdir(navigate_dir)) != NULL) {
        
        if (file->d_name[0] <= '9' && file->d_name[0] >= '0') {
            
            char data_file[1000];
            sprintf(data_file, "/proc/%s/stat", file->d_name);
            
            FILE *f = fopen(data_file, "r");
            if (f == NULL) continue;
            int pid = -1, tpgrp =  -1;
            char state , name[1000],name2[1000];
            fscanf(f, "%d (%s ", &pid, name);
            // printf("%ld\n",strlen(name));
            for(int i=0;i<strlen(name)-1;++i)   
            name2[i] = name[i];
            
            fscanf(f, " %c ", &state);
            fscanf(f, " %d", &tpgrp);
            if (tpgrp == (int) getpid()) {
                str[child] = (char *)malloc(sizeof(char)*1000);
                pids[child] = pid;
                strcpy(str[child++],name);
            }
            fclose(f);
        }
    }
    closedir(navigate_dir);

    while ((check = waitpid(-1, &status, WNOHANG)) > 0) {
        int normal = 0;
        if (WIFEXITED(status)) normal = 1;
        else if (WIFSIGNALED(status)) normal = 0;
        char name[1000];
        strcpy(name, "");
        for (int i = 0;; i++) {
            if(i == child)
            break;
            else if (pids[i] == check) {
                strcpy(name, str[i]);
                break;
            }
        }
        char * name2;
        name2 = (char *)malloc(sizeof(char)*1000);
        for(int i=0;i<strlen(name)-1;++i)   
            name2[i] = name[i];
        cnt_bg--;
        if(normal)  printf("\n%s with pid %d exited normally\n",name2, check);
        else printf("\n%s with pid %d exited abnormally\n",name2, check);
        break;
    }
}

void sys_commands(int i,char * temp ,char * tokens[],int bg){
	int status ;
	pid_t pid ;
	pid = fork();
    if(pid < 0){
        perror("Error(forking)"); // Error in forking 
    }
    else if(pid == 0){
        // this is a child process
		int child_pid = getpid(); 
		if(bg){
			setpgid(0,0);
		}
        if(execvp(tokens[0],tokens) == -1){
            perror("Invalid Command");
        }
        exit(EXIT_FAILURE);
    }
	// parent process
	else {  
		// background process
		if(bg){
			cnt_bg++;
			printf("[%d]  %d\n",cnt_bg,pid);
		}
		// foreground process
		else {
			waitpid(pid,NULL,0);
			// do 
			// {
			// 	// waitpid(pid, &status, WUNTRACED);
			// } 
			// while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
}
