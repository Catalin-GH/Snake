#pragma once

#include "Console_Functions.h"
#include "Snake.h"
#include "Functions.h"
#include <fstream>
#include "Block.h"
#include <cstdlib>
#include <time.h>

class Map
{
private:
    Block ** _block;
    size_t _rows;
    size_t _cols;
    COORD _originPosition;
public:
    Map(size_t, COORD);
    ~Map();

    size_t GetRows() const {return _rows;}
    size_t GetCols() const {return _cols;}
    Block GetBlock(size_t, size_t) const;
    Block GetCenterBlock() const;

    void Build(void);       // se initializeaza harta
    bool UpdateObject(const std::vector<Block> &);      // se introduce obiectul pe harta
    void GraphicObject(const std::vector<Block> &);        //se afiseaza obiectul pe harta
    void DeleteObject(const std::vector<Block> &);      // se sterge obiectul
    void Graphic(void);     //se afiseaza harta
    COORD RandomPosition(void);

    void SeeInfos(void);        //informatii despre harta

    inline COORD operator=(COORD NewPosition)
    {
        COORD Position;
        Position.X = NewPosition.X;
        Position.Y = NewPosition.Y;
        return Position;
    }

    friend bool operator==(const COORD &, const COORD &);
};
