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
	delete[] p;
	num = other.num;
	p = new char[num];
	memcpy(p, other.p, num);
	if (관찰) std::cout << "복사할당연산자 - " << num << ", " << this << std::endl;
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

char* STRING::get() const
{
	return p;
}

size_t STRING::size() const
{
	return num;
}

std::ostream& operator<<(std::ostream& cout, STRING& output)
{
	cout << output.get();
	return cout;
}
