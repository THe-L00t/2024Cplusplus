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
	MemoryMonster(int n) :num{ n } { 
		arrnum = new int[num];
		for (int i = 0; i < num; ++i) {
			arrnum[i] = i + 1;
		}
	}

	~MemoryMonster() {
		delete[] arrnum;
	}
	void show() {
		for (int i = 0; i < num; ++i) {
			std::cout << arrnum[i] << std::endl;
		}
	}
};

int main()
{	
	//[문제] 다음 코드가 문제없이 실행되도록 하자 
	// MemoryMonster는 생성시에 전달된 int 개수만큼 int를 저장할 
	// 메모리를 확보한다. 메모리의 값을 1부터 시작하는 정수로 채워나간다. 

	std::cout << "int input: ";
	int num;
	std::cin >> num;

	MemoryMonster a{ num };

	a.show();	//1부터 num까지 숫자가 화면에 출력되어야 겠다.
	std::cout << "main end" << std::endl;
}

