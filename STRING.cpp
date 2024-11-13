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
		if (관찰) std::cout << "생성자 - " << num << ", " << this << std::endl;
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

size_t STRING::size() const
{
	return num;
}
