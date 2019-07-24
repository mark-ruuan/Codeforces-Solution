import java.util.*;
import java.lang.*;

public class C{
	private static long gcd(long a, long b){
		if(a < b) return gcd(b, a);
		if(b == 0) return a;
		return gcd(b, a % b);
	}

	private static long lcm(long a, long b){
		return a / gcd(a, b) * b;
	}

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		long a = in.nextLong();
		long b = in.nextLong();
		if(a > b){
			a ^= b;
			b ^= a;
			a ^= b;
		}
		List<Long> factors = new ArrayList<Long>();
		long diff =  b - a;
		for(long i = 1; i * i <= diff; i++){
			if(diff % i == 0){
				factors.add(diff / i);
				if(diff / i != i){
					factors.add(i);
				}
			}
		}
		long mn = lcm(a, b), out = 0; 
		for(long f: factors){
			long add = f - (a % f);
			long ans = lcm(a + add, b + add);
			if(mn > ans){
				mn = ans;
				out = add;
			}
		}
		System.out.println(out);
		in.close();
	}
}