//������Ͽ� ���μҽ����� ����� namespace�� Ŭ���� ����
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

//�����迭�� ������� �������
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
