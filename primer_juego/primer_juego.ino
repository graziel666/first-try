/*
Tarragona Diego
primer juego
16/01/2020
*/

#include "globals.h"
#include "player.h"
#include "enemy.h"
#include "main.h"



void setup() {
  arduboy.begin();
  arduboy.setFrameRate(35);
  arduboy.display();
  //arduboy.initRandomSeed();
  arduboy.clear();
}

void loop() {
  if (!(arduboy.nextFrame())){
    return;
  }
  
  arduboy.pollButtons();

  
  arduboy.clear();
  arduboy.setCursor(x,y);
  
  playerMove();

  arduboy.display();
    
}
