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

#include "STRING.h"
#include "save.h"

extern bool 관찰;




int main()
{	
	//copy elision - RVO(Return Value Optimization)
	관찰 = true;
	STRING s = { "The C++ Programming language!" };

	//[문제] 다음 코드가 의도대로 실행도게 하라
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = std::toupper(s[i]);
		// 식이 수정할 수 있는 lvalue여야 합니다. 
		//lvalue(location value) = right-value 
		//value category 찾아보기 
		//표현식 expression은 glvalue와 rvalue로 나뉜다. 
		// glvalue	--> lvalue		:xvlaue가 아닌 glvalue
		//			>-> xvalue		:
		// rvalue	--> prlvalue	:
	}

	std::cout << s << std::endl;
	//관찰 = false;
	save("소스.cpp");
}


