/*
Tarragona Diego
primer juego
16/01/2020
*/

#include "globals.h"
#include "player.h"
#include "enemy.h"
#include "main.h"
#include "map.h"



void setup() {
  arduboy.begin();
  arduboy.setFrameRate(45);
  arduboy.display();
  //arduboy.initRandomSeed();
  arduboy.clear();
}

void loop() {
  if (!(arduboy.nextFrame())){
    return;
  }
  arduboy.clear();
  arduboy.setCursor(x,y);

  drawMap();
  playerMove();

    arduboy.setCursor(0,0);
    arduboy.print(mapX);
    arduboy.setCursor(10,10);
    arduboy.print(playerY);

  arduboy.display();
    
}
