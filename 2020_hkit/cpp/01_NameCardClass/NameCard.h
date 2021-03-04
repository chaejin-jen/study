//헤더파일에 메인소스에서 사용할 namespace와 클래스 선언
//0825_NameClass_h

#ifndef Jen__NAMECARD_h
#define Jen__NAMECARD_h

#include <iostream>
#include <vector>
#include <string>


namespace COM_POS
{
    enum { CLERK, SENIOR, ASSIST, MANAGER };
    void ShowPositionInfo(int pos);
}

//동적배열로 만들려면 어려워짐
class NameCard {
public:
    NameCard(std::string n, std::string c, std::string p, int pos);
    void ShowNameCardInfo();

private:
    std::string name;
    std::string company;
    std::string phone;
    int position;
};

#endif#pragma once
