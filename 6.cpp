#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

template <size_t N>
void splitString(string (&arr)[N], string str)
{
    int n = 0;
    istringstream iss(str);
    for (auto it = istream_iterator<string>(iss); it != istream_iterator<string>() && n < N; ++it, ++n)
        arr[n] = *it;
}

char letter(int n)
{
    if(n >= 1 && n <= 26)
    return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n-1];
}

bool isNum ( char c ) {
	bool yes = false;
	switch(c) {
		case '0' ... '9':
			yes = true;
	}
	return yes;
}

enum charTypeT{ other, alpha, digit};

charTypeT charType(char c){
    if(isdigit(c))return digit;
    if(isalpha(c))return alpha;
    return other;
}

bool is_number(const std::string& s)
{
    return !s.empty() && find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !isdigit(c); }) == s.end();
}

bool isIn(char d, string a) {
	bool yes = false;
	for(auto b : a) {
		if(b == d) yes = true;
	}
	return yes;
}

string separateThem(string inString, int& ocunt){
  string oString = "";charTypeT st=other;
    for(auto c:inString){
        if( (st==alpha && charType(c)==digit) || (st==digit && charType(c)==alpha) || (c == '&') || (c == '%') ) {
		
          oString.push_back(' ');
          ocunt++;
      }
        oString.push_back(c);st=charType(c);
    }
    return oString;
}

int main() {
	ifstream file;
	file.open("input2.txt");
	string line;
	string a = "";
	while(getline(file, line)) {
		if(line.empty()) continue;
		else a += line;
	}
	cout << a << endl<<endl;
	string full = "";
	for(auto b : a) {
		if(b == ' ') continue;
		else full += b;
	}
	int count = 0;
	string arr[109];
	full = separateThem(full, count);
	splitString(arr, full);
	cout << full << endl ;
	cout<<count;
	string ans = "";
	for(string f : arr) {
		if(f == " ") continue;
		else if(atoi(f.c_str()) <= 0 && is_number(f)) ans += "o";
		else if(atoi(f.c_str()) > 0 && atoi(f.c_str()) < 27 && is_number(f)) ans += letter(atoi(f.c_str()));
		else if(atoi(f.c_str()) > 26 && atoi(f.c_str()) % 2 == 0 && is_number(f)) ans += "&";
		else if(atoi(f.c_str()) > 26 && atoi(f.c_str()) % 2 != 0 && is_number(f)) ans += "%"; 
		else ans += f;
	}
	cout << endl << ans << endl;
	string final = "";
	for(auto m: ans) {
		if(isIn(m, final)) continue;
		else final += m;
	}
	cout << endl << final << endl;
}
