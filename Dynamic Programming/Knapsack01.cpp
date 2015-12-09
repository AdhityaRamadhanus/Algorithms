#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int Knapsack(vector<pair<int,int> > objects,int w,int i){ //Recursive
	if (i==objects.size()){ //Base case, only one object
		return 0;
	}
	else{
		if (objects[i].first<=w){
			return max(objects[i].second + Knapsack(objects,w-objects[i].first,i+1),Knapsack(objects,w,i+1)); 
		}
		else return Knapsack(objects,w,i+1);
	}
}
int main(){
	vector<pair<int,int> > test;
	test.push_back(make_pair(10,100));
	test.push_back(make_pair(4,70));
	test.push_back(make_pair(6,50));
	test.push_back(make_pair(12,100));
	int w=12,obj=4;
	int DP[obj+1][w+1];
	memset(DP,0,sizeof(DP));
	//Dynamic Programming
	for(int i=0;i<=obj;i++){
		for(int j=0;j<=w;j++){
			if (j==0 || i==0) DP[i][j]=0;
			else if (test[i-1].first<=j) DP[i][j] = max(test[i-1].second + DP[i-1][j-test[i-1].first],DP[i-1][j]);
			else DP[i][j] = DP[i-1][j];
		}
	}
	cout<<Knapsack(test,w,0)<<endl;
	cout<<DP[obj][w]<<endl;
}