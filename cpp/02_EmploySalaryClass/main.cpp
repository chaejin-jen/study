//실습 주제 : C++ 클래스 구현 실습 (이후 클래스 상속을 위한 기본클래스 만들기)
//실습 날짜 : 0827
//실습 내용 : 직원 급여 지급, 지급 합 (1) 기본

#include <iostream>
#include <string>


class Worker
{
private:
	std::string name;
	int salary;
public:
	Worker(std::string name, int salary) {
		this->name = name;
		this->salary = salary;
	}
	int getSalary() const {

		return this->salary;
	}
	void ShowSalaryInfo() const {
		std::cout << "name : " << this->name << std::endl;
		std::cout << "salary : " << this->salary << std::endl;
	}
};

class EmployeeHandler
{
public:
	EmployeeHandler() : empNum(0) {};

	// Worker클래스 형식에 따라, 직원 정보를 담은 객체 생성
	void AddEmployee(Worker* emp) {
		//empList배열은 포인터, emp 포인터 맞춰주기
		empList[empNum++] = emp;
	}
	// 모든 직원의 이름과, 월급정보 출력 (Woker 클래스의 ShowSalaryInfo 메소드를 사용)
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++) {
			//배열자체가 포인터이므로 그 안에 값을 표현하기 위해 다음과 같이 표현
			//(*empList[i]).ShowSalaryInfo();
			empList[i]->ShowSalaryInfo(); //포인터 empList[i]가 ShowSalaryInfo() 멤버함수를 가리키게 (클래스의 public 멤버함수를 통해 private으로 저장된 값을 불러옴)
		}
	}
	// 지급받는 월급 출력
	void ShowTotalSalary() const
	{
		long sum = 0;
		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->getSalary();
		}
		std::cout << "Total Salary : " << sum << std::endl;
	}
	// 직원 정보 전체 삭제
	~EmployeeHandler() {
		//포인터가 들어있는 배열 지움
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}

private:
	//Worker클래스의 포인터
	Worker* empList[50];
	int empNum; //직원번호
};

int main()
{
	EmployeeHandler handler;

	//클랙스 객체를 만든다면 객체지 포인터가아님. new를 사용해서 메모리 주소를 할당함.
	handler.AddEmployee(new Worker("홍길동", 400));
	handler.AddEmployee(new Worker("김철수", 500));
	handler.AddEmployee(new Worker("박영희", 600));

	//이번달 직원 급여 지급 정보
	handler.ShowAllSalaryInfo();

	//이번달 직원 급여 지급 합
	handler.ShowTotalSalary();
}

/*
	정리
		1. ->
			: 가리킨다 라고 해석하면 됨.
			아래 두 줄은 서로 같은 의미이다.
				(*empList[i]).ShowSalaryInfo();
				empList[i]->ShowSalaryInfo(); 
			포인터 empList[i]가 ShowSalaryInfo() 멤버함수를 가르킨다.
			포인터변수에 역참조연산자 *를 붙인 값은 Employee의 객체이다.
			즉, (*empList[i]).ShowSalryInfo()는 즉 객체가 멤버 함수를 호출한 것이고 empList[i]->ShowSalaryIfo() 라고 쓸 수 있다.

		2. delete
			: 가리키고 있는 메모리를 다시 운영체제로 반환한다.
			= 운영체제에서 해당 메모리를 다른 응용 프로그램에 다시 할당 가능해진다
			(배열을 지울 땐 for문으로 지움)
		
		3. new
			: 연산자는 단일 변수를 동적으로 할당하는데 사용.
			해당 메모리를 사용하여 객체를 만든 다음 할당된 메모리의 주소가 포함된 포인터를 반환. (할당된 메모리에 나중에 접근할 수 있도록 반환 값을 자체 포인터 변수에 할당)

*/