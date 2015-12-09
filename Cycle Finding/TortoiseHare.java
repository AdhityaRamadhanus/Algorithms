import java.util.*;
interface Func{
	int compute(int x);
}
public class TortoiseHare{
	public static int[] TortoiseHare(Func f,int xo){
		int tortoise = f.compute(xo);
		int hare = f.compute(f.compute(xo));
		while(tortoise!=hare){
			tortoise = f.compute(tortoise);
			hare = f.compute(f.compute(hare));
		}

		//Detect Cycle period
		int[] ans = new int[2];
		ans[0] =0;
		ans[1] =1;
		tortoise = xo;
		while(tortoise!=hare){
			tortoise = f.compute(tortoise);
			hare = f.compute(hare);
			ans[0]++;
		}

		hare = f.compute(tortoise);
		while(tortoise!=hare){
			hare = f.compute(hare);
			ans[1]++;
		}
		return ans;
	}
	public static void main(String[] args){
		int[] ans = TortoiseHare(new Func(){
			public int compute(int x){
				return (3*x*x + 7*x + 5) % 97;
			}
		},62);
		System.out.println(ans[0]+" "+ans[1]);
	}
}