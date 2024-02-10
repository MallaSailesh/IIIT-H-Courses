#include "song.h"
#include<stdlib.h>

Song makeSong(char * name , char * artist, int dur)
{
    Song s;
    s = (Song)malloc(sizeof(struct Song));
    s->name = name ;
    s->artist = artist;
    s->dur = dur;
    return s;
}