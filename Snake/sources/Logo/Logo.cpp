#include "Logo.h"

AnimatedLogo::AnimatedLogo()
{

}

void AnimatedLogo::InitLogo(COORD Position)
{
    size_t Logo[LOGO_ROWS][LOGO_COLS] = {
        { 2, 2, 2, 0, 2, 2, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 2, 2, 2 },
        { 2, 0, 0, 0, 2, 0, 2, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 2, 0, 0 },
        { 2, 2, 2, 0, 2, 0, 0, 2, 0, 1, 0, 2, 2, 2, 2, 0, 2, 2, 0, 0, 0, 2, 1, 1 },
        { 0, 0, 2, 0, 2, 0, 0, 0, 2, 1, 0, 2, 0, 0, 2, 0, 2, 0, 2, 0, 0, 2, 0, 0 },
        { 1, 1, 2, 0, 2, 0, 0, 0, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0, 0, 2, 0, 2, 1, 1 },
        { 1, 1, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 1, 1, 2, 2, 2, 1, 1, 2, 2, 2, 1, 1 }
    };

    for (size_t i = 0; i < LOGO_ROWS; i++)
    {
        for (size_t j = 0; j < LOGO_COLS; j++)
        {
            if (Logo[i][j] > 0)
            {
                COORD left = { Position.X + i, Position.Y + j * 2 };
                COORD right = { Position.X + i, Position.Y + j * 2 + 1 };
                COORD pos = { i, j };
                _logo[i][j].SetColor(COLOR_LOGO);
                _logo[i][j].SetFormat(FORMAT);
                _logo[i][j].SetValue(Logo[i][j]);   // used for path
                _logo[i][j].SetCoord(left, right);
                _logo[i][j].SetPosition(pos);
            }
        }
    }
}

void AnimatedLogo::printLogo(void)
{
    for (size_t i = 0; i < LOGO_ROWS; i++)
    {
        for (size_t j = 0; j < LOGO_COLS; j++)
        {
            Block::PrintBlock(_logo[i][j], COLOR_LOGO);
        }
    }
}

void AnimatedLogo::Animation(void)
{
    std::vector<std::pair<size_t, size_t>> path;
    std::pair<size_t, size_t> item;
    for (size_t i = 0; i < LOGO_ROWS; i++)
    {
        for (size_t j = 0; j < LOGO_COLS; j++)
        {
            if (_logo[i][j].GetValue() == 2)
            {
                item = std::make_pair(i, j);
                path.push_back(item);
            }
        }
    }
    Snake snake;
    Food food;
    while (TRUE)
    {
        for (size_t i = 0; i < path.size(); i++)
        {
            size_t x = path[i].first;
            size_t y = path[i].second;
            Block::PrintBlock(_logo[x][y], COLOR_FOOD);
            if (i > 1)
            {

            }
            Sleep(500);
            Block::PrintBlock(_logo[x][y], COLOR_LOGO);
        }
    }
}

