#ifndef PLAYER_H
#define PLAYER_H
#include "globals.h"
#include "map.h"

uint8_t frame = 0;
uint8_t x = 16;
uint8_t y = 16*2;
char dir = 'R'; //L,R
bool walking = false;

#define CharW 16
#define CharH 16
#define MaxX (WIDTH - tileSize )
#define MaxY (HEIGHT - CharH*2+3)
#define MinX 16

//jump
uint8_t groundLevel = 35;
uint8_t playerY = 35;
int playerVelocityY;
uint8_t gravity = 1;




void Walking(){
  walking = true;
   
    if (arduboy.everyXFrames(8)) frame ++;
    if (frame > 4) frame = 1;
    
}


void playerMove(){

//moving player and map
    if (arduboy.pressed(RIGHT_BUTTON)){
  //player movement
    if (x < MaxX){
      Walking();
      x++;
      dir = 'R';
    }
  //map movement
    if (x == MaxX && mapX < mapMaxY){
      Walking();
      mapX++;
    }
  }
  /*if (arduboy.pressed(RIGHT_BUTTON) && x == MaxX && mapX < 114){
    Walking();
    mapX++;
  }*/
  

  
  if (arduboy.pressed(LEFT_BUTTON)){
  //player movement
    if (x > MinX){
      Walking();
    x--;
    dir = 'L';
    }

  //map movement
  if (x == MinX && mapX > 0 && mapX <= mapMaxY){
    Walking();
    mapX--;
  }
  }

  /*if (arduboy.pressed(LEFT_BUTTON)&& x == MinX && mapX > 0 && mapX <= 114) {
    Walking();
    mapX--;*/
    
    
  

//jump
  if (arduboy.pressed(A_BUTTON)){
     if (playerY == groundLevel){
      playerVelocityY = -7;
     }

    
  }

//moving player up or down
  if (playerVelocityY < 0) playerY += playerVelocityY;

  if (playerVelocityY < 0) playerVelocityY += gravity;

  if (playerY < groundLevel) playerY += gravity%playerVelocityY;

//stop
  if (playerY > groundLevel) playerY = groundLevel;


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
