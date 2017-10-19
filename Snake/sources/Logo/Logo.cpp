#include "Logo.h"

AnimatedLogo::AnimatedLogo()
{

}

void AnimatedLogo::InitLogo(COORD Position)
{
    /*template logo*/
    size_t Logo[LOGO_ROWS][LOGO_COLS] = {
        { 4, 3, 2, 0, 18, 19, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 51, 52, 53 },
        { 5, 0, 0, 0, 17, 0, 20, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 50, 0, 0 },
        { 6, 7, 8, 0, 16, 0, 0, 21, 0, 1, 0, 29, 30, 31, 32, 0, 40, 41, 0, 0, 0, 49, 1, 1 },
        { 0, 0, 9, 0, 15, 0, 0, 0, 22, 1, 0, 28, 0, 0, 33, 0, 39, 0, 42, 0, 0, 48, 0, 0 },
        { 1, 1, 10, 0, 14, 0, 0, 0, 0, 23, 0, 27, 0, 0, 34, 0, 38, 0, 0, 43, 0, 47, 1, 1 },
        { 1, 1, 11, 12, 13, 1, 1, 1, 1, 24, 25, 26, 1, 1, 35, 36, 37, 1, 1, 44, 45, 46, 1, 1 }
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
    item = std::make_pair(0, 2);
    path.push_back(item);
    while (path.size() != 52)
    {
        for (size_t i = 0; i < LOGO_ROWS; i++)
        {
            for (size_t j = 0; j < LOGO_COLS; j++)
            {
                if (_logo[i][j].GetValue() == (1 + _logo[path.back().first][path.back().second].GetValue()))
                {
                    item = std::make_pair(i, j);
                    path.push_back(item);
                }
            }
        }
    }

    while (TRUE)
    {
        for (size_t i = 0; i < path.size(); i++)
        {
            if (i < 8)
            {
                size_t j = 0;
                for (; j < i; j++)
                {
                    size_t x = path[i - j - 1].first;
                    size_t y = path[i - j - 1].second;
                    switch (j)
                    {
                    case 0: Block::PrintBlock(_logo[x][y], COLOR_FOOD); break;
                    case 1: Block::PrintBlock(_logo[x][y], COLOR_MAP); break;
                    case 2: Block::PrintBlock(_logo[x][y], COLOR_MAP); break;
                    default: Block::PrintBlock(_logo[x][y], COLOR_SNAKE);
                    }
                }
                size_t x = path[path.size() + j - 8].first;
                size_t y = path[path.size() + j - 8].second;
                Block::PrintBlock(_logo[x][y], COLOR_MAP);
            }
            else
            {
                size_t j = 0;
                for (; j < 8; j++)
                {
                    size_t x = path[i - j].first;
                    size_t y = path[i - j].second;
                    switch (j)
                    {
                    case 0: Block::PrintBlock(_logo[x][y], COLOR_FOOD); break;
                    case 1: Block::PrintBlock(_logo[x][y], COLOR_MAP); break;
                    case 2: Block::PrintBlock(_logo[x][y], COLOR_MAP); break;
                    default: Block::PrintBlock(_logo[x][y], COLOR_SNAKE);
                    }
                }
                size_t x = path[i - j].first;
                size_t y = path[i - j].second;
                Block::PrintBlock(_logo[x][y], COLOR_MAP);
            }
            Sleep(200);
        }
    }
}

