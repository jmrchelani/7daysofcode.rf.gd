#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int EZ = 15000; // arbitraly saved it so i can find it till this or not
	long long res[EZ];
	res[0] = 0;
	res[1] = 0;
	for(int i = 1; i < EZ; i ++) { // i could use two loops but it will take long time so this is fast
		res[i] = res[i-1] + i;
	}

	int n = 0, save;
	for(int i = 0; i < EZ; i++) {
		n = res[i];
		int count = 0;
		for (int i=1; i<=sqrt(n); i++) 
		{ 
		    if (n%i == 0) 
		    { 
		        if (n/i == i) 
		            count += 1;
		        else 
		            count += 2;
		    } 
		} 
		if(count > 500) {
			save = i;
			break;
		}
	}
	
	cout << res[save];
	
}


