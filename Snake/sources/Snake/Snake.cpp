#include "Snake.h"

Snake::Snake(const Block & StartPosition)
{
    for (size_t i = 0; i < SNAKE_LENGTH; i++)
    {
        COORD left = { StartPosition.GetLeft().X, StartPosition.GetLeft().Y - (SHORT)i * 2 };
        COORD right = { StartPosition.GetRight().X, StartPosition.GetRight().Y - (SHORT)i * 2 };
        COORD position = { StartPosition.GetPosition().X, StartPosition.GetPosition().Y - (SHORT)i };
        _snake.push_back(GetBlockTemplate(left, right, position));
    }
}

bool Snake::HitBodyElement(void)
{
    bool bVal = FALSE;
    for(size_t i = 1; i < _snake.size(); i++)
    {
        if(_snake[0].GetPosition() == _snake[i].GetPosition())
        {
            bVal = TRUE;
            break;
        }
    }
    return bVal;
}

void Snake::InsertBodyElement(const Block & NewBlock)
{
    _snake.push_back(NewBlock);
}

void Snake::UpdatePosition(COORD HeadPosition)
{
    COORD Position = HeadPosition;
    if (Position == _snake[0].GetPosition())
    {
        COORD head = _snake[0].GetPosition();
        COORD body1 = _snake[1].GetPosition();
        if (head.Y == body1.Y)
        {
            Position.Y = head.Y;
            if (head.X < body1.X)
            {
                Position.X = head.X - 1;
            }
            else if (head.X > body1.X)
            {
                Position.X = head.X + 1;
            }
        }
        else if (head.X == body1.X)
        {
            Position.X = head.X;
            if (head.Y < body1.Y)
            {
                Position.Y = head.Y - 1;
            }
            else if (head.Y > body1.Y)
            {
                Position.Y = head.Y + 1;
            }
        }
        for (size_t it = _snake.size() - 1; it > 0; it--)
        {
            _snake[it].SetPosition(_snake[it - 1].GetPosition());
        }
        _snake[0].SetPosition(Position);
    }
    else if(Position == _snake[1].GetPosition())
    {

    }
    else
    {
        for (size_t it = _snake.size() - 1; it > 0; it--)
        {
            _snake[it].SetPosition(_snake[it - 1].GetPosition());
        }
        _snake[0].SetPosition(HeadPosition);
    }
}

void Snake::SeeInfos()
{
    std::ofstream eout("S_format.txt", std::ios_base::app);
    std::ofstream vout("S_value.txt", std::ios_base::app);
    std::ofstream cdout("S_coordinates.txt", std::ios_base::app);
    std::ofstream cout("S_color.txt", std::ios_base::app);
    std::ofstream pout("S_position.txt", std::ios_base::app);
    for (size_t j = 0; j < _snake.size(); j++)
    {
        _snake[j].ShowColor(cout);
        _snake[j].ShowFormat(eout);
        _snake[j].ShowValue(vout);
        _snake[j].ShowLeft(cdout);
        _snake[j].ShowRight(cdout);
        _snake[j].ShowPosition(pout);
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

