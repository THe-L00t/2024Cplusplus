//--------------------------------------------------------------------------------------
//    2024. 2학기 11.20 목                        수78목78                        (13주 1)
//
// 참고 -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(목) - 9주 1일차 - 중간 시험
//--------------------------------------------------------------------------------------
// 12/12 목요일 15주 1 - 종강
// 12/18 수요일 15주 2 - 기말
// 
// 11.27 한 시간 강의 못한 내용 - 동영상으로 일요일까지 업로드 
// 이 반 기말시험은 도형 실습문제를 내기로 말해 버림
// -------------------------------------------------------------------------------------
// 클래스 간의 관계 - 상속( inheritance )
// - 1. 코드 재사용
// - 2. 다형성 구현( dynamic binding )
//--------------------------------------------------------------------------------------

#include <iostream>

#include "save.h"

class Animal {
private:
	int a{};
public:
	Animal() {
		std::cout << "Animal C" << std::endl;
	}
	~Animal() {
		std::cout << "Animal D" << std::endl;
	}
};

//access modifier 
// - private
// - protected
// - public
// : is a 의 의미 
class Dog :public Animal {
private:
	double b{};

public:
	Dog() {
		std::cout << "Dog C" << std::endl;
	}
	~Dog() {
		std::cout << "Dog D" << std::endl;
	}
};
//클래스의 관계 검색해보기 

//클래스를 엮어서 무엇을 해결하려 하나?
// 디자인 패턴 design patterns : 우회로를 통해 해결    ?

// 상속의 이용 이유
// 1. code 재사용
// 2. polymorphism : 다(poly) 형(morph) 성(ism)
//		- One : command, interface
//		- Multiple behavior 
int main()
{
	/*std::cout <<"Animal size: "<< sizeof Animal << ", Dog size: " << sizeof Dog << std::endl;
	std::cout << "istream: " << sizeof std::istream << ", ostream: " << sizeof std::ostream << std::endl;
	std::cout << "iostream: " << sizeof std::iostream << std::endl;*/

	// 자식 객체가 확보한 메모리에는 부모의 메모리가 포함되어있다. 


	// [확인] 생성자와 소멸자의 호출을 관찰한다.  
	Animal a;
	Dog b;

	save("소스.cpp");
}
