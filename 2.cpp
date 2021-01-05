#include <iostream>
using namespace std; 

#define MAX 500 
  
int multiply(int x, int res[], int res_size); 
  
int sumOfFactorial(int n) 
{ 
    int res[MAX]; 
  
    res[0] = 1; 
    int res_size = 1; 
    int sum = 0;
  
    for (int x=2; x<=n; x++) 
        res_size = multiply(x, res, res_size); 
  
    cout << "Factorial of given number is \n"; 
    for (int i=res_size-1; i>=0; i--) 
        cout << res[i]; 
    for (int i=res_size-1; i>=0; i--) 
        sum += res[i]; 
    return sum;
} 
  
int multiply(int x, int res[], int res_size) 
{ 
    int carry = 0;  // Initialize carry 
  
    for (int i=0; i<res_size; i++) 
    { 
        int prod = res[i] * x + carry; 
  
        res[i] = prod % 10;   
  
        carry  = prod/10;     
    } 
  
    while (carry) 
    { 
        res[res_size] = carry%10; 
        carry = carry/10; 
        res_size++; 
    } 
    return res_size; 
} 
  
int main() 
{ 
    cout<< "\nSum of all the digits in factorial of 100 is: "<< sumOfFactorial(100) << endl;
    return 0; 
} 
