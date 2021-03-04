//NameCard.h �� NameCard Ŭ���� �޼ҵ带 ���� �ۼ���
//0825_NameCard_cpp

#include "NameCard.h"


NameCard::NameCard(std::string n, std::string c,
    std::string p, int pos) {
    name = n;
    company = c;
    phone = p;
    position = pos;
}


void NameCard::ShowNameCardInfo() {
    std::cout << "�̸� : " << name << std::endl;
    std::cout << "ȸ�� : " << company << std::endl;
    std::cout << "��ȭ��ȣ : " << phone << std::endl;
    std::cout << "���� : ";
    COM_POS::ShowPositionInfo(position);

    std::cout << std::endl;
}