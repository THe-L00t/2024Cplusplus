//--------------------------------------------------------------------------------------
//    2024. 2학기 9.24 수                        수78목78                        (6주 2)
//
// 참고 -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(목) - 9주 1일차 - 중간 시험
//--------------------------------------------------------------------------------------
// file I/O
//--------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <print>
#include <string>
#include <algorithm>

#include "save.h"

int main()
{
	//[문제] 파일 "메인.cpp"에 있는 단어를 
	// 단어의 길이를 기준으로 오름차순으로 정렬하여 출력하라
	// c++에서 단어의 처리는 std::string을 사용하면 된다
	//
	int cnt{};
	{
		std::ifstream in{ "소스.cpp" };
		if (not in) return 404;

		std::string str;
		while (in >> str) {
			++cnt;
		}
	}
	std::ifstream in{ "소스.cpp" };
	std::string* arr = new std::string[cnt];//string은 32바이트
	int i{ 0 };
	for (int i = 0; i < cnt; ++i) {
		in >> arr[i];
	}
	
	qsort(arr, cnt, sizeof(std::string), [](const void* a, const void* b) {
		const std::string* A = static_cast<const std::string*>(a);
		const std::string* B = static_cast<const std::string*>(b);
		return static_cast<int>(A->length() - B->length());
		});

	int c{ 0 };
	while (c<cnt) {
		std::cout << arr[c] << std::endl;
		++c;
	}

	(*save)("소스.cpp");//정석 함수 호출
}

