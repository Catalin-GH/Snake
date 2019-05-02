//#include "Snake.h"
//
//Snake::Snake(const SquareBlock & StartPosition) {
//    build(StartPosition);
//}
//
//void Snake::build(const SquareBlock & StartPosition) {
//    for (SHORT i = 0; i < Length::snake; i++) {
//        SquareBlock block;
//        COORD left = { StartPosition.getLeft().X, StartPosition.getLeft().Y - i * 2 };
//        COORD right = { StartPosition.getRight().X, StartPosition.getRight().Y - i * 2 };
//        COORD position = { StartPosition.getPosition().X, StartPosition.getPosition().Y - i };
//        block.setValue(BlockType::format);
//        block.setFormat(Category::snake);
//        block.setLeft(left);
//        block.setRight(right);
//        block.setPosition(position);
//        block.setColor(colorGame.snake);
//        m_object.push_back(block);
//    }
//}
//
//SquareBlock Snake::getBlockTemplate(COORD left, COORD right, COORD position) {
//    SquareBlock block;
//
//    block.setValue(BlockType::format);
//    block.setColor(colorGame.snake);
//    block.setFormat(Category::snake);
//    block.setLeft(left);
//    block.setRight(right);
//    block.setPosition(position);
//
//    return block;
//}
//
//bool Snake::hitBodyElement() {
//    bool bVal = FALSE;
//
//    for (size_t i = 1; i < m_object.size(); i++) {
//        if (m_object[0].getPosition().X == m_object[i].getPosition().X && 
//            m_object[0].getPosition().Y == m_object[i].getPosition().Y) {
//            bVal = TRUE;
//            break;
//        }
//    }
//
//    return bVal;
//}
//
//void Snake::updatePosition(COORD HeadPosition) {
//    COORD Position = HeadPosition;
//    if (Position.X == m_object[0].getPosition().X &&
//        Position.Y == m_object[0].getPosition().Y) {
//        COORD head = m_object[0].getPosition();
//        COORD body1 = m_object[1].getPosition();
//        if (head.Y == body1.Y) {
//            Position.Y = head.Y;
//            if (head.X < body1.X) {
//                Position.X = head.X - 1;
//            }
//            else if (head.X > body1.X) {
//                Position.X = head.X + 1;
//            }
//        }
//        else if (head.X == body1.X) {
//            Position.X = head.X;
//            if (head.Y < body1.Y) {
//                Position.Y = head.Y - 1;
//            }
//            else if (head.Y > body1.Y) {
//                Position.Y = head.Y + 1;
//            }
//        }
//        for (size_t it = m_object.size() - 1; it > 0; it--) {
//            m_object[it].setPosition(m_object[it - 1].getPosition());
//        }
//        m_object[0].setPosition(Position);
//    }
//    else if (Position.X == m_object[1].getPosition().X &&
//             Position.Y == m_object[1].getPosition().Y) {
//
//    }
//    else {
//        for (size_t it = m_object.size() - 1; it > 0; it--) {
//            m_object[it].setPosition(m_object[it - 1].getPosition());
//        }
//        m_object[0].setPosition(HeadPosition);
//    }
//}
//
//COORD Snake::arrowKeyPress() {
//    COORD newPosition = m_object[0].getPosition();
//
//    if (GetAsyncKeyState(VK_LEFT)) {
//        newPosition.Y -= 1;
//        return newPosition;
//    }
//    if (GetAsyncKeyState(VK_UP)) {
//        newPosition.X -= 1;
//        return newPosition;
//    }
//    if (GetAsyncKeyState(VK_RIGHT)) {
//        newPosition.Y += 1;
//        return newPosition;
//    }
//    if (GetAsyncKeyState(VK_DOWN)) {
//        newPosition.X += 1;
//    }
//
//    return newPosition;
//}
//
//COORD Snake::operator=(const COORD & New_Pos) {
//    COORD Actual_Pos;
//    Actual_Pos.X = New_Pos.X;
//    Actual_Pos.Y = New_Pos.Y;
//    return Actual_Pos;
//}
