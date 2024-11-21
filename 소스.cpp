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

	int getAge() const{
		return age;
	}

	//함수호출 연산자를 오버로딩하면 이 class객체는 호출 가능하게 된다. 
	//함수호출 연산자를 오버로딩한 이 class의 객체를 function object라 한다 . 
	//left hand side   right hand side
	bool operator()(const Dog& lhs, const Dog& rhs)const {
		return lhs.age < rhs.age;
	}

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		std::print(os, "나이 : {:2}, 이름 : {}", dog.age,dog.name);
		return os;
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

	//Dog dog;                                  dog 가 들어가도 됨
	std::sort(std::begin(dogs), std::end(dogs), Dog{});
	//가능하다. 그러나 빌드 오류 발생 
	
	for (const Dog& dog : dogs)
	{
		std::cout << dog << std::endl;
	}

	save("소스.cpp");
}

bool 나이순(const Dog& a, const Dog& b) {
	return a.getAge() < b.getAge();
}
