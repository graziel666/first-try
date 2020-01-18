#ifndef MAP_H
#define MAP_H
#include "globals.h"

#define worldHeight 8
#define worldWidth 15
#define tileSize 16

#define FLOOR 0
#define GROUND 1
#define BLANK 3

int mapX = 0;
int mapY = 0;

int Map[worldHeight][worldWidth] = {
  {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK },
  {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK },
  {FLOOR, FLOOR, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, FLOOR },
  {BLANK, BLANK, BLANK, FLOOR, BLANK, FLOOR, FLOOR, FLOOR, FLOOR, BLANK, BLANK, BLANK, FLOOR, FLOOR, FLOOR },
  {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, FLOOR, FLOOR, BLANK, BLANK, BLANK },
  {BLANK, BLANK, BLANK, FLOOR, FLOOR, FLOOR, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK },
  {FLOOR, FLOOR, FLOOR, BLANK, BLANK, BLANK, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR,},
  {GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND},
};


void drawMap(){
  const int tilesWide = WIDTH/tileSize + 1;
  const int tilesTall = HEIGHT/tileSize + 1;

  for (char y = 0; y < 8; y++) {
    for (char x = 0; x < 15; x++){
      sprites.drawOverwrite(x*tileSize, y*tileSize,FloorTiles,Map[y][x]);
    }
  }
}




#endif
