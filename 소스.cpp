//--------------------------------------------------------------------------------------
//    2024. 2학기 10.24 목                        수78목78                        (8주 1)
//
// 참고 -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(목) - 9주 1일차 - 중간 시험
//--------------------------------------------------------------------------------------
// special member - 디폴트 생성자 / 소멸자
//					복사생성자/복사할당연산자
//					이동생성자/이동할당연산자
//--------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>


#include "save.h"

#pragma comment( lib, "winmm.lib")

class Dog {
	
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
	std::cout << "메인 시작 전" << std::endl;

	Dog* pD = new Dog;

	//delet[] pD; 프로그램 사망함. 할당과 해제의 짝을 맞출것
	delete(pD);
	(*save)("소스.cpp");//정석 함수 호출
	std::cout << "main end" << std::endl;
}

