//--------------------------------------------------------------------------------------
//    2024. 2�б� 9.24 ��                        ��78��78                        (6�� 2)
//
// ���� -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(��) - 9�� 1���� - �߰� ����
//--------------------------------------------------------------------------------------
// ����� ���� �ڷ���
//--------------------------------------------------------------------------------------

#include <iostream>
#include <string>

#include "save.h"

//struct�� class�� ����Ͽ� �� �ڷ����� �����. 
class person {
	std::string name{ "����" };
private:		//access modifier - class default

}typedef Person;
struct Dog {
public:			//struct default
	std::string name{ "����" };
	int age;
	int kind;
	char color;

	void bark();
	void run();
}typedef Dog;

int main()
{	
	Dog p;
	std::cout << p.name << std::endl;
	p.name = "���ֿ�";	//�ٲ��� ���ϰ� �Ϸ��� Ŭ������ ����
	std::cout << p.name << std::endl;
	Dog d;
	(*save)("�ҽ�.cpp");//���� �Լ� ȣ��
}

