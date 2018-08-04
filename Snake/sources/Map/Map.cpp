#include "Map.h"

Block Map::getBlock(size_t i, size_t j) const {
    return m_block[i][j];
}

Block Map::getCenterBlock() const {
    uint8_t center = MAP_LENGTH / 2 - 1;

    return (m_block[center][center]);
}

void Map::build(COORD coord) {  // se initializeaza blocurile ce alcatuiesc harta
    m_originPosition = coord;

    for (size_t i = 0; i < MAP_LENGTH; i++) {
        for (size_t j = 0; j < MAP_LENGTH; j++) {
            COORD left = { (SHORT)i + m_originPosition.X, (SHORT)j * 2 + m_originPosition.Y };
            COORD right = { (SHORT)i + m_originPosition.X, (SHORT)j * 2 + 1 + m_originPosition.Y };
            COORD position = { (SHORT)i, (SHORT)j };
            (m_block[i][j]).SetCoord(left, right);
            (m_block[i][j]).SetFormat(FORMAT);
            (m_block[i][j]).SetPosition(position);
            if (i == 0 || j < 1 || i > MAP_LENGTH - 2 || j > MAP_LENGTH - 2) {
                (m_block[i][j]).SetValue(IS_WALL);
                (m_block[i][j]).SetColor(COLOR_WALL);
            } 
            else {
                (m_block[i][j]).SetValue(IS_MAP);
                (m_block[i][j]).SetColor(COLOR_MAP);
            }
        }
    }
}

bool Map::updateObject(const std::vector<Block> & Object) {
    bool bVal = TRUE;
    size_t X = Object[0].GetPosition().X;
    size_t Y = Object[0].GetPosition().Y;
    if((m_block[X][Y]).GetValue() == IS_WALL) {
        bVal = FALSE;
    }
    else if(Object.size() >= SNAKE_LENGTH) {
        for (size_t i = 0; i < Object.size(); i++) {
            size_t x = Object[i].GetPosition().X;
            size_t y = Object[i].GetPosition().Y;
            (m_block[x][y]).SetColor(COLOR_SNAKE);
            (m_block[x][y]).SetValue(IS_SNAKE);
        }
    }
    else {
        size_t x = Object[0].GetPosition().X;
        size_t y = Object[0].GetPosition().Y;
        (m_block[x][y]).SetColor(COLOR_FOOD);
        (m_block[x][y]).SetValue(IS_FOOD);
    }

    return bVal;
}

void Map::printGraphicObject(const std::vector<Block> & Object) {
    for (size_t i = 0; i < Object.size(); i++) {
        size_t x = Object[i].GetPosition().X;
        size_t y = Object[i].GetPosition().Y;
        Block::PrintBlock(m_block[x][y], (WORD)(m_block[x][y]).GetColor());
    }
}

void Map::deleteGraphicObject(const std::vector<Block> & Object) {
    for(size_t i = 0; i < Object.size(); i++) {
        size_t x = Object[i].GetPosition().X;
        size_t y = Object[i].GetPosition().Y;
        (m_block[x][y]).SetValue(IS_MAP);
        (m_block[x][y]).SetColor(COLOR_MAP);
    }
}

void Map::printGraphic(void) {
    for (size_t i = 0; i < MAP_LENGTH; i++) {
        for (size_t j = 0; j < MAP_LENGTH; j++) {
            Block::PrintBlock(m_block[i][j], (WORD)(m_block[i][j]).GetColor());
        }
        std::cout << std::endl;
    }
}

COORD Map::randomPosition(void) {
    size_t x;
    size_t y;
    srand ((unsigned)time(NULL));
    do {
        x = rand() % MAP_LENGTH;
        y = rand() % MAP_LENGTH;
    } while (!((m_block[x][y]).GetValue() == IS_MAP));

    return (m_block[x][y]).GetPosition();
}

void Map::seeInfos(void) {
    std::ofstream eout("M_Format.txt", std::ios_base::app);
    std::ofstream vout("M_Value.txt", std::ios_base::app);
    std::ofstream cdout("M_Coordinates.txt", std::ios_base::app);
    std::ofstream cout("M_Color.txt", std::ios_base::app);
    std::ofstream pout("M_Position.txt", std::ios_base::app);
    for (size_t i = 0; i < MAP_LENGTH; i++) {
        for (size_t j = 0; j < MAP_LENGTH; j++) {
            (m_block[i][j]).ShowColor(cout);
            (m_block[i][j]).ShowFormat(eout);
            (m_block[i][j]).ShowValue(vout);
            (m_block[i][j]).ShowLeft(cdout);
            (m_block[i][j]).ShowRight(cdout);
            (m_block[i][j]).ShowPosition(pout);
        }
        eout << std::endl;
        vout << std::endl;
        cdout << std::endl;
        cout << std::endl;
        pout << std::endl;
    }

    eout << std::endl << std::endl;
    vout << std::endl << std::endl;
    cdout << std::endl << std::endl;
    cout << std::endl << std::endl;
    pout << std::endl << std::endl;

    eout.close();
    vout.close();
    cdout.close();
    cout.close();
    pout.close();
}
