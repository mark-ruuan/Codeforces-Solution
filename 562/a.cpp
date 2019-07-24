/*
Yea, those will be the days that I will be missing
	When I’m old and when I’m gray and when I stop working
I hope that I can say
	When all my days are done
That I had my fun!!!!!!!
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	int n, a, x, b, y;
	cin >> n >> a >> x >> b >> y;
	for(int i = a, j = b ; ; i++, j--){
		if(i == n + 1) i =  1;
		if(j == 0) j = n;
		if(i == j) return cout << "YES", 0;
		if(i == x || j == y) break;
	}
	cout << "NO";


	return 0;
}

