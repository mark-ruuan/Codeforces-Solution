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

std::vector<ll> ans;
bool visit[N];
set<ll> st, v[N];

void dfs(ll node){
	visit[node] = 1;
	ans.push_back(node);
	for(auto i: v[node]){
		if(!visit[i])
			st.insert(i);
	}
	while(!st.empty()){
		ll i =  *st.begin();
		if(!visit[i]){
			if(st.find(i) != st.end())
			st.erase(st.find(i));
			dfs(i);
		}
		else{
			if(st.find(i) != st.end()){
				st.erase(st.find(i));
			}
		}
	}
}

int main(){
	fast;
	ll n, m, x, y;
	cin >> n >> m;
	for(int  i = 0; i < m; i++)
	{
		cin >> x >> y;
		v[x].insert(y);
		v[y].insert(x);
	}
	
	dfs(1);
	for(auto i: ans) cout << i << " ";
	return 0;
}
