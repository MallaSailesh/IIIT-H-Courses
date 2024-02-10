#include "musicplayer.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

MusicPlayer * createMusicPlayer()
{
   MusicPlayer * mp;
   mp = (MusicPlayer *)malloc(sizeof(MusicPlayer));
   assert(mp!=NULL);
   mp -> Currentsong = NULL;
   mp -> head = NULL;
   return mp;
}
int addSongToQueue(MusicPlayer * mp,Song s)
{
    Node temp=mp->head,temp2=NULL;
    if(mp->head==NULL)
    {
        mp->head = (Node)malloc(sizeof(struct Node));
        assert(mp->head!=NULL);
        mp -> head -> s = s;
        mp -> head -> next = NULL;
        return 0;
    }
    while((temp->next)!=NULL)
    {
        temp = temp -> next;
    }  
    temp2 = (Node)malloc(sizeof(struct Node));
    assert(temp2!=NULL);
    temp -> next = temp2;
    temp2 -> s = s;
    temp2 -> next = NULL;
    return 0;
}
int removeSongFromQueue(MusicPlayer * mp , int index)
{
    if(mp->head==NULL)
    return 1;
    Node temp = mp->head,temp2=NULL;
    if(index>=0)
    {
        if(index==0)
        {
            mp->head = mp->head->next;
            free(temp);
            temp = NULL;
            return 0;
        }
        else
        {
            if(index == 1)
            {
                if(mp->head->next==NULL) return 1;
                temp = temp->next;
                mp -> head -> next = mp->head->next->next ; 
                free(temp);
                temp = NULL;
                return 0;
            }
            while(index>1)
            {
                temp = temp -> next ;
                index--;
            }
            if(temp == NULL||temp->next==NULL) return 1 ;
            else 
            {
                temp2 = temp -> next;
                temp -> next = temp -> next -> next;
                free(temp2);
                temp2 = NULL;
            }
            return 0;
        }
    }
    return 1;
}
int playSong(MusicPlayer * mp)
{
    if(mp->head == NULL)
    return 1;
    else
    {
       mp -> Currentsong = mp->head->s;
       removeSongFromQueue(mp,0);
       return 0;
    }
}
Song getCurrentSong(MusicPlayer * mp)
{
    if(mp->Currentsong ==NULL)
    return NULL;
    return mp->Currentsong;
}