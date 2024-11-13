//--------------------------------------------------------------------------------------
//    2024. 2학기 10.24 목                        수78목78                        (10주 2)
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

#include "STRING.h"
#include "save.h"

extern bool 관찰;

int main()
{	
	관찰 = true;
	STRING s[5]{ "1", "333","55555","22","4444" };


	//[문제] s를 길이 오름차순으로 정렬하라
	qsort(s, 5, sizeof(STRING), [](const void* a, const void* b) {
		STRING& A = *(STRING*)a;
		STRING& B = *(STRING*)b;
		return static_cast<int>(A.size() - B.size());
		});

	for ( STRING& s : s) {
		std::cout << s.size() << std::endl;
	}
	save("소스.cpp");
}


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
	str[ssize - 1] = '\0';
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

