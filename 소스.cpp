//--------------------------------------------------------------------------------------
//    2024. 2학기 11.20 목                        수78목78                        (11주 2)
//
// 참고 -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(목) - 9주 1일차 - 중간 시험
//--------------------------------------------------------------------------------------
// 12/12 목요일 15주 1 - 종강
// 12/18 수요일 15주 2 - 기말
// -------------------------------------------------------------------------------------
// move semantics (이동의미론)
// 
// 
//--------------------------------------------------------------------------------------

#include <iostream>
#include <random>
#include <string>
#include <algorithm>

#include "STRING.h"
#include "save.h"

extern bool 관찰;

int main()
{
	관찰 = true;
	STRING s[5]{ "1","333","55555","22","4444" };

	std::sort(std::begin(s), std::end(s), [](const STRING& a, const STRING& b) {
		return a.size() < b.size();
		});

	for (STRING& s : s) {
		std::cout << s << std::endl;
	}

	save("소스.cpp");
}

//xvalue expired 된 값 
//위의 s1처럼 이동된 빈 값을 가지고 있는 것을 xvalue라고 한다. 

//&	-> ampersand
//int a; int* p = &a;	-> address of n
//int& r = n;			-> reference
//int&& rr = 3;			->rvalue-reference