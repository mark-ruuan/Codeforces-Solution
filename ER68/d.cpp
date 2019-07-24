#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	int t;
	cin >> t;
	while(t--){
		ll x, y;
		cin >> x >> y;
		if(x == 0){
			cout << "Bob\n";
			continue;
		}
		if(y % 3 || x < y){
			if(x % 3 == 0) cout << "Bob\n";
			else cout << "Alice\n";
		}
		else{
			if(x == y) cout << "Alice\n";
			else{
				ll rem = x % (y + 1);
				if(rem == 0) cout << "Bob\n";
				else if(rem % 3 == 0){
					if((rem + 1) % (y + 1) == 0) cout << "Alice\n";
					else cout << "Bob\n";

				}
				else{
					cout << "Alice\n";
				}
			}
		}
	}
	
	return 0;
}
