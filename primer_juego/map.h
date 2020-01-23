#pragma once

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
uint8_t mapMaxY = 114;

int Map[worldHeight][worldWidth] = {
  {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK },
  {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK },
  {FLOOR, FLOOR, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, FLOOR },
  {BLANK, BLANK, BLANK, FLOOR, BLANK, FLOOR, FLOOR, FLOOR, FLOOR, BLANK, BLANK, BLANK, FLOOR, FLOOR, FLOOR },
  {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, FLOOR, FLOOR, BLANK, BLANK, BLANK },
  {BLANK, BLANK, BLANK, FLOOR, FLOOR, FLOOR, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK },
  {FLOOR, FLOOR, FLOOR, GROUND, GROUND, GROUND, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR,},
};


/*void drawMap(){
 
  const int tilesWide = WIDTH/tileSize + 1;
  const int tilesTall = HEIGHT/tileSize + 1;

  for (uint8_t  y = 0; y < worldHeight; y++) {
    for (uint8_t  x = 0; x < worldWidth; x++){
      sprites.drawOverwrite(x * tileSize + mapX, y * tileSize - mapY, FloorTiles, Map[y][x]);
    }
  }
}*/

void drawMap()
{
  constexpr uint8_t tileWidth = tileSize;
  constexpr uint8_t tileHeight = tileSize;

//Number of tiles that can be displayed on screen
  constexpr size_t screenTileWidth = ((WIDTH / tileWidth) + 1);
  constexpr size_t screenTileHeight = ((HEIGHT / tileHeight) + 1);

//Top left camera tile
  const int16_t mapTileY = (mapY / tileHeight);
  const int16_t mapTileX = (mapX / tileWidth);
  
  for(uint8_t y = 0; y < screenTileHeight; ++y){
//Tile Y coordinate
    const int16_t tileY = (mapTileY + y);

  //If the tile is out of bounds, continue to next Y
    if((tileY < 0) || (tileY >= worldHeight))continue;

    const int16_t mapRemainderY = (mapY % tileHeight);
    const int16_t drawY = ((y * tileHeight) - mapRemainderY);

    for(uint8_t x = 0; x < screenTileWidth; ++x){
  //Tile X coordinate
      const int16_t tileX = (mapTileX + x);

  //If the tile is out of bounds, continue to next X
      if((tileX < 0) || (tileX >= worldWidth)) continue;

      const int16_t mapRemainderX = (mapX % tileWidth); 
      const int16_t drawX = ((x * tileWidth) - mapRemainderX);

  //Draw tile
      Sprites::drawOverwrite(drawX, drawY, FloorTiles, Map[tileY][tileX]);
    }
  }
}




#endif
