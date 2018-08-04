#include "Object.h"

void Object::SeeInfos(uint8_t Identifier)
{
    std::string FileName[5];
    FileName[0] = "C_Format";
    FileName[1] = "C_Value";
    FileName[2] = "C_Coordinates";
    FileName[3] = "C_Color";
    FileName[4] = "C_Position";
    switch (Identifier)
    {
    case IS_SNAKE: for (uint8_t i = 0; i < 5; i++) { FileName[i].replace(0, 1, "S"); } break;
    case IS_FOOD:  for (uint8_t i = 0; i < 5; i++) { FileName[i].replace(0, 1, "F"); } break;
    default: std::cout << "Object::SeeInfos(uint8_t) nu poate fi folosita" << std::endl; return;
    }
    std::ofstream eout(FileName[0], std::ios_base::app);
    std::ofstream vout(FileName[1], std::ios_base::app);
    std::ofstream cdout(FileName[2], std::ios_base::app);
    std::ofstream cout(FileName[3], std::ios_base::app);
    std::ofstream pout(FileName[4], std::ios_base::app);
    for (size_t j = 0; j < m_object.size(); j++)
    {
        m_object[j].ShowColor(cout);
        m_object[j].ShowFormat(eout);
        m_object[j].ShowValue(vout);
        m_object[j].ShowLeft(cdout);
        m_object[j].ShowRight(cdout);
        m_object[j].ShowPosition(pout);
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
