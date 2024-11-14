//--------------------------------------------------------------------------------------
//    2024. 2학기 10.24 목                        수78목78                        (11주 1)
//
// 참고 -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(목) - 9주 1일차 - 중간 시험
//--------------------------------------------------------------------------------------
// 12/12 목요일 15주 1 - 기말
// 12/18 수요일 15주 2 - 종강
// -------------------------------------------------------------------------------------
// 연산자 오버로딩
// std::string 을 흉내낸 STRING을 작성
// int를 흉내낸 INT를 작성하여 연산자를 오버로딩할 필요성
//--------------------------------------------------------------------------------------

#include <iostream>
#include <random>
#include <string>

#include "STRING.h"
#include "save.h"

extern bool 관찰;




int main()
{	
	관찰 = true;
	STRING s = { "The C++ Programming language!" };
	std::cout << s.size() << std::endl;

	s = s + "참 재미있다. ";
	std::cout << s << std::endl;
	save("소스.cpp");
}

// X c = a $ b;
// 기계어가 지원되지 않는 다면 함수 호출로 생각한다. 
// 결국 함수라 생각하므로 code 세그먼트라 생각한다.
// 1. a.operator$(b)라는 멤버함수가 있나 찾아본다. 
// 2. 없다면,X operator$(a,b)라는 전역함수를 찾아본다. 
// 둘 다 없다면 컴파일 실패 




//혼자 해본거
/*
* class STRING {
private:
	size_t ssize{};
	char* str;
public:
	STRING(const char* istr);
	int size();
	const char operator[](int idx);
	char* begin();
	char* end();
	const char* operator+(const char* other);
};

STRING::STRING(const char* istr) {
	ssize = sizeof(istr) + 1;
	str = new char[ssize];
	memcpy(str, istr, sizeof(istr));
	str[ssize - 1] = '\0';		//마지막 널은 전혀 신경 쓸 이유가 없다. 
	/*for (int i = 0; i < sizeof(istr); ++i)
	{
		str[i] = str
	}
};
int STRING::size() {
	return ssize;
};
const char STRING::operator[](int idx) {
	return str[idx];
};
char* STRING::begin() {
	return str;
}
char* STRING::end() {
	return &str[ssize - 1];
}
const char* STRING::operator+(const char* other) {
	char* temp = new char[ssize];
	memcpy(temp, str, ssize);
	delete str;
	ssize = ssize + sizeof(other);
	str = new char[ssize];
	memcpy(str, temp, sizeof(temp) - 1);
	memcpy(&str[sizeof(temp) - 1], other, sizeof(other));
}
*/

