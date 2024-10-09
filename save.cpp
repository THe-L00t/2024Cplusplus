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
	// ���޵� inFileName�� �б� ���� ���� ->> ���� ���� ���� ���� 
	std::ifstream in{ inFileName }; // {} - uniform initializer 


	//������ ������ ���� ���� ����
	std::ofstream out{ "2024 2 C++ ������.txt", std::ios::app };

	//������ �ð��� ����Ѵ�. 
	auto now = std::chrono::system_clock::now();
	using namespace std::literals;
	now += 9h;

	out << '\n' << '\n';
	out << "=====================================================" << std::endl;
	out << "����ð�:" << now << std::endl;
	out << "=====================================================" << std::endl;
	out << '\n';

	//���� ���Ͽ��� �� ���ڸ� �о� �� ���Ͽ� ����.
	char c;
	in >> std::noskipws;
	while (in >> c)
		out << c;

}