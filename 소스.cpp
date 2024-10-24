//--------------------------------------------------------------------------------------
//    2024. 2학기 10.24 목                        수78목78                        (8주 1)
//
// 참고 -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(목) - 9주 1일차 - 중간 시험
//--------------------------------------------------------------------------------------
// special member - 디폴트 생성자 / 소멸자
//					복사생성자/복사할당연산자
//					이동생성자/이동할당연산자
//--------------------------------------------------------------------------------------

#include <iostream>
#include <string>

#include "save.h"

class MemoryMonster {
private:
	int* arrnum;
	int num;
public:
	MemoryMonster(int n) :num{ n } {	//non-special function 
		arrnum = new int[num];
		for (int i = 0; i < num; ++i) {
			arrnum[i] = i + 1;
		}
		std::cout << "생성자 호출" << this << std::endl;
	}

	~MemoryMonster();	//정식 함수 선언
	
	//복사 생성자 - copy constructor
	//이거 코딩 안해도 컴파일러가 이 함수를 자동으로 생성한다 - special function
	MemoryMonster(const MemoryMonster& other);
	
	//interface function
	void show() {
		for (int i = 0; i < num; ++i) {
			std::cout << arrnum[i] << " ";
		}
	}
};

MemoryMonster::~MemoryMonster() {	//special function
	delete[] arrnum;
	std::cout << "소멸자 호출" << this <<std::endl;
}

MemoryMonster::MemoryMonster(const MemoryMonster& other) : num{ other.num }, arrnum{ other.arrnum } {
	std::cout << "복사 생성자" << this << std::endl;
}

int main()
{	
	//[문제] 실행 후 결과를 설명하라 
	// 
	// 

	MemoryMonster a( 100 );
	MemoryMonster b{ a };	//b = a
	//b는 a의 int와 int*값을 그대로 복사하여 생성한다. 그리고 b가 사라지며 
	//원래 a가 가리키고 있던 free store메모리가 할당 해제되어 
	//a에서 댕글링 포인터를 반환하게 된다. 결국 프로그램이 죽는다. 

	//기본 생성자는 정의하지 않아도 알아서 실행 => 스페셜 함수 

	save("소스.cpp");
}

