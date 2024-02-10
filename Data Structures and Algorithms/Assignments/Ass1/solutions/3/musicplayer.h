#ifndef MUSIC_H
#define MUSIC_H
#include "song.h"
typedef struct MusicPlayer MusicPlayer;
typedef struct Node * Node;
struct Node 
{
    Song s ;
    Node next;
};
struct MusicPlayer
{
    Song Currentsong;
    Node head ;
};
MusicPlayer * createMusicPlayer();
int addSongToQueue(MusicPlayer * mp,Song s);
int removeSongFromQueue(MusicPlayer * mp , int index);
int playSong(MusicPlayer * mp);
Song getCurrentSong(MusicPlayer * mp);
#endif