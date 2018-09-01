#include "Logo.h"

Animation::Animation() :
    m_stop_animation(FALSE)
{
    initLogoMatrix();
}

void Animation::setAnimationMapColor(WORD color) {
    for (uint8_t i = 0; i < LOGO_ROWS - 1; i++) {
        for (uint8_t j = 0; j < LOGO_COLS; j++) {
            if (m_logo_path[i][j] > 0) {
                m_logo[i][j].setColor(color);
            }
        }
    }
}
void Animation::setAnimationWallColor(WORD color) {
    for (uint8_t i = LOGO_ROWS - 1; i < LOGO_ROWS; i++) {
        for (uint8_t j = 0; j < LOGO_COLS; j++) {
            m_logo[i][j].setColor(color);
        }
    }
}
void Animation::setAnimationSnakeColor(WORD color) {
    for (uint8_t i = LOGOPART_LENGHT - SNAKE_LENGTH; i < LOGOPART_LENGHT; i++) {
        m_logo_part[i].setColor(color);
    }
};

void Animation::setAnimationFoodColor(WORD color) { 
    m_logo_part[0].setColor(color); 
}

void Animation::initPath() {
    m_path[0] = std::make_pair(0, 2);
    /*add path to array*/
    for (uint8_t k = 1; k < 52; k++) {
        for (uint8_t i = 0; i < LOGO_ROWS; i++) {
            for (uint8_t j = 0; j < LOGO_COLS; j++) {
                if (m_logo[i][j].getValue() ==
                    (1 + m_logo[m_path[k - 1].first][m_path[k - 1].second].getValue())) {
                    m_path[k] = std::make_pair(i, j);
                }
            }
        }
    }
}

void Animation::initLogoMatrix() {
    /*template logo*/
    uint8_t logo_matrix[LOGO_ROWS][LOGO_COLS] = {
    { 4, 3,  2,  0, 18, 19,  0,  0, 0,  1,  0,  1,  1,  1,  1, 0,   1,  0,  0,  1,  0, 51, 52, 53 },
    { 5, 0,  0,  0, 17,  0, 20,  0, 0,  1,  0,  1,  0,  0,  1, 0,   1,  0,  1,  0,  0, 50,  0,  0 },
    { 6, 7,  8,  0, 16,  0,  0, 21, 0,  1,  0, 29, 30, 31, 32, 0,  40, 41,  0,  0,  0, 49,  1,  1 },
    { 0, 0,  9,  0, 15,  0,  0,  0, 22, 1,  0, 28,  0,  0, 33, 0,  39,  0, 42,  0,  0, 48,  0,  0 },
    { 1, 1, 10,  0, 14,  0,  0,  0, 0, 23,  0, 27,  0,  0, 34, 0,  38,  0,  0, 43,  0, 47,  1,  1 },
    { 1, 1, 11, 12, 13,  1,  1,  1, 1, 24, 25, 26,  1,  1, 35, 36, 37,  1,  1, 44, 45, 46,  1,  1 }
    };

    for (uint8_t x = 0; x < LOGO_ROWS; x++) {
        for (uint8_t y = 0; y < LOGO_COLS; y++) {
            m_logo_path[x][y] = logo_matrix[x][y];
        }
    }
}

void Animation::initLogo(COORD Position) {
    /*set logo properties*/
    for (uint8_t i = 0; i < LOGO_ROWS; i++) {
        for (uint8_t j = 0; j < LOGO_COLS; j++) {
            if (m_logo_path[i][j] > 0) {
                COORD left =  { SHORT(Position.X + i), SHORT(Position.Y + j * 2) };
                COORD right = { SHORT(Position.X + i), SHORT(Position.Y + j * 2 + 1) };
                COORD pos =   { (SHORT)i, (SHORT)j };
                m_logo[i][j].setFormat(FORMAT);
                m_logo[i][j].setValue(m_logo_path[i][j]);   // used for path
                m_logo[i][j].setCoord(left, right);
                m_logo[i][j].setPosition(pos);
                m_logo[i][j].setColor(i == 5 ? COLOR_WALL : COLOR_MAP);
            }
        }
    }

    /*set logoPart proprieties*/
    for (size_t i = 0; i < LOGOPART_LENGHT; i++) {
        switch (i) {
        case 0:  m_logo_part[i].setColor(COLOR_FOOD);  m_logo_part[i].setValue(IS_FOOD); break;
        case 1:  m_logo_part[i].setColor(COLOR_MAP);   m_logo_part[i].setValue(IS_MAP);  break;
        case 2:  m_logo_part[i].setColor(COLOR_MAP);   m_logo_part[i].setValue(IS_MAP);  break;
        default: m_logo_part[i].setColor(COLOR_SNAKE); m_logo_part[i].setValue(IS_SNAKE);
        }
        m_logo_part[i].setFormat(FORMAT);
    }

    /*set the m_path variable*/
    static bool bVal = FALSE;
    if (!bVal) {
        initPath();
        bVal = TRUE;
    }
}

void Animation::printBackground() {
    for (uint8_t i = 0; i < LOGO_ROWS; i++) {
        for (uint8_t j = 0; j < LOGO_COLS; j++) {
            if (m_logo[i][j].getValue())
                printer.printBlock(m_logo[i][j]);
        }
    }
}

void Animation::stopAnimation() { m_stop_animation = TRUE; }

void Animation::startAnimation(COORD & position) {
    bool bVal = FALSE;

    initLogo(position);
    printBackground();

    m_stop_animation = FALSE;

    while (!m_stop_animation) {
        for (uint8_t i = 0; i < 52; i++) {
            if (m_stop_animation) {
                break;
            }

            if (i < LOGOPART_LENGHT) {
                for (uint8_t j = 0; j <= i; j++) {
                    /*print first LOGOPART_LENGHT blocks*/
                    uint8_t x = m_path[i - j].first;
                    uint8_t y = m_path[i - j].second;
                    m_logo_part[j].setCoord(m_logo[x][y].getLeft(), m_logo[x][y].getRight());
                    m_logo_part[j].setPosition(m_logo[x][y].getPosition());
                    printer.printBlock(m_logo_part[j]);
                }

                /*print last LOGOPART_LENGHT blocks*/
                if (bVal) {
                    uint8_t j = LOGOPART_LENGHT - 1;
                    for (; j > i; j--) {
                        uint8_t x = m_path[52 + i - j].first;
                        uint8_t y = m_path[52 + i - j].second;
                        m_logo_part[j].setCoord(m_logo[x][y].getLeft(), m_logo[x][y].getRight());
                        m_logo_part[j].setPosition(m_logo[x][y].getPosition());
                        printer.printBlock(m_logo_part[j]);
                    }
                    uint8_t x = m_path[52 + i - LOGOPART_LENGHT].first;
                    uint8_t y = m_path[52 + i - LOGOPART_LENGHT].second;
                    printer.printBlock(m_logo[x][y]);
                }
            }
            else /*print the left blocks*/ {
                bVal = TRUE;
                uint8_t j = 0;
                for (; j < LOGOPART_LENGHT; j++) {
                    uint8_t x = m_path[i - j].first;
                    uint8_t y = m_path[i - j].second;
                    m_logo_part[j].setCoord(m_logo[x][y].getLeft(), m_logo[x][y].getRight());
                    m_logo_part[j].setPosition(m_logo[x][y].getPosition());
                    m_logo_part[1].setColor(m_logo_part[1].getPosition().X == 5 ? COLOR_WALL : COLOR_MAP);
                    m_logo_part[2].setColor(m_logo_part[2].getPosition().X == 5 ? COLOR_WALL : COLOR_MAP);
                    printer.printBlock(m_logo_part[j]);
                }
                uint8_t x = m_path[i - j].first;
                uint8_t y = m_path[i - j].second;
                printer.printBlock(m_logo[x][y]);
            }
            Sleep(150);
        }
        if (m_stop_animation) {
            break;
        }
    }
}
