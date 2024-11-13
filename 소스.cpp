//--------------------------------------------------------------------------------------
//    2024. 2학기 10.24 목                        수78목78                        (10주 1)
//
// 참고 -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(목) - 9주 1일차 - 중간 시험
//--------------------------------------------------------------------------------------
// 연산자 오버로딩
// std::string 을 흉내낸 STRING을 작성
// int를 흉내낸 INT를 작성하여 연산자를 오버로딩할 필요성
//--------------------------------------------------------------------------------------

#include <iostream>
#include <random>
#include <string>

#include "save.h"



int main()
{	
	//[문제] 이 코드가 문제없이 실행되도록 class string을 코딩하라 
	//적어도 아래 2 줄은 여러분 모두 코딩할 수 있습니다. 
	// 다음 주 올 때까지 살려주세요. 

	class STRING {
	private:
		char* str;

	public:
		STRING(const char* str);
		int size();
		const char* operator[](int idx);
		char* begin();
		char* end();
		const char* operator+(const char* other);
	};

	//std::string s{ "The C++ Progamming Language. " };
	STRING s{ "The C++ Progamming Language. " };

	std::cout << "s의 글자 수 - " << s.size() << std::endl;

	for (int i = 0; i < s.size(); i++)
	{
		std::cout << s[i] << "-";
	}

	for (char c : s)
		std::cout << c << "-";

	s = s + "정말 재미있는 언어네요. 배우고 싶어서 잠이 안와요 ";
	std::cout << "s의 글자 수 - " << s.size() << std::endl;

	save("소스.cpp");
}


