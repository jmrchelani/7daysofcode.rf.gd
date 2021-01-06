#include <iostream>
#include <fstream>
#include <string.h>
#include<sstream>
#include <algorithm>
using namespace std;

struct not_digit {
    bool operator()(const char c) {
        return c != ' ' && !std::isdigit(c);
    }
};

string getNumberFromString(string s) {
   string str(s);
    not_digit not_a_digit;
    string::iterator end = std::remove_if(str.begin(), str.end(), not_a_digit);
    string all_numbers(str.begin(), end);
    stringstream ss(all_numbers);
    string f = "";
    
    for(int i = 0; ss >> i; ) {
        f += to_string(i);
    }
   return f;
}

bool isIn(char a, string ok) {
	bool ye = false;
	for(auto b : ok) {
		if(b == a) ye = true;
	}
	return ye;
}

int main() {
	ifstream input;
	input.open("input1.txt");
	string line;
	int lcount = 0;
	int max = 0;
	while(getline(input, line)) {
		lcount++;
		if(line.empty()) continue;
		else max++;
	}
	string arr[max];
	int cnt = 0;
	input.close();
	input.open("input1.txt");
	while(getline(input, line)) {
		if(line.empty()) continue;
		for(auto& a: line) a = tolower(a);
		arr[cnt] = line;
		cnt++;
		cout << line << endl;
	}
	string ans = "";
	for(int i = 0; i < max; i++) {
		string ez = arr[i];
		
		for(auto a : ez) {
			if(a == 'a') ans += "11";
			else if(a == 'e') ans += "22";
			else if(a == 'i') ans += "33";
			else if(a == 'o') ans += "44";
			else if(a == 'u') ans += "55";
			else if(a == 'm') ans += "100";
			else if(a == ' ') continue;
			else ans += a;
		}
	}
	
	string fin = "";
	for(auto a : ans) {
		if(!isIn(a, fin)) fin+=a;
	}
	
	cout << fin ;
	string s = fin;
	string aaa = getNumberFromString(fin);
	s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalpha(c); } ), s.end());
	sort(s.begin(), s.end());
	string res = to_string(max) + s + aaa;
	
	cout<<lcount << "\t " << max << endl;
	cout << res << endl;
	cout << aaa;
}
