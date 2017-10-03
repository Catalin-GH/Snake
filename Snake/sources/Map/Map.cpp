#include "Map.h"

Map::Map(size_t length, COORD OriginPosition)
{
    _originPosition = OriginPosition;
    _rows = length;
    _cols = length;
    _block = new Block *[_rows];
    for (size_t i = 0; i < _rows; i++)
    {
        _block[i] = new Block[_cols];
    }
}

Map::~Map()
{
    for (size_t i = 0; i < _rows; i++)
    {
        delete[] _block[i];
    }
    delete[] _block;
}

Block Map::GetBlock(size_t i, size_t j) const
{
    return _block[i][j];
}

Block Map::GetCenterBlock() const
{
    return (_block[_rows / 2 - 1][_cols / 2 - 1]);
}

void Map::Build(void)
{
    for (size_t i = 0; i < _rows; i++)
    {
        for (size_t j = 0; j < _cols; j++)
        {
            COORD left = { (SHORT)i + _originPosition.X, (SHORT)j * 2 + _originPosition.Y };
            COORD right = { (SHORT)i + _originPosition.X, (SHORT)j * 2 + 1 + _originPosition.Y };
            COORD position = { (SHORT)i, (SHORT)j };
            (_block[i][j]).SetCoord(left, right);
            (_block[i][j]).SetFormat(FORMAT);
            (_block[i][j]).SetPosition(position);
            if (i == 0 || j < 1 || i > _rows - 2 || j > _cols - 2)
            {
                (_block[i][j]).SetValue(IS_WALL);
                (_block[i][j]).SetColor(COLOR_WALL);
            }
            else
            {
                (_block[i][j]).SetValue(IS_MAP);
                (_block[i][j]).SetColor(COLOR_MAP);
            }
        }
    }
}

bool Map::UpdateObject(const std::vector<Block> & Object)
{
    bool bVal = TRUE;
    size_t X = Object[0].GetPosition().X;
    size_t Y = Object[0].GetPosition().Y;
    if((_block[X][Y]).GetValue() == IS_WALL)
    {
        bVal = FALSE;
    }
    else if(Object.size() >= SNAKE_LENGTH)
    {
        for (size_t i = 0; i < Object.size(); i++)
        {
            size_t x = Object[i].GetPosition().X;
            size_t y = Object[i].GetPosition().Y;
            (_block[x][y]).SetColor(COLOR_SNAKE);
            (_block[x][y]).SetValue(IS_SNAKE);
        }
    }
    else
    {
        size_t x = Object[0].GetPosition().X;
        size_t y = Object[0].GetPosition().Y;
        (_block[x][y]).SetColor(COLOR_FOOD);
        (_block[x][y]).SetValue(IS_FOOD);
    }

    return bVal;
}

void Map::GraphicObject(const std::vector<Block> & Object)
{
    for (size_t i = 0; i < Object.size(); i++)
    {
        size_t x = Object[i].GetPosition().X;
        size_t y = Object[i].GetPosition().Y;
        size_t lx = (_block[x][y]).GetLeft().X;
        size_t ly = (_block[x][y]).GetLeft().Y;
        size_t rx = (_block[x][y]).GetRight().X;
        size_t ry = (_block[x][y]).GetRight().Y;
        gotoxy(ly, lx);             //(col, row)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)(_block[x][y]).GetColor());
        std::cout << (uint8_t)GetBlock(x, y).GetFormat();
        gotoxy(ry, rx);             //(col, row)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)(_block[x][y]).GetColor());
        std::cout << (uint8_t)GetBlock(x, y).GetFormat();
    }
}

void Map::DeleteObject(const std::vector<Block> & Object)
{
    for(size_t i = 0; i < Object.size(); i++)
    {
        size_t x = Object[i].GetPosition().X;
        size_t y = Object[i].GetPosition().Y;
        (_block[x][y]).SetValue(IS_MAP);
        (_block[x][y]).SetColor(COLOR_MAP);
    }
}

void Map::Graphic(void)
{
    for (size_t i = 0; i < _rows; i++)
    {
        for (size_t j = 0; j < _cols; j++)
        {
            size_t lx = (_block[i][j]).GetLeft().X;
            size_t ly = (_block[i][j]).GetLeft().Y;
            size_t rx = (_block[i][j]).GetRight().X;
            size_t ry = (_block[i][j]).GetRight().Y;
            gotoxy(ly, lx);             //(col, row)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)(_block[i][j]).GetColor());
            std::cout << (uint8_t)GetBlock(i, j).GetFormat();
            gotoxy(ry, rx);             //(col, row)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)(_block[i][j]).GetColor());
            std::cout << (uint8_t)GetBlock(i, j).GetFormat();
        }
        std::cout << std::endl;
    }
}

COORD Map::RandomPosition(void)
{
    size_t x;
    size_t y;
    srand ((unsigned)time(NULL));
    do 
    {
        x = rand() % _rows;
        y = rand() % _rows;
    } while (!((_block[x][y]).GetValue() == IS_MAP));

    return (_block[x][y]).GetPosition();
}

void Map::SeeInfos(void)
{
    std::ofstream eout("M_Format.txt", std::ios_base::app);
    std::ofstream vout("M_Value.txt", std::ios_base::app);
    std::ofstream cdout("M_Coordinates.txt", std::ios_base::app);
    std::ofstream cout("M_Color.txt", std::ios_base::app);
    std::ofstream pout("M_Position.txt", std::ios_base::app);
    for (size_t i = 0; i < _rows; i++)
    {
        for (size_t j = 0; j < _cols; j++)
        {
            (_block[i][j]).ShowColor(cout);
            (_block[i][j]).ShowFormat(eout);
            (_block[i][j]).ShowValue(vout);
            (_block[i][j]).ShowLeft(cdout);
            (_block[i][j]).ShowRight(cdout);
            (_block[i][j]).ShowPosition(pout);
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
