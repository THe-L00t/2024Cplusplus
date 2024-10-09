//--------------------------------------------------------------------------------------
//    2024. 2학기 9.24 수                        수78목78                        (5주 2)
//
// 참고 -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(목) - 9주 1일차 - 중간 시험예상
//--------------------------------------------------------------------------------------
// 동적할당 메모리
//--------------------------------------------------------------------------------------

#include <iostream>
#include <random>
#include <print>
#include <array>

#include "save.h"


int main()
{
	//[문제] 사용자가 입력한 숫자만큼 int를 저장할 메모리를 확보하라 
	//이 메모리를 1부터 시작하는 정수로 채워라
	//메모리에 저장된 모든 정수의 합을 화면에 출력하라

	int in{-1}, sum{0};
	std::cin >> in;

	int* arr = (int*)calloc(in, sizeof(int));//malloc ( contiguous 연속적인 메모리를 요청)
	if (arr == NULL) { return 1; }
	for (int i = 0; i < in; ++i) {
		arr[i] = i+1;
		sum += i+1;
	}

	std::cout << sum << std::endl;

	free(arr);

	//const int num{333};
	//int n[num]; const 사용하면 가능 , 그렇지 않으면 가변적이라 불가능

	save("소스.cpp");
}
