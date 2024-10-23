//--------------------------------------------------------------------------------------
//    2024. 2학기 9.24 수                        수78목78                        (6주 2)
//
// 참고 -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(목) - 9주 1일차 - 중간 시험
//--------------------------------------------------------------------------------------
// 사용자 정의 자료형
//--------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <random>
#include <cmath>

#include "save.h"

std::default_random_engine dre;
std::uniform_int_distribution uid{ -99,99 };

struct Point2D {
	//variable member
	int x{ uid(dre) };
	int y{ uid(dre) };

	//function member
	void show() {
		std::cout <<"("<< x << ", " << y <<")" << std::endl;
	}
	double distance() {	//원점에서의 거리 
		return std::sqrt((x * x) + (y * y));
	}

};


int main()
{	
	Point2D points[100];	//instancing : 메모리에 생성
	//for (Point2D point : points) point.show();

	//[문제] (0,0)에서 반경 20 미만의 점에 영향을 미치는 폭탄이 터졌다. 
	//영향 받는 점들의 좌표를 화면에 출력하고, 모두 몇 개인지 출력하라 
	//root 값은 함수를 이용하여 구할 수 있다. 
	int count{ 0 };
	for (Point2D point : points) {
		if (20 > point.distance()) {
			++count;
			point.show();
		} 
	}
	std::cout << "반경 내의 점의 개수 :" << count << std::endl;

	(*save)("소스.cpp");//정석 함수 호출
}

