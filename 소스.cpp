//--------------------------------------------------------------------------------------
//    2024. 2�б� 9.24 ��                        ��78��78                        (6�� 2)
//
// ���� -  c++ core guideline 
//--------------------------------------------------------------------------------------
// 10.31(��) - 9�� 1���� - �߰� ���迹��
//--------------------------------------------------------------------------------------
// file I/O
//--------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <print>

#include "save.h"


int main()
{
	//[����] ���� "������ �.mp3"���� �� ������ �𸣴� int ����
	//����Ǿ� �ִ�.
	// �������� �����Ϸ� ȭ�� ����϶�
	// 
	int count{ 0 };
	{
		std::ifstream in{ "������ �.mp3" };
		if (not in) {		// ���� Ȯ�� �ʼ� 
			std::cout << "�ҷ����� ����" << std::endl;
			return 333;
		}

		int max{ -1 }, num;
		while (in >> num) {	//!in.eof() ������� �ʱ�  : in >> num ����ϱ� 

			++count;
			max = (max < num) ? num : max;
		}
	std::cout << "int�� ���� : " << count << std::endl << "���� ū �� : " << max << std::endl;
	}

	std::ifstream in{ "������ �.mp3" };
	int* arr = new int[count];
	int num, i{ 0 };
	while (in >> num) {
		arr[i] = num;
		++i;
	}
	qsort(arr, count, sizeof(int), [](const void* a, const void* b) {return *(int*)a - *(int*)b; });
	for (int j = 0; j < count; ++j) {
		std::print("{:16}", arr[j]);
	}

	(*save)("�ҽ�.cpp");//���� �Լ� ȣ��
}

