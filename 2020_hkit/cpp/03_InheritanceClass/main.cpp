//�ǽ� ���� : Ŭ������ ���(Inheritance)�� ���� �������
//�ǽ� ��¥ : 0827
//�ǽ� ���� : ���� �޿� ����, ���� ���� (2)  ������, ��ƮŸ��

#include <iostream>
#include <string>

class Employee {
private:
	std::string name;
public:
	/*���ʻ����� �߰� ���ϸ� �Ʒ� ��� ������.
	�Ļ� Ŭ������ ��ü ���� �� ���α׷��� ���� Ŭ������ �����ڸ� ȣ���Ѵ�.
	�̶�, ���� Ŭ���� �����ڴ� ��ӹ��� ��� ������ �ʱ�ȭ�� �����ϹǷ� ���ʻ����ڰ� �� �ʿ��ϴ�.*/
	Employee() {}
	Employee(std::string name) {
		this->name = name;
	}

	/*�����Լ��� ȣ���ϸ� ��ӹ��� Ŭ�������� ���� �̸��� ���� ����Լ� (getName, getPay)�� �ڵ� ȣ���Ѵ�.
	(���� �Ű������� �ٸ��Ƿ� �´� ������)*/
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
	//���!! Employee�� �����ڿ� ���� ����ִ� ���̱� ������ �Ʒ�ó�� ���ٿ� �������
	Permanentworker(std::string name, int salary) : Employee(name) {
		this->salary = salary;
	}

	int getPay() const {

		return this->salary;
	}
	void ShowSalaryInfo() const {
		getName();
		//std::cout << "salary : " << this->salary << std::endl;
		std::cout << "salary : " << getPay() << std::endl; //�Լ� getPay() ȣ���Ͽ� ��ȯ���� ���
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
	//���� �ð��� ���� �޿�
	int getPay() const {
		return work_time * pay_per_hour;
	}
	void ShowSalaryInfo() const {
		getName();
		std::cout << "salary : " << getPay() << std::endl; //�Լ� getPay() ȣ���Ͽ� ��ȯ���� ���
	}

};

class SalesWoker : public Permanentworker //�������� ���
{
private:
	int sales_result; //�� ���� ����
	double bonus_ratio; // �󿩱� ���� ����
public:
	//�Ź� ����������, ������ ����
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
	//WorkerŬ������ ������
	Employee* empList[50];
	int empNum; //������ȣ

public:
	EmployeeHandler() {
		empNum = 0;
		for (int i = 0; i < 50; i++)
			empList[i] = NULL;
	}

	//
	void AddEmployee(Employee* emp) {
		//empList�迭�� ������, emp ������ �����ֱ�
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {

		for (int i = 0; i < empNum; i++) {
			//�迭�ε� �������̹Ƿ� �� �ȿ� ��(�����Ͱ� ����Ű�� ��)�� ǥ���ϱ� ���� ������ ���� ǥ��
			//(*empList[i]).ShowSalaryInfo();
			empList[i]->ShowSalaryInfo();
			//�����ͺ����� ������������ *�� ���� ���� Employee�� ��ü�̹Ƿ� ShowSalryInfo() ����Լ��� ȣ���� ���Ѵ�.
			//ȣ���� Ŭ���� ��ü�� ���� �ڵ����� Ŭ���� �Լ� ȣ�� (��ӹ��� ��� �Ʒ��� ������ �� ����)


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
		//�����ͷ� �迭 50���� ���� ���� (������ �Ҵ��Ѱ���) �����ֱ�
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}

};

int main()
{
	EmployeeHandler handler;

	//Ŭ���� ��ü�� ����ٸ� ��ü�� �����Ͱ��ƴ�. new�� ����ؼ� �޸� �ּҸ� �Ҵ���.
	handler.AddEmployee(new Permanentworker("ȫ�浿", 400));
	handler.AddEmployee(new Permanentworker("��ö��", 500));
	handler.AddEmployee(new Permanentworker("�ڿ���", 600));

	TemporaryWorker* partTime1 = new TemporaryWorker("������", 700);
	partTime1->AddWorkTime(5);
	handler.AddEmployee(partTime1);

	SalesWoker* sales1 = new SalesWoker("�̿���", 500, 0.03);
	sales1->AddSalesResult(7000);
	handler.AddEmployee(sales1);

	//�̹��� ���� �޿� ���� ����
	handler.ShowAllSalaryInfo();

	//�̹��� ���� �޿� ���� ��
	handler.ShowTotalSalary();
}

/* ����
	1. ����
	Ŭ���� ���: ������ ���ǵǾ� �ִ� Ŭ������ ��� ��� ������ ��� �Լ��� �����޾�, ���ο� Ŭ������ �ۼ��ϴ� ��
		����(�⺻Ŭ����): ���� Ŭ����(base class) �Ǵ� �θ� Ŭ����(parent class), ���� Ŭ����(super class)
		���ο�: �Ļ� Ŭ����(derived class) �Ǵ� �ڽ� Ŭ����(child class), ���� Ŭ����(sub class)
		*** ���ϻ�� �� �ƴ϶� ���߻�� �����ϴ�
	
	2. �Ļ� Ŭ������ ��ü ������ �Ҹ�
		Permanentworker(std::string name, int salary) : Employee(name)
		�Ļ�Ŭ������ ������                             ����Ŭ������ ������
		(1) �Ļ� Ŭ������ ��ü�� �����ϸ�, ���α׷��� ���� ���� ���� Ŭ������ �����ڸ� ȣ�� (�̶� ���� Ŭ���� �����ڴ� ��ӹ��� ��� ������ �ʱ�ȭ�� ����)
		(2) �Ļ� Ŭ������ �����ڰ� ȣ��
		(3) �ݴ�� �Ļ� Ŭ������ ������ ���ϸ�, ���� �Ļ� Ŭ������ �Ҹ��ڰ� ȣ��ǰ�, �� �Ŀ� ���� Ŭ������ �Ҹ��ڰ� ȣ��
*/