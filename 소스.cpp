//--------------------------------------------------------------------------------------
//    2024. 2학기 9.24 수                        수78목78                        (6주 2)
//
// 참고 -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(목) - 9주 1일차 - 중간 시험
//--------------------------------------------------------------------------------------
// 사용자 정의 자료형
//--------------------------------------------------------------------------------------

#include <iostream>
#include <string>

#include "save.h"

//struct와 class를 사용하여 새 자료형을 만든다. 
class person {
	std::string name{ "응애" };
private:		//access modifier - class default

}typedef Person;
struct Dog {
public:			//struct default
	std::string name{ "응애" };
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
	p.name = "응애요";	//바꾸지 못하게 하려면 클래스로 선언
	std::cout << p.name << std::endl;
	Dog d;
	(*save)("소스.cpp");//정석 함수 호출
}

