#ifndef PLAYER_H
#define PLAYER_H
#include "globals.h"

byte frame = 0;
byte x = 0;
byte y = 16*2;
char dir = 'R'; //L,R
bool walking = false;

#define CharW 16
#define CharH 16
#define MaxX (WIDTH - CharW)
#define MaxY (HEIGHT - CharH)



void playerMove(){

    
  if (arduboy.pressed(RIGHT_BUTTON) && (x < MaxX)){
    walking = true;
    x++;
    if (arduboy.everyXFrames(8)) frame ++;
    if (frame > 4) frame = 1;
    dir = 'R';
  }

  
  if (arduboy.pressed(LEFT_BUTTON) && (x > 0)){
    walking = true;
    x--;
    if (arduboy.everyXFrames(8)) frame++;
    if (frame > 4) frame = 1;
    dir = 'L';
  }

  if (walking && arduboy.notPressed(RIGHT_BUTTON) && arduboy.notPressed(LEFT_BUTTON)) walking = false;
  if (!walking) frame = 0;

  

  if (dir == 'L'){
    sprites.drawPlusMask(x,MaxY,PjWalkingLeft,frame);
  }

  
  if (dir == 'R'){
    sprites.drawPlusMask(x,MaxY,PjWalkingRight,frame);
  }

  
  
}


#endif
