#include <iostream>
using namespace std;

string encryptIt(string msg, int key) {
	char ch;
	int i;
	
	for(i = 0; i < msg.length(); ++i){
		ch = msg[i];
		
		if(ch >= 'a' && ch <= 'z'){
			ch = ch + key;
			
			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}
			
			msg[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;
			
			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}
			
			msg[i] = ch;
		}
	}
	return msg;
}

int getIt(char a) {
	return (int)a - 97;
}

bool isNum(char c) {
	bool yes = false;
	switch(c) {
		case '0' ... '9':
			yes = true;
	}
	return yes;
}

int main() {
	string a = "21bcdfghjklnprstvwy0123456789";
	a = encryptIt(a, 4);
	string ans = "";
	for(auto x : a) {
		if(isNum(x)) ans += x;
		else ans+= to_string(getIt(x));
	}
	cout << ans;
}
