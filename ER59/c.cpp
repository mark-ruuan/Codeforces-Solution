 /*
    __                      _    _            __                 __
   / /_/\__        __ _    | | _| | __     _  \ \       __/\__  / /
  / /\    /       / _` |   | |/ / |/ /    (_)  | |      \    / / / 
 / / /_  _\      | (_| |   |   <|   <      _   | |      /_  _\/ /  
/_/    \/         \__,_|___|_|\_\_|\_\    (_)  | |        \/ /_/   
                      |_____|                 /_/                  

*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

priority_queue <ll, vector<ll>, greater<ll> > pq[27]; 
ll a[N];
int main(){
	fast;
	ll n, k, sum = 0;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	string s;
	cin >> s;
	s += '#';
	char prev = '#';
	for(int i = 0; i <= n; i++){
		if(prev != s[i] && prev != '#'){
			while(pq[prev - 'a'].size() > k){
				pq[prev - 'a'].pop();
			}
			while(pq[prev - 'a'].size()){
				sum += pq[prev - 'a'].top();
				pq[prev - 'a'].pop();
			}

		}
		if(s[i] != '#')
			pq[s[i] - 'a'].push(a[i]);
		prev = s[i];
	}
	cout << sum;


	
	return 0;
}
