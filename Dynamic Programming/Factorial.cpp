#include <iostream>
#include <algorithm>
using namespace std;
int Factorial(int n){
	if (n==0) return 1;
	else return Factorial(n-1)*n;
}
int main(){
	int n;
	cin>>n;
	int Fact[n];
	Fact[0]=1;
	Fact[1]=1;
	for(int i=2;i<=n;i++) Fact[i] = i * Fact[i-1]; //DP
	cout<<Fact[n]<<endl;
	cout<<Factorial(n)<<endl;
}