//--------------------------------------------------------------------------------------
//    2024. 2학기 11.20 목                        수78목78                        (13주 1)
//
// 참고 -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(목) - 9주 1일차 - 중간 시험
//--------------------------------------------------------------------------------------
// 12/12 목요일 15주 1 - 종강
// 12/18 수요일 15주 2 - 기말 E동 219호
// 
// 11.27 한 시간 강의 못한 내용 - 동영상으로 일요일까지 업로드 
// 이 반 기말시험은 도형 실습문제를 내기로 말해 버림
// -------------------------------------------------------------------------------------
// 클래스 간의 관계 - 상속( inheritance )
// - 2. 다형성 구현( dynamic binding )
//--------------------------------------------------------------------------------------

#include <iostream>
#include <string>

#include "save.h"

class Animal {
public:
	virtual void move() const {	//virtual을 사용하면 virtual pointer가 추가 할당 된다. 
		std::cout << "동물의 move" << std::endl;
	}
	//포인터이므로 8바이트 
private:
	int a;
};

class Dog : public Animal{
public:
	void move() const {
		std::cout << "개 달린다" << std::endl;
	}
private:
	double d;
};

class Bird : public Animal{
public:
	void move() const {
		std::cout << "새 난다" << std::endl;
	}
private:
	//char c; 8bite = 4bite,1bite,3bite(data padding)
	int b;
}; //상속 받을때에는 부모 클래스의 메모리는 건드리지 않는다. 

int main()
{
	Animal animal;
	Dog dog;
	Bird bird;

	//polymorphism 을 구현하려면 객체를 부모의 *로 가리켜야 한다. 
	Animal* animals[3];
	animals[0] = &animal;
	animals[1] = &dog;
	animals[2] = &bird;

	//모든 동물들에게 move()를 호출한다. 
	for (int i = 0; i < 3; i++)
	{
		animals[i]->move();		//이 함수는 dynamic binding
	}

	//다형성은 메모리를 막대하게 희생하여 유연함을 얻는다. 

	//같은 이름의 함수라면 c++에서는 name mangling하기 때문에 구분 가능하다. 
	// 추가 기호를 붙여 구분한다. 

	//컴파일 시간에 어떤 함수를 찾아가야할지 정해진다 -> static binding

	//dynamic binding 

	//memory size check
	std::cout << "Aniaml : " << sizeof Animal << std::endl;
	std::cout << "Dog : " << sizeof Dog << std::endl;
	std::cout << "Bird : " << sizeof Bird << std::endl;

	save("소스.cpp");
}
