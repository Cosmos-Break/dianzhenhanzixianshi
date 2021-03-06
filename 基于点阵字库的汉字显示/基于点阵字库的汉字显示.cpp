// 基于点阵字库的汉字显示.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<fstream>
#include<string>
using namespace std;


int main()
{
	ifstream infile("HZK16", ios::binary);
	unsigned char str[3];
	str[0] = 0xB0;
	str[1] = 0xA1;
	str[2] = '\0';
	char zi[32];
	unsigned int order = str[1] - 0xA1 + 94 * (str[0] - 0xB0) + 15 * 94;
	unsigned int position = order * 32;
	infile.seekg(position);
	infile.read(zi, sizeof(zi));
	cout << str << endl;
	int count = 0;
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 8; j++) {
			if (((zi[i] >> (7 - j)) & 0x01) == 1) {
				cout << "**";
			}
			else {
				cout << "  ";
			}
			count++;
			if (count == 16) {
				cout << endl;
				count = 0;
			}
		}
	}
	infile.close();	
	infile.open("HZK48S", ios::binary);
	order = str[1] - 0xA1 + 94 * (str[0] - 0xB0);
	position = order * 288;
	char zi2[288];
	infile.seekg(position);
	infile.read(zi2, sizeof(zi2));
	count = 0;
	for (int i = 0; i < 288; i++) {
		for (int j = 0; j < 8; j++) {
			if (((zi2[i] >> (7 - j)) & 0x01) == 1) {
				cout << "**";
			}
			else {
				cout << "  ";
			}
			count++;
			if (count == 48) {
				cout << endl;
				count = 0;
			}
		}
	}
	infile.close();
	return 0;
}
