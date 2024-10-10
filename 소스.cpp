//--------------------------------------------------------------------------------------
//    2024. 2학기 9.24 수                        수78목78                        (6주 1)
//
// 참고 -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(목) - 9주 1일차 - 중간 시험예상
//--------------------------------------------------------------------------------------
// 함수 포인터
//--------------------------------------------------------------------------------------

#include <iostream>
#include <memory>

#include "save.h"

char c[1'500'000'000];

int main()
{
	//[문제] 실행 결과를 해석하라
	//전역변수는 자동으로 0으로 초기화 된다. 그러나 char형이라 아스키코드 0번인 
	//null 빈칸이 출력되게 된다.
	for (int i = 0; i < 10; ++i) {
		std::cout << c[i] << " ";
	}
	

	(*save)("소스.cpp");//정석 함수 호출
}

