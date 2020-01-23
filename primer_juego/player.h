#pragma once

#ifndef PLAYER_H
#define PLAYER_H
#include "globals.h"
#include "map.h"

bool isWalking  = false;


enum class HorizontalDirection : uint8_t {Left, Right};

uint8_t frame = 0;
uint8_t x = 16;
uint8_t y = 16*2;
HorizontalDirection playerDir = HorizontalDirection::Right; //Left,Right

constexpr uint8_t CharW = 16;
constexpr uint8_t  CharH = 16;
#define MaxX (WIDTH - tileSize )
#define MaxY (HEIGHT - CharH*2+3)
#define MinX 16

//jump
uint8_t groundLevel = 35;
uint8_t playerY = 35;
int playerVelocityY;
uint8_t gravity = 1;




void WalkingAnim(){

  isWalking = true;
   
    if (arduboy.everyXFrames(8)) frame ++;
    if (frame > 4) frame = 1;
    
}


void playerMove(){

//moving player and map
    if (arduboy.pressed(RIGHT_BUTTON)){
  //player movement
    if (x < MaxX){
      WalkingAnim();
      x++;
      playerDir = HorizontalDirection::Right;
    }
  //map movement
    if (x == MaxX && mapX < mapMaxY){
      WalkingAnim();
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
      WalkingAnim();
    x--;
    playerDir = HorizontalDirection::Left;
    }

  //map movement
  if (x == MinX && mapX > 0 && mapX <= mapMaxY){
    WalkingAnim();
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
  if (isWalking  && arduboy.notPressed(RIGHT_BUTTON) && arduboy.notPressed(LEFT_BUTTON)) isWalking  = false;
  if (!isWalking ) frame = 0;

  
//setting direction
  if (playerDir == HorizontalDirection::Left){
    sprites.drawPlusMask(x ,playerY,PjWalkingLeft,frame);
  }

  
  if (playerDir == HorizontalDirection::Right){
    sprites.drawPlusMask(x ,playerY,PjWalkingRight,frame);
  }

  
  
}




#endif
