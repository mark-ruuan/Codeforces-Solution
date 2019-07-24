#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	int n;
	cin >> n;
	char mx = 'E';
	//mx--;
	map<int, char> mp;
	mp[0] = 'D';
	mp[1] = 'A';
	mp[2] = 'C';
	mp[3] = 'B';
	int ans = 0;
	for(int i = 0; i <= 2; i++){
		int x = n + i;
		if(mp[(x % 4)] < mx){
			mx = mp[x % 4];
			ans = i;
		}
	}
	cout << ans << " " << mx;
	
	return 0;
}
