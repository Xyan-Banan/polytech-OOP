/*
Разработать программу, которая должна сделать следующее:
1.	Прочитать содержимое текстового файла. Файл может содержать:
a.	Слова – состоят из латинских строчных и заглавных букв, а также цифр, длинна слова должна быть не более 20 символов
b.	Знаки препинания – «.», «,» «!» «?» «:» «;»
c.	Пробельные символы – пробел, табуляция, символ новой строки.

2.	Отформатировать текст следующим образом:
a.	Не должно быть  пробельных символов отличных от пробела
b.	Не должно идти подряд более одного пробела
c.	Между словом и знаком препинания не должно быть пробела
d.	После знака препинания всегда должен идти пробел
e.	Слова длиной более 10 символов заменяются на слово «Vau!!!»

3.	Преобразовать полученный текст в набор строка, каждая из которых содержит целое количество строк (слово должно целиком находиться в строке) и ее длинна не превышает 40 символов.

*/

//Соколов Михаил
//22.03.2021

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void processText(string& str);
vector<string> fillVector(string& str);

int main()
{
	cout << "Hello World!\n";
	string fileName = "lab2-string.cpp";
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

	processText(text);
	cout << endl << "After formatting:" << endl;
	cout << text << endl;
	vector<string> resV = fillVector(text);

	cout << endl << "After splitting:" << endl;
	for (auto it = resV.begin(); it != resV.end(); it++) {
		cout << *it << endl;
	}
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
	//string::iterator it;
	//replace_if(str.begin(),str.end(), [](string::iterator it) {return *it == '\t' || *it == '\n'; }, ' ');

	if (str.empty()) {
		return;
	}

	replace_if(str.begin(), str.end(), [](char c) {return c == '\t' || c == '\n'; }, ' ');

	size_t pos;
	while ((pos = str.find("  ")) != string::npos) { //replace double spaces
		str.replace(pos, 2, " ");
		/*replace_if(str.begin(), str.end(), [](char& c) {
			if (c != '\0') {
				return (c == ' ' && *(&c + 1) == ' ');
			}
			return false;
		}, '');*/
	}

	string punctuators = ".,!?:;";
	for (int i = 0; i < punctuators.size(); i++) {//replace spaces before punctuators
		string substr = string(" ") + punctuators[i];
		while ((pos = str.find(substr)) != string::npos){
			str.replace(pos, 2, punctuators.substr(i, 1));
		}
	}

	for (auto it = str.begin(); it != str.end() - 1; it++) {//add spaces after punctuators
		if (punctuators.find(*it) != string::npos && isWord(*(it + 1))) {
			str.replace(it, it + 1, *it + string(" "));
		}
	}
}

void processLongWords(string& str) {
	size_t pos, start = 0;
	while ((pos = str.find(" ", start)) != string::npos) {
		auto length = pos - start;
		if (length > 10) {
			str.replace(start, length, "Vau!!!");
			length = 6;
		}
		start += length + 1;
	}
}

void processText(string& str) {
	processSpaces(str);
	processLongWords(str);
}

vector<string> fillVector(string& str) {
	vector<string> v;
	if (str.empty()) {
		return v;
	}

	size_t pos,start = 0;
	v.push_back("");
	while ((pos = str.find(" ",start)) != string::npos) {
		if (v.back().size() + (pos - start)<= 40)
			v.back() += str.substr(start, pos - start + 1);
		else {
			v.back().resize(v.back().size() - 1);
			v.push_back(str.substr(start, pos - start + 1));
		}
		start = pos + 1;
	}
	
	return v;
}