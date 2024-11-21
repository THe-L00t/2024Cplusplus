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
// 연산자 오버로딩 
// callable type(호출가능타입) - 함수, 멤버함수, 람다, function object
// 
//--------------------------------------------------------------------------------------

#include <iostream>
#include <random>
#include <string>
#include <print>
#include <algorithm>

#include "save.h"

std::default_random_engine dre;
std::uniform_int_distribution uidAge{ 1,99 };
std::uniform_int_distribution<int> uidName{ 'a','z' };
std::uniform_int_distribution uidNameLen{ 3,30 };

class Dog {
public:
	Dog(){
		int len =  uidNameLen(dre);
		for (int i = 0; i < len; i++)
		{
			name += uidName(dre);
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		std::print(os, "나이 : {:2}, 이름 : {}", dog.age,dog.name);
		return os;
	}

	int getAge() const{
		return age;
	}
private:
	int age{uidAge(dre)};	//{}uniform initializer  연속으로 들어간다면 해당 내용으로 초기화
	std::string name{};	//비어있다면 일반적으로 0으로 초기화지만
	//string에서는 디폴트 생성자를 불러온다.
};

bool 나이순(const Dog& a, const Dog& b);

int main()
{
	Dog dogs[10]{};

	//나이 오름차순으로 정렬하라 
	//std::sort(std::begin(dogs), std::end(dogs), 나이순);
	std::sort(std::begin(dogs), std::end(dogs), [](const Dog& a, const Dog& b)->bool {
		return a.getAge() < b.getAge();
		});
	//constexpr 컴파일 시에 계산을 끝낼 수 있다. 
	// < > 다시 코드를 찍어내는 함수이다?
	//ranges::sort() 범위 기반의 정렬함수, 가장 최신 함수 
	//c++ predicate 알아보기 

	//qsort(dogs, 10, sizeof(Dog), 나이순);

	for (const Dog& dog : dogs)
	{
		std::cout << dog << std::endl;
	}

	save("소스.cpp");
}

bool 나이순(const Dog& a, const Dog& b) {
	return a.getAge() < b.getAge();
}
