//NameCard.h 의 NameCard 클래스 메소드를 여기 작성함
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
    std::cout << "이름 : " << name << std::endl;
    std::cout << "회사 : " << company << std::endl;
    std::cout << "전화번호 : " << phone << std::endl;
    std::cout << "직급 : ";
    COM_POS::ShowPositionInfo(position);

    std::cout << std::endl;
}