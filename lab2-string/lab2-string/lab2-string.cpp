#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void processSpaces(string& str);
vector<string> fillVector(string& str);

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

	cout << "Original text:" << endl;
	cout << text << endl;

	processSpaces(text);
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