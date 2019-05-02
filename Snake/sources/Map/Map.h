//#pragma once
//
//#include <cstdlib>
//#include <fstream>
//#include <time.h>
//#include <vector>
//
//#include "SquareBlock.h"
//#include "Printer.h"
//#include "Snake.h"
//#include "Types.h"
//
//extern ColorGame colorGame;
//
//class Map
//{
//private:
//    SquareBlock m_block[Length::map][Length::map];
//    COORD m_originPosition;
//public:
//    Map() {}
//    ~Map() {}
//
//    SquareBlock getBlock(size_t, size_t) const;
//    SquareBlock getCenterOfMap() const;
//
//    void build(COORD);
//    bool updateObject(const std::vector<SquareBlock> &);
//    void printGraphicObject(const std::vector<SquareBlock> &);
//    void deleteGraphicObject(const std::vector<SquareBlock> &);
//    void printGraphic();
//    COORD randomPosition();
//
//    friend bool operator==(const COORD &, const COORD &);
//};
//
//inline
//SquareBlock Map::getBlock(size_t i, size_t j) const {
//    return m_block[i][j];
//}

#ifndef __MAP_H__
#define __MAP_H__

#include "Playground.hpp"
#include "Types.h"
#include "Wall.hpp"

class Map
{
private:
    const Coordonates2D mPosition;
    const Wall mWall;
    Playground mPlayground;

public:
    Map(const Coordonates2D & position);
    ~Map();
};

#endif //__MAP_H__ 
