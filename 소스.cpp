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
	
	MemoryMonster operator=(MemoryMonster& other) {
		delete[] this->arrnum;
		arrnum = new int[other.num];
		memcpy(arrnum, other.arrnum, sizeof(int) * num);
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
	a = b;
	std::cout << b.arrnum << " " << a.arrnum << std::endl;
	a.show();
	b.show();
	save("소스.cpp");
}


// 시험 답 1
// 자료형 A크기를 갖는 메모리 B개를 free-store에 요청한다. 
//cout << sizeof(A)*B <<endl;

//2
//cin이 읽어오다가 형식이 다르면 읽지 못한다. 그러나 내용은 버퍼에 남아있게 되어 
// 루프를 돌며 무한히 반복하게 된다. 
// 오류가 났다면 오류를 제거한다. => 버퍼를 지운다. 
// if(not cin){ 
//		cin.clear();
//		while (cin.get() != '\n')
//			;
//		continue;
// }

//3
// 지역 객체이고 디폴트 생성자이지만 스택에 만들어진 각 멤버변수의 값을 초기화 하지 않는다. 결국
// 스택에 있던 초기화 되지 않은 값이 출력된다. 

//4
// 1. 스택 오버플로우 
// 2. 컴파일러 최적화, 결국 돌아감

//5 
//함수 오버로딩
// void toupper(char& c){
// c = std::toupper(c);
// }

//6 
