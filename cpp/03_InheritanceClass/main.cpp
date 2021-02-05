//실습 주제 : 클래스의 상속(Inheritance)에 대해 배워보자
//실습 날짜 : 0827
//실습 내용 : 직원 급여 지급, 지급 총합 (2)  정규직, 파트타임

#include <iostream>
#include <string>

class Employee {
private:
	std::string name;
public:
	/*기초생성자 추가 안하면 아래 상속 못받음.
	파생 클래스의 객체 생성 시 프로그램이 기초 클래스의 생성자를 호출한다.
	이때, 기초 클래스 생성자는 상속받은 멤버 변수의 초기화를 진행하므로 기초생성자가 꼭 필요하다.*/
	Employee() {}
	Employee(std::string name) {
		this->name = name;
	}

	/*가상함수를 호출하면 상속받은 클래스에서 같은 이름을 지닌 멤버함수 (getName, getPay)를 자동 호출한다.
	(각각 매개변수가 다르므로 맞는 것으로)*/
	void getName() const {
		std::cout << "name : " << name << std::endl;
	}
	virtual int getPay() const
	{
		return 0;
	}
	virtual void ShowSalaryInfo() const {}

};

class Permanentworker : public Employee
{
private:
	std::string name;
	int salary;
public:
	Permanentworker() {};
	//상속!! Employee의 생성자에 값을 집어넣는 것이기 때문에 아래처럼 윗줄에 써줘야함
	Permanentworker(std::string name, int salary) : Employee(name) {
		this->salary = salary;
	}

	int getPay() const {

		return this->salary;
	}
	void ShowSalaryInfo() const {
		getName();
		//std::cout << "salary : " << this->salary << std::endl;
		std::cout << "salary : " << getPay() << std::endl; //함수 getPay() 호출하여 반환값을 출력
	}
};

class TemporaryWorker : public Employee
{
private:
	int work_time;
	int pay_per_hour;
public:
	TemporaryWorker() {};
	TemporaryWorker(std::string name, int pay_per_hour) : Employee(name) {
		this->work_time = 0;
		this->pay_per_hour = pay_per_hour;
	}
	void AddWorkTime(int work_time) {
		this->work_time += work_time;
	}
	//일한 시간에 대한 급여
	int getPay() const {
		return work_time * pay_per_hour;
	}
	void ShowSalaryInfo() const {
		getName();
		std::cout << "salary : " << getPay() << std::endl; //함수 getPay() 호출하여 반환값을 출력
	}

};

class SalesWoker : public Permanentworker //정규직을 상속
{
private:
	int sales_result; //월 매출 실적
	double bonus_ratio; // 상여금 지급 비율
public:
	//매번 변동이지만, 비율은 고정
	SalesWoker(std::string name, int salary, double bonus_ratio) :Permanentworker(name, salary) {

		this->bonus_ratio = bonus_ratio;
		this->sales_result = 0;
	}
	int getPay() const {
		return Permanentworker::getPay() + int(sales_result * bonus_ratio);
	}

	void AddSalesResult(int sales_result) {
		this->sales_result += sales_result;
	}

};


class EmployeeHandler
{
private:
	//Worker클래스의 포인터
	Employee* empList[50];
	int empNum; //직원번호

public:
	EmployeeHandler() {
		empNum = 0;
		for (int i = 0; i < 50; i++)
			empList[i] = NULL;
	}

	//
	void AddEmployee(Employee* emp) {
		//empList배열은 포인터, emp 포인터 맞춰주기
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {

		for (int i = 0; i < empNum; i++) {
			//배열로된 포인터이므로 그 안에 값(포인터가 가리키는 값)을 표현하기 위해 다음과 같이 표현
			//(*empList[i]).ShowSalaryInfo();
			empList[i]->ShowSalaryInfo();
			//포인터변수에 역참조연산자 *를 붙인 값은 Employee의 객체이므로 ShowSalryInfo() 멤버함수의 호출을 뜻한다.
			//호출한 클래스 객체에 따라 자동으로 클래스 함수 호출 (상속받은 경우 아래로 내려올 수 있음)


		}
	}
	void ShowTotalSalary() const
	{
		long sum = 0;
		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->getPay();
		}
		std::cout << "Total Salary : " << sum << std::endl;
	}
	~EmployeeHandler() {
		//포인터로 배열 50개를 만든 것을 (공간을 할당한것을) 지워주기
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}

};

int main()
{
	EmployeeHandler handler;

	//클랙스 객체를 만든다면 객체지 포인터가아님. new를 사용해서 메모리 주소를 할당함.
	handler.AddEmployee(new Permanentworker("홍길동", 400));
	handler.AddEmployee(new Permanentworker("김철수", 500));
	handler.AddEmployee(new Permanentworker("박영희", 600));

	TemporaryWorker* partTime1 = new TemporaryWorker("권프로", 700);
	partTime1->AddWorkTime(5);
	handler.AddEmployee(partTime1);

	SalesWoker* sales1 = new SalesWoker("이영업", 500, 0.03);
	sales1->AddSalesResult(7000);
	handler.AddEmployee(sales1);

	//이번달 직원 급여 지급 정보
	handler.ShowAllSalaryInfo();

	//이번달 직원 급여 지급 합
	handler.ShowTotalSalary();
}

/* 정리
	1. 개념
	클래스 상속: 기존에 정의되어 있는 클래스의 모든 멤버 변수와 멤버 함수를 물려받아, 새로운 클래스를 작성하는 것
		기존(기본클래스): 기초 클래스(base class) 또는 부모 클래스(parent class), 상위 클래스(super class)
		새로운: 파생 클래스(derived class) 또는 자식 클래스(child class), 하위 클래스(sub class)
		*** 단일상속 뿐 아니라 다중상속 가능하다
	
	2. 파생 클래스의 객체 생성과 소멸
		Permanentworker(std::string name, int salary) : Employee(name)
		파생클래스의 생성자                             기초클래스의 생성자
		(1) 파생 클래스의 객체를 생성하면, 프로그램은 제일 먼저 기초 클래스의 생성자를 호출 (이때 기초 클래스 생성자는 상속받은 멤버 변수의 초기화를 진행)
		(2) 파생 클래스의 생성자가 호출
		(3) 반대로 파생 클래스의 수명이 다하면, 먼저 파생 클래스의 소멸자가 호출되고, 그 후에 기초 클래스의 소멸자가 호출
*/