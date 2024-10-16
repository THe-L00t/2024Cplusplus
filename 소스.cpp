//--------------------------------------------------------------------------------------
//    2024. 2학기 9.24 수                        수78목78                        (6주 2)
//
// 참고 -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(목) - 9주 1일차 - 중간 시험예상
//--------------------------------------------------------------------------------------
// file I/O
//--------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <print>

#include "save.h"


int main()
{
	//[문제] 파일 "랜덤값 몇개.mp3"에는 몇 개인지 모르는 int 값이
	//저장되어 있다.
	// 오름차순 정렬하려 화면 출력하라
	// 
	int count{ 0 };
	{
		std::ifstream in{ "랜덤값 몇개.mp3" };
		if (not in) {		// 에러 확인 필수 
			std::cout << "불러오기 실패" << std::endl;
			return 333;
		}

		int max{ -1 }, num;
		while (in >> num) {	//!in.eof() 사용하지 않기  : in >> num 사용하기 

			++count;
			max = (max < num) ? num : max;
		}
	std::cout << "int의 개수 : " << count << std::endl << "가장 큰 값 : " << max << std::endl;
	}

	std::ifstream in{ "랜덤값 몇개.mp3" };
	int* arr = new int[count];
	int num, i{ 0 };
	while (in >> num) {
		arr[i] = num;
		++i;
	}
	qsort(arr, count, sizeof(int), [](const void* a, const void* b) {return *(int*)a - *(int*)b; });
	for (int j = 0; j < count; ++j) {
		std::print("{:16}", arr[j]);
	}

	(*save)("소스.cpp");//정석 함수 호출
}

