//---------------------------------------------------------------------
// 여기에서는 클래스의 함수멤버를 정의 한다. 
//
//
//---------------------------------------------------------------------
#include <cstring>
#include <iostream>
#include "STRING.h"

bool 관찰{ false };

STRING::STRING(const char* s) : num{ strlen(s) }	//RAII
{	
		p = new char[num];
		memcpy(p, s, num);
		if (관찰) std::cout << "생성자(const char*) - " << num << ", " << this << std::endl;
}

//operator+ 에서 필요하여 만듦
STRING::STRING(size_t n) : num{n}
{
	p = new char[num];
	if (관찰) std::cout << "생성자(size_t) - " << num << ", " << this << std::endl;
}

STRING::~STRING()
{
	if (관찰) std::cout << "소멸자 - " << num << ", " << this << std::endl;
	delete[] p;
}

STRING::STRING(const STRING& other) : num{other.num}
{
	p = new char[num];
	memcpy(p, other.p, num);
	if (관찰) std::cout << "복사생성자 - " << num << ", " << this << std::endl;
}

STRING& STRING::operator=(const STRING& other)
{
	if (this == &other)
		return *this;
	delete[] p;
	num = other.num;
	p = new char[num];
	memcpy(p, other.p, num);
	if (관찰) std::cout << "복사할당연산자 - " << num << ", " << this << std::endl;
	return *this;
}

STRING::STRING(STRING&& other) : num{other.num}, p{other.p}
{
	other.num = 0;
	other.p = nullptr;
	if (관찰) std::cout << "이동생성자 - " << num << ", " << this << std::endl;
}

STRING& STRING::operator=(STRING&& other)
{
	if (this == &other)
		return *this;
	num = other.num;
	p = other.p;
	other.num = 0;
	other.p = nullptr;
	if (관찰) std::cout << "이동할당연산자 - " << num << ", " << this << std::endl;
	return *this;
}

STRING STRING::operator+(const char* s) const
{
	STRING temp{ num + strlen(s) };
	/*size_t temp_num = num + strlen(s);
	char* temp = new char[temp_num];*/
	
	memcpy(temp.p, p, num);
	memcpy(temp.p + num, s, strlen(s));
	return temp;
}

char STRING::operator[] (size_t idx) const
{
	return p[idx];
}

char& STRING::operator[](size_t idx)
{
	return p[idx];
}


size_t STRING::size() const
{
	return num;
}

STRING operator+(const char* s, const STRING& other)
{
	STRING temp{ other.num + strlen(s) };

	memcpy(temp.p, s, strlen(s));
	memcpy(temp.p + strlen(s), other.p, other.num);
	return temp;
}

std::ostream& operator<<(std::ostream& os, const STRING& output)
{
	for (int i = 0; i < output.num; i++)
	{
		os << output.p[i];
	}
	//os << output.p;
	return os;
}
//ostream은 const가 절대 불가 하다. 프로그램이 진행되면서 계속 변하기 때문에 
//ostream은 멋대로 작명하지 않도록 할것, os로 할것
