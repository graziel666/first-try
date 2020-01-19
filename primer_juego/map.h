#ifndef MAP_H
#define MAP_H
#include "globals.h"

#define worldHeight 7
#define worldWidth 15
#define tileSize 16

#define FLOOR 0
#define GROUND 1
#define BLANK 2

int mapX = 0;
int mapY = 45;

int Map[worldHeight][worldWidth] = {
  {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK },
  {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK },
  {FLOOR, FLOOR, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, FLOOR },
  {BLANK, BLANK, BLANK, FLOOR, BLANK, FLOOR, FLOOR, FLOOR, FLOOR, BLANK, BLANK, BLANK, FLOOR, FLOOR, FLOOR },
  {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, FLOOR, FLOOR, BLANK, BLANK, BLANK },
  {BLANK, BLANK, BLANK, FLOOR, FLOOR, FLOOR, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK },
  {FLOOR, FLOOR, FLOOR, GROUND, GROUND, GROUND, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR,},
};


void drawMap(){
 
  const int tilesWide = WIDTH/tileSize + 1;
  const int tilesTall = HEIGHT/tileSize + 1;

  for (char y = 0; y < worldHeight; y++) {
    for (char x = 0; x < worldWidth; x++){
      sprites.drawOverwrite(x * tileSize + mapX, y * tileSize - mapY, FloorTiles, Map[y][x]);
    }
  }
}




#endif
