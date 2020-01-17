#ifndef PLAYER_H
#define PLAYER_H
#include "globals.h"
#include "bitmaps.h"

byte frame = 0;
byte x = 0;
byte y = 30;
char dir = 'R'; //L,R

#define CharW 16
#define CharH 16
#define MaxX (WIDTH - CharW)
#define MaxY (HEIGHT - CharH)



void playerMove(){

  
    
  if (arduboy.pressed(RIGHT_BUTTON) && (x < MaxX)){
    x++;
    frame = 0;
    if (arduboy.everyXFrames(12)){ frame ++;}
    if (frame > 2) frame = 0;
    dir = 'R';
  }
  
  if (arduboy.pressed(LEFT_BUTTON) && (x > 0)){
    x--;
    frame = 0;
    if (arduboy.everyXFrames(13)) frame++;
    if (frame > 2) frame = 0;
    dir = 'L';
  }

  if (arduboy.justReleased(LEFT_BUTTON)) frame = 0;

  if (arduboy.justReleased(RIGHT_BUTTON)) frame = 0;

  if (dir == 'L'){
    sprites.drawPlusMask(x,y,PjWalkingLeft,frame);
  }

  
  if (dir == 'R'){
    sprites.drawPlusMask(x,y,PjWalkingRight,frame);
  }

  
  
}


#endif
