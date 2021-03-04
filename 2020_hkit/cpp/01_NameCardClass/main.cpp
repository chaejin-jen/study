//실습 주제 : 클래스 구현시, 코드의 가독성을 높이자!
//실습 날짜 : 0826
//실습 내용 : 명함 클래스,클래스를 헤더파일과 구현 파일 나누어 담아보기


#include "NameCard.h"

//using namespace COM_POS;

namespace COM_POS
{
    void ShowPositionInfo(int pos) {
        switch (pos)
        {
        case CLERK:
            std::cout << "사원" << std::endl;
            break;
        case SENIOR:
            std::cout << "주임" << std::endl;
            break;
        case ASSIST:
            std::cout << "대리" << std::endl;
            break;
        case MANAGER:
            std::cout << "과장" << std::endl;
            break;
        }
    }
}


int main()
{
    NameCard manClerk("Lee", "ABCorp", "010-1111-2222", COM_POS::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COM_POS::SENIOR);
    NameCard manAssist("Kim", "GoodCom", "010-5555-6666", COM_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}


/* 정리
    1. 코드의 가독성으 높이기 위해 다음과 같이 파일을 나누어 작성한다.
        NameCard.h - 클래스 정의 헤더파일
        NameCard.cpp - 클래스 멈버구현
        main.cpp - main함수 구현
    
    2. 파일을 나눌때 주의해야 할 점
        헤더파일에선 처음부분에 #ifndef Jen__NAMECARD_h 와 #define Jen__NAMECARD_h 그리고 마지막줄에 #endif를 추가해줘야한다.
        ifndef의 역할은 헤더파일이 겹치는 것을 막아준다.
*/