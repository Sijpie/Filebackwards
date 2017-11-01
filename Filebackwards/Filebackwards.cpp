// Filebackwards.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

#define FILE "D:\\HKU\\DEV\\OOP\\backwardsIN.txt"


int charMander() {
	char ch;

	std::ifstream in_stream;

	int count = 0;

	in_stream.open(FILE);
	if (!in_stream) {
		std::cout << "Probleem bij openen file" << std::endl;
		exit(13);
	}

	in_stream.get(ch);
	while (!in_stream.fail()) {
		count++;
		in_stream.get(ch);
	}
	in_stream.close();

	std::cout << count << " characters" << std::endl;

	//in_stream.close();
	return count;
}

char getCharizard(int n) {
	char ch;
	std::ifstream fileInput;

	fileInput.open(FILE);
	for (int i = 0; i < n; i++) {
		fileInput.get(ch);
	}
	fileInput.close();
	return ch;
}

int main()
{

	std::ofstream out_stream;
	out_stream.open("D:\\HKU\\DEV\\OOP\\backwardsOUT.txt");
	if (!out_stream) {
		std::cout << "Probleem bij openen out file" << std::endl;
		exit(1);
	} 

	

	int count;

	count = charMander();

	for (int n = count; n > 0; n--) {
		out_stream << getCharizard(n);
	}


	out_stream.close();
	

    return 0;
}

