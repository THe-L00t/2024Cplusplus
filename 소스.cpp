//--------------------------------------------------------------------------------------
//    2024. 2학기 9.24 수                        수78목78                        (5주 2)
//
// 참고 -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(목) - 9주 1일차 - 중간 시험예상
//--------------------------------------------------------------------------------------
// C++ 실행파일 메모리  - STACK, DATA, free store, CODE
//--------------------------------------------------------------------------------------

#include <iostream>

#include "save.h"

int add(int, int);

int main()
{

	int num{ 123 };
	int* pn = &num;

	std::cout << "add의 자료형: " << typeid(add).name() << std::endl;

	//[](int, int)* {} fp = add; //함수를 어떻게 save할 수 있나

	(*save)("소스.cpp");//정석 함수 호출
}

int add(int a, int b) {
	return a + b;
}
