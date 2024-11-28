//--------------------------------------------------------------------------------------
//    2024. 2학기 11.20 목                        수78목78                        (13주 1)
//
// 참고 -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(목) - 9주 1일차 - 중간 시험
//--------------------------------------------------------------------------------------
// 12/12 목요일 15주 1 - 종강
// 12/18 수요일 15주 2 - 기말
// 
// 11.27 한 시간 강의 못한 내용 - 동영상으로 일요일까지 업로드 
// 이 반 기말시험은 도형 실습문제를 내기로 말해 버림
// -------------------------------------------------------------------------------------
// 클래스 간의 관계 - 상속( inheritance )
// - 1. 코드 재사용
// - 2. 다형성 구현( dynamic binding )
//--------------------------------------------------------------------------------------

#include <iostream>
#include <string>

#include "save.h"

class Animal {
private:
	int a{};
public:
	Animal() {
		std::cout << "Animal C" << std::endl;
	}
	~Animal() {
		std::cout << "Animal D" << std::endl;
	}
};

//access modifier 
// - private
// - protected
// - public
// : is a 의 의미 
class Dog :public Animal {
private:
	double b{};

public:
	Dog() {
		std::cout << "Dog C" << std::endl;
	}
	~Dog() {
		std::cout << "Dog D" << std::endl;
	}
};
//클래스의 관계 검색해보기 

//클래스를 엮어서 무엇을 해결하려 하나?
// 디자인 패턴 design patterns : 우회로를 통해 해결    ?

// 상속의 이용 이유
// 1. code 재사용
// 2. polymorphism : 다(poly) 형(morph) 성(ism)
//		- One : command, interface
//		- Multiple behavior 
class BankString : public std::string {
public:
	friend std::ostream& operator<<(std::ostream& os, const std::string& str) {
		for (const char& c : str) {
			if (c >= '0' && c <= '9') os << '*';
			else os << c;
		}
		return os;
	}
};
int main()
{
	// [문제] 은행에서 사용할 string이다. 
	// 저장한 string의 내용을 화면에 출력할때 숫자를 '*'로 바꾸어 출력한다.  
	// 다음 프로그램이 문제없이 실행되게 하자.
	BankString s{ "2024년 11월 28일" };

	std::cout << s << std::endl;
	save("소스.cpp");
}

// c++ main keyword
// 1. const, & (읽기만 할 수 있다. , 원격제어하겠다. / 복사하지 않겠다.)
// 2. virtual -> polymorphism
// 3. template -> generic programming