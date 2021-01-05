#include <iostream>
using namespace std;

int main() {
	
	for(int i = 0; i < 1000; i++) {
		for(int j = i+1; j < 1000; j++) {
			int k = 1000 - i - j;
			if((i*i + j*j == k*k) && (i+j+k == 1000) && (i < j && j < k)) cout << i *j*k <<endl;
		}
	}
	
}
