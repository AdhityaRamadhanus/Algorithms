#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int LIS(int* array,int n){
	if (n==0) return 1;
	else{
		int soln=1;
		for(int j=0;j<n;j++){
			if (array[n]>array[j]){
				soln=max(soln,1+LIS(array,j));
			} 
		}
		return soln;
	}
}
int main(){
	int array[]={-7,10,9,2,3,8,8,1};
	int soln=0;
	for(int i=0;i<8;i++){
		soln=max(soln,LIS(array,i));
	}
	int DP[8];
	memset(DP,0,sizeof(DP));
	DP[0]=1;
	for(int i=1;i<8;i++){
		for(int j=0;j<i;j++){
			if (array[j]<array[i]) DP[i]=max(DP[i],1+DP[j]);
		}
	}
	cout<<*max_element(DP,DP+8)<<endl;
	cout<<soln<<endl;
}