using System.Collections.Generic;
using System;

public delegate int Func(int x);
public class Solution{
	public static List<int> TortoiseHare(Func f,int xo){
		int tortoise = f(xo);
		int hare = f(f(xo));
		while(tortoise!=hare){
			tortoise = f(tortoise);
			hare = f(f(hare));
		}

		//Detect Cycle period
		List<int> ans = new List<int>();
		ans.Add(0);
		ans.Add(1);

		tortoise = xo;
		while(tortoise!=hare){
			tortoise = f(tortoise);
			hare = f(hare);
			ans[0]++;
		}

		hare = f(tortoise);
		while(tortoise!=hare){
			hare = f(hare);
			ans[1]++;
		}
		return ans;
	}
	public static void Main(string[] args){
		List<int> ans = TortoiseHare(delegate (int x){return ((3*x*x + 7*x + 5) % 97);},62);
		Console.WriteLine("mu "+ans[0]+ " , lambda "+ans[1]);
	}
}