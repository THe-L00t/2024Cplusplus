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
#include <random>

#include "save.h"



class Animal {
public:
	//Animal은 모든 동물의 공통 속성을 표현하기 위한 추상 Abstrct
	//추상 클래스는 instance하지 않는 것이 자연스럽다.
	// 이때 조상의 move 함수를 순수가상함수 pure virtual function 으로 만든다
	virtual void move() const = 0;
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


std::default_random_engine dre;
std::uniform_int_distribution uid(0,1);

int main()
{
	// [문제] 동물 호텔을 운영한다. 
	// 몇 마리가 숙박하길 원하는 지 입력받자. ( Dog와 Bird를 합한 수) 
	// 홀수면 Dog, 짝수면 Bird를 배정한다. 
	while (true) {
		std::cout << "몇 마리인가요? ";
		size_t num;
		std::cin >> num;

		Animal** animals = new Animal * [num];
		for (int i = 0; i < num; i++)
		{
			int sel = uid(dre);
			if (1 == sel)
				animals[i] = new Dog;
			else
				animals[i] = new Bird;
		}

		//전체 동물들에게 move명령을 내린다. 
		for (int i = 0; i < num; i++)
		{
			animals[i]->move();
		}

		for (int i = 0; i < num; i++)
		{
			delete animals[i];
		}
		delete[] animals;
	}
	save("소스.cpp");
}
