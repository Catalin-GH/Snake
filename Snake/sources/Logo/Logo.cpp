#include "Logo.h"

AnimatedLogo::AnimatedLogo()
{
}

void AnimatedLogo::InitPath(void)
{
    std::pair<size_t, size_t> item;
    item = std::make_pair(0, 2);
    _path.push_back(item);

    /*add path to a vector*/
    while (_path.size() != 52)
    {
        for (size_t i = 0; i < LOGO_ROWS; i++)
        {
            for (size_t j = 0; j < LOGO_COLS; j++)
            {
                if (_logo[i][j].GetValue() == (1 + _logo[_path.back().first][_path.back().second].GetValue()))
                {
                    item = std::make_pair(i, j);
                    _path.push_back(item);
                }
            }
        }
    }
}

void AnimatedLogo::InitLogo(COORD Position)
{
    /*template logo*/
    size_t Logo[LOGO_ROWS][LOGO_COLS] = {
        { 4, 3,  2,  0, 18, 19,  0,  0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 51, 52, 53 },
        { 5, 0,  0,  0, 17,  0, 20,  0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 50, 0, 0 },
        { 6, 7,  8,  0, 16,  0,  0, 21, 0, 1, 0, 29, 30, 31, 32, 0, 40, 41, 0, 0, 0, 49, 1, 1 },
        { 0, 0,  9,  0, 15,  0,  0,  0, 22, 1, 0, 28, 0, 0, 33, 0, 39, 0, 42, 0, 0, 48, 0, 0 },
        { 1, 1, 10,  0, 14,  0,  0,  0, 0, 23, 0, 27, 0, 0, 34, 0, 38, 0, 0, 43, 0, 47, 1, 1 },
        { 1, 1, 11, 12, 13,  1,  1,  1, 1, 24, 25, 26, 1, 1, 35, 36, 37, 1, 1, 44, 45, 46, 1, 1 }
    };

    /*set logo properties*/
    for (size_t i = 0; i < LOGO_ROWS; i++)
    {
        for (size_t j = 0; j < LOGO_COLS; j++)
        {
            if (j == 5)
            {
                _logo[i][j].SetColor(COLOR_MAP);
            }
            else
            {
                _logo[i][j].SetColor(COLOR_WALL);
            }

            if (Logo[i][j] > 0)
            {
                COORD left = { Position.X + i, Position.Y + j * 2 };
                COORD right = { Position.X + i, Position.Y + j * 2 + 1 };
                COORD pos = { i, j };
                _logo[i][j].SetFormat(FORMAT);
                _logo[i][j].SetValue(Logo[i][j]);   // used for path
                _logo[i][j].SetCoord(left, right);
                _logo[i][j].SetPosition(pos);
            }
        }
    }

    /*set logoPart proprieties*/
    for (size_t i = 0; i < LOGOPART_LENGHT; i++)
    {
        switch (i)
        {
        case 0: _logoPart[i].SetValue(IS_FOOD); break;
        case 1: _logoPart[i].SetValue(IS_MAP); break;
        case 2: _logoPart[i].SetValue(IS_MAP); break;
        default: _logoPart[i].SetValue(IS_SNAKE);
        }
        _logoPart[i].SetFormat(FORMAT);
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
    InitPath();
    bool bVal = FALSE;
    while (!GetCondition())
    {
        for (size_t i = 0; i < _path.size(); i++)
        {
            if (i < LOGOPART_LENGHT)
            {
                for (size_t j = 0; j <= i; j++)
                {
                    switch (j)
                    {
                    case 0: _logoPart[j].SetColor(COLOR_FOOD); break;
                    case 1: _logoPart[j].SetColor(COLOR_MAP); break;
                    case 2: _logoPart[j].SetColor(COLOR_MAP); break;
                    default: _logoPart[j].SetColor(COLOR_SNAKE);
                    }

                    /*print first LOGOPART_LENGHT blocks-*/
                    size_t x = _path[i - j].first;
                    size_t y = _path[i - j].second;
                    _logoPart[j].SetCoord(_logo[x][y].GetLeft(), _logo[x][y].GetRight());
                    _logoPart[j].SetPosition(_logo[x][y].GetPosition());
                    Block::PrintBlock(_logoPart[j], _logoPart[j].GetColor());
                }

                /*print last LOGOPART_LENGHT blocks*/
                if (bVal)
                {
                    size_t j = LOGOPART_LENGHT - 1;
                    for (; j > i; j--)
                    {
                        switch (j)
                        {
                        case 0: _logoPart[j].SetColor(COLOR_FOOD); break;
                        case 1: _logoPart[j].SetColor(COLOR_MAP); break;
                        case 2: _logoPart[j].SetColor(COLOR_MAP); break;
                        default: _logoPart[j].SetColor(COLOR_SNAKE);
                        }

                        size_t x = _path[_path.size() + i - j].first;
                        size_t y = _path[_path.size() + i - j].second;
                        _logoPart[j].SetCoord(_logo[x][y].GetLeft(), _logo[x][y].GetRight());
                        _logoPart[j].SetPosition(_logo[x][y].GetPosition());
                        Block::PrintBlock(_logoPart[j], _logoPart[j].GetColor());
                    }
                    size_t x = _path[_path.size() + i - LOGOPART_LENGHT].first;
                    size_t y = _path[_path.size() + i - LOGOPART_LENGHT].second;
                    Block::PrintBlock(_logo[x][y], _logo[x][y].GetColor());
                }
            }
            else
            {
                bVal = TRUE;
                size_t j = 0;
                for (; j < LOGOPART_LENGHT; j++)
                {
                    switch (j)
                    {
                    case 0: _logoPart[j].SetColor(COLOR_FOOD); break;
                    case 1: _logoPart[j].SetColor(COLOR_MAP); break;
                    case 2: _logoPart[j].SetColor(COLOR_MAP); break;
                    default: _logoPart[j].SetColor(COLOR_SNAKE);
                    }

                    size_t x = _path[i - j].first;
                    size_t y = _path[i - j].second;
                    _logoPart[j].SetCoord(_logo[x][y].GetLeft(), _logo[x][y].GetRight());
                    _logoPart[j].SetPosition(_logo[x][y].GetPosition());
                    Block::PrintBlock(_logoPart[j], _logoPart[j].GetColor());
                }
                size_t x = _path[i - j].first;
                size_t y = _path[i - j].second;
                Block::PrintBlock(_logo[x][y], _logo[x][y].GetColor());
            }

            Sleep(200);
        }
    }
}
