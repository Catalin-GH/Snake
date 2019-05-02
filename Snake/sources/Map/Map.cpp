#include "Map.h"

extern ColorGame colorGame;

Map::Map(const Coordonates2D & position)
    : mPosition(position)
    , mWall(position, colorGame.wall)
    , mPlayground(Coordonates2D(position.x + 1, position.y + 1), colorGame.playground)
{
}

Map::~Map()
{
}

//
//SquareBlock Map::getCenterOfMap() const {
//    uint8_t center = Length::map / 2 - 1;
//
//    return m_block[center][center];
//}
//
//void Map::build(COORD coord) {
//    m_originPosition = coord;
//
//    for (SHORT row = 0; row < Length::map; row++) {
//        for (SHORT col = 0; col < Length::map; col++) {
//            COORD left = { row + m_originPosition.X, col * 2 + m_originPosition.Y };
//            COORD right = { row + m_originPosition.X, col * 2 + 1 + m_originPosition.Y };
//            COORD position = { row, col };
//            m_block[row][col].setCoord(left, right);
//            m_block[row][col].setFormat(BlockType::format);
//            m_block[row][col].setPosition(position);
//
//            if (row == 0 || col < 1 || row > Length::map - 2 || col > Length::map - 2) {
//                m_block[row][col].setValue(Category::wall);
//                m_block[row][col].setColor(colorGame.wall);
//            } 
//            else {
//                m_block[row][col].setValue(Category::map);
//                m_block[row][col].setColor(colorGame.map);
//            }
//        }
//    }
//}
//
//bool Map::updateObject(const std::vector<SquareBlock> & object) {
//    bool bVal = TRUE;
//    size_t X = object[0].getPosition().X;
//    size_t Y = object[0].getPosition().Y;
//    if(m_block[X][Y].getValue() == Category::wall) {
//        bVal = FALSE;
//    }
//    else if(object.size() >= Length::snake) {
//        for (size_t i = 0; i < object.size(); i++) {
//            size_t x = object[i].getPosition().X;
//            size_t y = object[i].getPosition().Y;
//            m_block[x][y].setColor(colorGame.snake);
//            m_block[x][y].setValue(Category::snake);
//        }
//    }
//    else {
//        size_t x = object[0].getPosition().X;
//        size_t y = object[0].getPosition().Y;
//        m_block[x][y].setColor(colorGame.food);
//        m_block[x][y].setValue(Category::food);
//    }
//
//    return bVal;
//}
//
//void Map::printGraphicObject(const std::vector<SquareBlock> & Object) {
//    for (size_t i = 0; i < Object.size(); i++) {
//        size_t x = Object[i].getPosition().X;
//        size_t y = Object[i].getPosition().Y;
//        Printer::printBlock(m_block[x][y]);
//    }
//}
//
//void Map::deleteGraphicObject(const std::vector<SquareBlock> & Object) {
//    for(size_t i = 0; i < Object.size(); i++) {
//        size_t x = Object[i].getPosition().X;
//        size_t y = Object[i].getPosition().Y;
//        m_block[x][y].setValue(Category::map);
//        m_block[x][y].setColor(colorGame.map);
//    }
//}
//
//void Map::printGraphic() {
//    for (size_t i = 0; i < Length::map; i++) {
//        for (size_t j = 0; j < Length::map; j++) {
//            Printer::printBlock(m_block[i][j]);
//        }
//        Printer::endLine();
//    }
//}
//
//COORD Map::randomPosition() {
//    size_t x;
//    size_t y;
//    srand ((unsigned)time(NULL));
//    do {
//        x = rand() % Length::map;
//        y = rand() % Length::map;
//    } while (!((m_block[x][y]).getValue() == Category::map));
//
//    return m_block[x][y].getPosition();
//}
