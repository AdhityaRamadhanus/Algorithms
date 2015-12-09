#include <iostream>
using namespace std;
int f(int x){
	return (3*x*x + 7*x + 5) % 97;
}
pair<int,int> FloydTortoise(int (*f)(int),int xo){
	int tortoise = f(xo);
	int hare = f(f(xo));
	while(tortoise!=hare){
		tortoise = f(tortoise);
        hare = f(f(hare));
	}

	pair<int,int> ans = make_pair(0,1);
	tortoise = xo;
	while(tortoise!=hare){
		tortoise = f(tortoise);
		hare = f(hare);
		ans.first++;
	}

    hare = f(tortoise);
    while(tortoise!=hare){
    	hare = f(hare);
    	ans.second++;
    }
    return ans;
}
int main(){
	pair<int,int> ans = FloydTortoise(f,62);
	cout<<ans.first<<" "<<ans.second<<endl;
}