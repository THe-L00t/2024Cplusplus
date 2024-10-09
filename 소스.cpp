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

using namespace std::literals;

char c[1'000'000'000]{ 'A', 'B','C' };

int main()
{
	for (int i = 0; i < 10; ++i) {
		std::cout << (char)(c[i] + 7) << std::endl;
	}
	save("소스.cpp");
}
