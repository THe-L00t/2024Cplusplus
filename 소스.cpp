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
public:
	int* arrnum;
	int num;
public:
	/*MemoryMonster() = default;
	~MemoryMonster() = default;
	
	MemoryMonster( const MemoryMonster& other ) = default;
	MemoryMonster& operator=( const MemoryMonster& other ) = default;
	
	MemoryMonster( MemoryMonster&& other ) = default;
	MemoryMonster& operator=( MemoryMonster&& other ) = default;
	*/
	MemoryMonster() {
		std::cout << "디폴트 생성자" << this << std::endl;
	};
	

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
	
	MemoryMonster& operator=(const MemoryMonster& other) {
		delete[] this->arrnum;
	
		num = other.num;
		arrnum = new int[num];
		memcpy(arrnum, other.arrnum, sizeof(int) * num);//DMA
		std::cout << "복사 할당 연산자 호출" << this << std::endl;

		return *this;
	}
	//interface function
	void show() const/* cv-qualifier */ { //const 위치 중요 : 멤버변수의 값을 바꾸지 않겠다. 
		for (int i = 0; i < num; ++i) {
			std::cout << arrnum[i] << " ";
		}
		std::cout << std::endl;
	}
};

MemoryMonster::~MemoryMonster() {	//special function
	delete[] arrnum;
	std::cout << "소멸자 호출" << this <<std::endl;
}

MemoryMonster::MemoryMonster(const MemoryMonster& other) : num{ other.num } {
	arrnum = new int[num];

	////깊은 복사를 이렇게 하면 바보된다. 
	//for (int i{}; i < num; ++i) arrnum[i] = other.arrnum[i];
	////cpu가 개입하는 코드 
	
	memcpy(arrnum, other.arrnum, sizeof(int) * num);

	std::cout << "복사 생성자" << this << std::endl;
}

int main()
{	
	MemoryMonster a{ 3 };
	MemoryMonster b{ 5 };
	std::cout << b.arrnum << " " << a.arrnum << std::endl;
	a = b;	//copy assignment operator가 개입하는 special 한 순간
	std::cout << b.arrnum << " " << a.arrnum << std::endl;
	a.show();
	b.show();
	save("소스.cpp");
}


