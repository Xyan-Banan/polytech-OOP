#include <string>
#include <set>
#include <algorithm>

using namespace std;

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
