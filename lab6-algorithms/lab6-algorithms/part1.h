/*
1.	Ќаписать программу, котора€ выполн€ет следующие действи€:
a.	„итает содержимое текстового файла
b.	¬ыдел€ет слова, словом считаютс€ последовательность символов разделенных пробелами и/или знаками табул€ции и/или символами новой строки
c.	¬ывести список слов присутствующий в тексте без повторений (имеетс€ в виду, что одно и то же слово может присутствовать в списке только один раз)
*/

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

set<string> destructText(string& str);
void processSpaces(string& str);

int part1() {
	string fileName = "part1.h";
	ifstream file;
	file.open(fileName);
	if (!file) {
		cout << "Cannot open file " << fileName << endl;
		return -1;
	}

	string text;
	stringstream buff;
	buff << file.rdbuf();
	text = buff.str();

	cout << "Original text:" << endl;
	cout << text << endl;
	processSpaces(text);

	set<string> wordSet = destructText(text);
	cout << "_____________________________________" << endl;
	cout << "Word set:" << endl;
	for (auto it = wordSet.begin(); it != wordSet.end(); it++) {
		cout << *it << endl;
	}
	return 0;

}

set<string> destructText(string& str) {
	size_t pos, start = 0;
	set<string> s;
	while ((pos = str.find(" ", start)) != string::npos) {
		s.insert(str.substr(start, pos - start));
		start = pos + 1;
	}
	return s;
}

bool isDigit(char c) {
	return (c >= 48) && (c <= 57);
}

bool isLetter(char c) {
	return ((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122));
}

bool isWord(char c) {
	return isDigit(c) || isLetter(c);
}

void processSpaces(string& str) {
	if (str.empty()) {
		return;
	}

	replace_if(str.begin(), str.end(), [](char c) {return c == '\t' || c == '\n'; }, ' ');

	size_t pos;
	while ((pos = str.find("  ")) != string::npos) { //replace double spaces
		str.replace(pos, 2, " ");
	}

	string punctuators = ".,!?:;";
	for (int i = 0; i < punctuators.size(); i++) {//replace spaces before punctuators
		string substr = string(" ") + punctuators[i];
		while ((pos = str.find(substr)) != string::npos) {
			str.replace(pos, 2, punctuators.substr(i, 1));
		}
	}

	for (auto it = str.begin(); it != str.end() - 1; it++) {//add spaces after punctuators
		if (punctuators.find(*it) != string::npos && isWord(*(it + 1))) {
			str.replace(it, it + 1, *it + string(" "));
		}
	}
}

