//----------------------------------------------
// 
// save.cpp 
//									2024.9.5
//
//----------------------------------------------

#include <iostream>
#include <print>
#include <fstream>
#include <chrono>
#include "save.h"

void save(const std::string& inFileName)
{
	// 전달된 inFileName을 읽기 모드로 연다 ->> 별로 좋지 않은 형식 
	std::ifstream in{ inFileName }; // {} - uniform initializer 


	//저장할 파일을 쓰기 모드로 연다
	std::ofstream out{ "2024 2 C++ 이태형.txt", std::ios::app };

	//저장한 시간을 기록한다. 
	auto now = std::chrono::system_clock::now();
	using namespace std::literals;
	now += 9h;

	out << '\n' << '\n';
	out << "=====================================================" << std::endl;
	out << "저장시간:" << now << std::endl;
	out << "=====================================================" << std::endl;
	out << '\n';

	//읽을 파일에서 한 글자를 읽어 쓸 파일에 쓴다.
	char c;
	in >> std::noskipws;
	while (in >> c)
		out << c;

}