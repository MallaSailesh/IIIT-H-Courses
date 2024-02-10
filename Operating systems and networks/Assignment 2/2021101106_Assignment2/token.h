#ifndef _TOKEN_H
#define _TOKEN_H

void tokeniseamp(char * text , char *dir , char * prevdir , char * homedir );
void tokenise_sc(int i , char * text ,int bg,  char * dir , char * prevdir,char * homedir);
void tokenise_space(int i,char * temp , char * text ,int bg , char * dir , char * prevdir,char * homedir);
#endif