//--------------------------------------------------------------------------------------
//    2024. 2�б� 9.24 ��                        ��78��78                        (6�� 2)
//
// ���� -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(��) - 9�� 1���� - �߰� ����
//--------------------------------------------------------------------------------------
// file I/O
//--------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <print>
#include <string>
#include <algorithm>

#include "save.h"

int main()
{
	//[����] ���� "����.cpp"�� �ִ� �ܾ 
	// �ܾ��� ���̸� �������� ������������ �����Ͽ� ����϶�
	// c++���� �ܾ��� ó���� std::string�� ����ϸ� �ȴ�
	//
	int cnt{};
	{
		std::ifstream in{ "�ҽ�.cpp" };
		if (not in) return 404;

		std::string str;
		while (in >> str) {
			++cnt;
		}
	}
	std::ifstream in{ "�ҽ�.cpp" };
	std::string* arr = new std::string[cnt];//string�� 32����Ʈ
	int i{ 0 };
	for (int i = 0; i < cnt; ++i) {
		in >> arr[i];
	}
	
	qsort(arr, cnt, sizeof(std::string), [](const void* a, const void* b) {
		const std::string* A = static_cast<const std::string*>(a);
		const std::string* B = static_cast<const std::string*>(b);
		return static_cast<int>(A->length() - B->length());
		});

	int c{ 0 };
	while (c<cnt) {
		std::cout << arr[c] << std::endl;
		++c;
	}

	(*save)("�ҽ�.cpp");//���� �Լ� ȣ��
}

