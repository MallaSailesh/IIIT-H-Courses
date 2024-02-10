#ifndef SONG_H
#define SONG_H
typedef struct Song * Song;
struct Song {
    char * name;
    char * artist;
    float dur;
};

Song  makeSong(char * name , char * artist, int dur);
#endif