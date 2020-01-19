#ifndef PLAYER_H
#define PLAYER_H
#include "globals.h"
#include "map.h"

byte frame = 0;
byte x = 16;
byte y = 16*2;
char dir = 'R'; //L,R
bool walking = false;

#define CharW 16
#define CharH 16
#define MaxX (WIDTH - tileSize )
#define MaxY (HEIGHT - CharH*2+3)
#define MinX 16
int playerY = 35;


void Walking(){
  walking = true;
   
    if (arduboy.everyXFrames(8)) frame ++;
    if (frame > 4) frame = 1;
    
}


void playerMove(){

//moving player and map
    if (arduboy.pressed(RIGHT_BUTTON) && (x < MaxX)){
    Walking();
    x++;
    dir = 'R';
  }
  if (arduboy.pressed(RIGHT_BUTTON) && x == MaxX && mapX > -114){
    Walking();
    mapX--;
  }
  

  
  if (arduboy.pressed(LEFT_BUTTON) && (x > MinX)){
    Walking();
    x--;
    dir = 'L';
  }

  if (arduboy.pressed(LEFT_BUTTON)&& x == MinX && mapX < 0 && mapX >= -114) {
    Walking();
    mapX++;
    
    
  }

//jump
  if (arduboy.pressed(A_BUTTON)){
     playerY-=2;
    
  }

//animation reset
  if (walking && arduboy.notPressed(RIGHT_BUTTON) && arduboy.notPressed(LEFT_BUTTON)) walking = false;
  if (!walking) frame = 0;

  
//setting direction
  if (dir == 'L'){
    sprites.drawPlusMask(x ,playerY,PjWalkingLeft,frame);
  }

  
  if (dir == 'R'){
    sprites.drawPlusMask(x ,playerY,PjWalkingRight,frame);
  }

  
  
}




#endif
