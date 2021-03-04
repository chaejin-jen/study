//�ǽ� ���� : Ŭ���� ������, �ڵ��� �������� ������!
//�ǽ� ��¥ : 0826
//�ǽ� ���� : ���� Ŭ����,Ŭ������ ������ϰ� ���� ���� ������ ��ƺ���


#include "NameCard.h"

//using namespace COM_POS;

namespace COM_POS
{
    void ShowPositionInfo(int pos) {
        switch (pos)
        {
        case CLERK:
            std::cout << "���" << std::endl;
            break;
        case SENIOR:
            std::cout << "����" << std::endl;
            break;
        case ASSIST:
            std::cout << "�븮" << std::endl;
            break;
        case MANAGER:
            std::cout << "����" << std::endl;
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


/* ����
    1. �ڵ��� �������� ���̱� ���� ������ ���� ������ ������ �ۼ��Ѵ�.
        NameCard.h - Ŭ���� ���� �������
        NameCard.cpp - Ŭ���� �ع�����
        main.cpp - main�Լ� ����
    
    2. ������ ������ �����ؾ� �� ��
        ������Ͽ��� ó���κп� #ifndef Jen__NAMECARD_h �� #define Jen__NAMECARD_h �׸��� �������ٿ� #endif�� �߰�������Ѵ�.
        ifndef�� ������ ��������� ��ġ�� ���� �����ش�.
*/