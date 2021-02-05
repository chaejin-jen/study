//�ǽ� ���� : C++ Ŭ���� ���� �ǽ� (���� Ŭ���� ����� ���� �⺻Ŭ���� �����)
//�ǽ� ��¥ : 0827
//�ǽ� ���� : ���� �޿� ����, ���� �� (1) �⺻

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

	// WorkerŬ���� ���Ŀ� ����, ���� ������ ���� ��ü ����
	void AddEmployee(Worker* emp) {
		//empList�迭�� ������, emp ������ �����ֱ�
		empList[empNum++] = emp;
	}
	// ��� ������ �̸���, �������� ��� (Woker Ŭ������ ShowSalaryInfo �޼ҵ带 ���)
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++) {
			//�迭��ü�� �������̹Ƿ� �� �ȿ� ���� ǥ���ϱ� ���� ������ ���� ǥ��
			//(*empList[i]).ShowSalaryInfo();
			empList[i]->ShowSalaryInfo(); //������ empList[i]�� ShowSalaryInfo() ����Լ��� ����Ű�� (Ŭ������ public ����Լ��� ���� private���� ����� ���� �ҷ���)
		}
	}
	// ���޹޴� ���� ���
	void ShowTotalSalary() const
	{
		long sum = 0;
		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->getSalary();
		}
		std::cout << "Total Salary : " << sum << std::endl;
	}
	// ���� ���� ��ü ����
	~EmployeeHandler() {
		//�����Ͱ� ����ִ� �迭 ����
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}

private:
	//WorkerŬ������ ������
	Worker* empList[50];
	int empNum; //������ȣ
};

int main()
{
	EmployeeHandler handler;

	//Ŭ���� ��ü�� ����ٸ� ��ü�� �����Ͱ��ƴ�. new�� ����ؼ� �޸� �ּҸ� �Ҵ���.
	handler.AddEmployee(new Worker("ȫ�浿", 400));
	handler.AddEmployee(new Worker("��ö��", 500));
	handler.AddEmployee(new Worker("�ڿ���", 600));

	//�̹��� ���� �޿� ���� ����
	handler.ShowAllSalaryInfo();

	//�̹��� ���� �޿� ���� ��
	handler.ShowTotalSalary();
}

/*
	����
		1. ->
			: ����Ų�� ��� �ؼ��ϸ� ��.
			�Ʒ� �� ���� ���� ���� �ǹ��̴�.
				(*empList[i]).ShowSalaryInfo();
				empList[i]->ShowSalaryInfo(); 
			������ empList[i]�� ShowSalaryInfo() ����Լ��� ����Ų��.
			�����ͺ����� ������������ *�� ���� ���� Employee�� ��ü�̴�.
			��, (*empList[i]).ShowSalryInfo()�� �� ��ü�� ��� �Լ��� ȣ���� ���̰� empList[i]->ShowSalaryIfo() ��� �� �� �ִ�.

		2. delete
			: ����Ű�� �ִ� �޸𸮸� �ٽ� �ü���� ��ȯ�Ѵ�.
			= �ü������ �ش� �޸𸮸� �ٸ� ���� ���α׷��� �ٽ� �Ҵ� ����������
			(�迭�� ���� �� for������ ����)
		
		3. new
			: �����ڴ� ���� ������ �������� �Ҵ��ϴµ� ���.
			�ش� �޸𸮸� ����Ͽ� ��ü�� ���� ���� �Ҵ�� �޸��� �ּҰ� ���Ե� �����͸� ��ȯ. (�Ҵ�� �޸𸮿� ���߿� ������ �� �ֵ��� ��ȯ ���� ��ü ������ ������ �Ҵ�)

*/