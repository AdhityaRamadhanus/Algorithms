#include <iostream>
#include <algorithm>
using namespace std;
int Fibonacci(int n){
	if (n<=2) return 1;
	else return Fibonacci(n-1)+Fibonacci(n-2);
}
int main(){
	int n;
	cin>>n;
	int Fibo[n];
	Fibo[0]=1;
	Fibo[1]=1;
	for(int i=2;i<n;i++) Fibo[i] = Fibo[i-1]+Fibo[i-2];
	cout<<Fibo[n-1]<<endl;
	cout<<Fibonacci(n)<<endl;
}