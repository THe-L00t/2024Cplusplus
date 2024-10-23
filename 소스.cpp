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
#include <Windows.h>
#include <mmsystem.h>


#include "save.h"

#pragma comment( lib, "winmm.lib")

class Dog {
	//멤버 변수를 바깥에 공개하는 것이 유리하면 struct 
	//멤버 변수를 공개하지 않는 것이 맞다면 class
private:		//default access-modifier
	std::string name{}; //32바이트
	int age{};	//4바이트

public: //싱글턴 공부하기, private에 생성자 넣지 않도록 하기 
	Dog() {	//생성자만 오버로딩 가능
		PlaySound(L"개소리.wav",NULL,SND_SYNC);
		std::cout << "소리남" << std::endl;
	}
	Dog(std::string name) : name{ name } { std::cout << this->name <<"소리남" << std::endl; }
	Dog(int age) : age{ age } {}
	Dog(std::string name, int age) : name{ name }, age{ age } {}
	~Dog() {
		PlaySound(L"죽는소리.wav", NULL, SND_SYNC);
		std::cout << name << "죽는소리 남" << std::endl;
	}
};

int main()
{	
	Dog dog("1");
	{	//지역 객체의 life cycle
		Dog dog("2");
	}
	
	(*save)("소스.cpp");//정석 함수 호출
}

