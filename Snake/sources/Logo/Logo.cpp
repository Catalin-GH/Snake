#include "Logo.h"

void AnimatedLogo::InitialSetup()
{
    AllocateMemoryLogoMatrix();
    InitLogoMatrix();
}

void AnimatedLogo::AllocateMemoryLogoMatrix()
{
    /*allocate memory for _logo_matrix*/
    _logo_matrix = new size_t *[LOGO_ROWS];
    for (size_t i = 0; i < LOGO_ROWS; i++)
    {
        _logo_matrix[i] = new size_t[LOGO_COLS];
    }
}

void AnimatedLogo::ReleaseMemoryLogoMatrix()
{
    //release resources from memory for logo background
    for (size_t i = 0; i < LOGO_ROWS; i++)
    {
        delete[] _logo_matrix[i];
    }
    delete _logo_matrix;
}

void AnimatedLogo::AllocateMemory(void)
{
    /*allocate memory for logo (snake and food)*/
    _logo_part = new Block[LOGOPART_LENGHT];

    /*allocate memory for logo (matrix)*/
    _logo = new Block *[LOGO_ROWS];
    for (size_t i = 0; i < LOGO_ROWS; i++)
    {
        _logo[i] = new Block[LOGO_COLS];
    }
}

void AnimatedLogo::ReleaseMemory(void)
{
    //release memory
    delete _logo_part;
    for (size_t i = 0; i < LOGO_ROWS; i++)
    {
        delete[] _logo[i];
    }
    delete[] _logo;
}

void AnimatedLogo::InitPath(void)
{
    _path[0] = std::make_pair(0, 2);
    /*add path to array*/
    for (size_t k = 1; k < 52; k++)
    {
        for (size_t i = 0; i < LOGO_ROWS; i++)
        {
            for (size_t j = 0; j < LOGO_COLS; j++)
            {
                if (_logo[i][j].GetValue() == (1 + _logo[_path[k - 1].first][_path[k - 1].second].GetValue()))
                {
                    _path[k] = std::make_pair(i, j);
                }
            }
        }
    }
}

void AnimatedLogo::InitLogoMatrix()
{
    /*template logo*/
    size_t logoMatrix[LOGO_ROWS][LOGO_COLS] = {
    { 4, 3,  2,  0, 18, 19,  0,  0, 0,  1,  0,  1,  1,  1,  1, 0,   1,  0,  0,  1,  0, 51, 52, 53 },
    { 5, 0,  0,  0, 17,  0, 20,  0, 0,  1,  0,  1,  0,  0,  1, 0,   1,  0,  1,  0,  0, 50,  0,  0 },
    { 6, 7,  8,  0, 16,  0,  0, 21, 0,  1,  0, 29, 30, 31, 32, 0,  40, 41,  0,  0,  0, 49,  1,  1 },
    { 0, 0,  9,  0, 15,  0,  0,  0, 22, 1,  0, 28,  0,  0, 33, 0,  39,  0, 42,  0,  0, 48,  0,  0 },
    { 1, 1, 10,  0, 14,  0,  0,  0, 0, 23,  0, 27,  0,  0, 34, 0,  38,  0,  0, 43,  0, 47,  1,  1 },
    { 1, 1, 11, 12, 13,  1,  1,  1, 1, 24, 25, 26,  1,  1, 35, 36, 37,  1,  1, 44, 45, 46,  1,  1 }
    };

    for (uint8_t x = 0; x < LOGO_ROWS; x++)
        for (uint8_t y = 0; y < LOGO_COLS; y++)
            _logo_matrix[x][y] = logoMatrix[x][y];
}

void AnimatedLogo::InitLogo(COORD Position)
{
    /*set logo properties*/
    for (size_t i = 0; i < LOGO_ROWS; i++)
    {
        for (size_t j = 0; j < LOGO_COLS; j++)
        {
            if (_logo_matrix[i][j] > 0)
            {
                COORD left =  { SHORT(Position.X + i), SHORT(Position.Y + j * 2) };
                COORD right = { SHORT(Position.X + i), SHORT(Position.Y + j * 2 + 1) };
                COORD pos =   { (SHORT)i, (SHORT)j };
                _logo[i][j].SetFormat(FORMAT);
                _logo[i][j].SetValue(_logo_matrix[i][j]);   // used for path
                _logo[i][j].SetCoord(left, right);
                _logo[i][j].SetPosition(pos);
                _logo[i][j].SetColor(i == 5 ? COLOR_WALL : COLOR_MAP);
            }
        }
    }

    /*set logoPart proprieties*/
    for (size_t i = 0; i < LOGOPART_LENGHT; i++)
    {
        switch (i)
        {
        case 0:  _logo_part[i].SetColor(COLOR_FOOD);  _logo_part[i].SetValue(IS_FOOD); break;
        case 1:  _logo_part[i].SetColor(COLOR_MAP);   _logo_part[i].SetValue(IS_MAP);  break;
        case 2:  _logo_part[i].SetColor(COLOR_MAP);   _logo_part[i].SetValue(IS_MAP);  break;
        default: _logo_part[i].SetColor(COLOR_SNAKE); _logo_part[i].SetValue(IS_SNAKE);
        }
        _logo_part[i].SetFormat(FORMAT);
    }

    /*set the _path variable*/
    static bool bVal = FALSE;
    if (!bVal)
    {
        InitPath();
        bVal = TRUE;
    }
}

void AnimatedLogo::printLogo(void)
{
    for (size_t i = 0; i < LOGO_ROWS; i++)
    {
        for (size_t j = 0; j < LOGO_COLS; j++)
        {
            if (_logo[i][j].GetValue())
                Block::PrintBlock(_logo[i][j], (WORD)_logo[i][j].GetColor());
        }
    }
}

bool AnimatedLogo::_stop_animation = FALSE;
bool AnimatedLogo::_animation_stopped = FALSE;

void AnimatedLogo::Animation(void)
{
    bool bVal = FALSE;
    while (!_stop_animation)
    {
        for (size_t i = 0; i < 52; i++)
        {
            if (_stop_animation)
            {
                break;
                _animation_stopped = TRUE;
            }
            if (i < LOGOPART_LENGHT)
            {
                for (size_t j = 0; j <= i; j++)
                {
                    /*print first LOGOPART_LENGHT blocks*/
                    size_t x = _path[i - j].first;
                    size_t y = _path[i - j].second;
                    _logo_part[j].SetCoord(_logo[x][y].GetLeft(), _logo[x][y].GetRight());
                    _logo_part[j].SetPosition(_logo[x][y].GetPosition());
                    Block::PrintBlock(_logo_part[j], (WORD)_logo_part[j].GetColor());
                }

                /*print last LOGOPART_LENGHT blocks*/
                if (bVal)
                {
                    size_t j = LOGOPART_LENGHT - 1;
                    for (; j > i; j--)
                    {
                        size_t x = _path[52 + i - j].first;
                        size_t y = _path[52 + i - j].second;
                        _logo_part[j].SetCoord(_logo[x][y].GetLeft(), _logo[x][y].GetRight());
                        _logo_part[j].SetPosition(_logo[x][y].GetPosition());
                        Block::PrintBlock(_logo_part[j], (j == 1 || j == 2) ? (WORD)_logo[x][y].GetColor() : (WORD)_logo_part[j].GetColor());
                    }
                    size_t x = _path[52 + i - LOGOPART_LENGHT].first;
                    size_t y = _path[52 + i - LOGOPART_LENGHT].second;
                    Block::PrintBlock(_logo[x][y], (WORD)_logo[x][y].GetColor());
                }
            }
            else /*print the left blocks*/
            {
                bVal = TRUE;
                size_t j = 0;
                for (; j < LOGOPART_LENGHT; j++)
                {
                    size_t x = _path[i - j].first;
                    size_t y = _path[i - j].second;
                    _logo_part[j].SetCoord(_logo[x][y].GetLeft(), _logo[x][y].GetRight());
                    _logo_part[j].SetPosition(_logo[x][y].GetPosition());
                    Block::PrintBlock(_logo_part[j], (j == 1 || j == 2) ? (WORD)_logo[x][y].GetColor() : (WORD)_logo_part[j].GetColor());
                }
                size_t x = _path[i - j].first;
                size_t y = _path[i - j].second;
                Block::PrintBlock(_logo[x][y], (WORD)_logo[x][y].GetColor());
            }
            Sleep(150);
        }
        if (_stop_animation)
        {
            break;
            _animation_stopped = TRUE;
        }
    }
}
