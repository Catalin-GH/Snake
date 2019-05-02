//#pragma once
//
//#include "Types.h"
//
//extern ColorGame colorGame;
//
//class Snake : public Object
//{
//public:
//    Snake() {}
//    Snake(const SquareBlock &);
//
//    inline std::vector<SquareBlock> getSnake() const;
//    inline size_t getLength() const;
//    inline void insertBodyElement(const SquareBlock & newBlock);
//
//    void build(const SquareBlock &);
//    SquareBlock getBlockTemplate(COORD, COORD, COORD);
//    bool hitBodyElement();
//    void updatePosition(COORD);
//    COORD arrowKeyPress();
//
//    COORD operator=(const COORD &);
//    friend bool operator==(const COORD &, const COORD &);
//    friend bool operator!=(const COORD &, const COORD &);
//};
//
//inline
//std::vector<SquareBlock> Snake::getSnake() const 
//{
//    return m_object; 
//}
//
//inline
//size_t Snake::getLength() const 
//{
//    return m_object.size(); 
//}
//
//inline
//void Snake::insertBodyElement(const SquareBlock & newBlock) 
//{ 
//    m_object.push_back(newBlock);
//}
