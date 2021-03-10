#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void processSpaces(string& str);

int main()
{
	cout << "Hello World!\n";
	string fileName = "text.txt";
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

	cout << text << endl;

	processSpaces(text);
	cout << text << endl;
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
