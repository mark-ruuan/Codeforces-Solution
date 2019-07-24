#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	map<char, int> mp;
	mp['s'] = 0;
	mp['p'] = 1;
	mp['m'] = 2;
	std::vector<int> v[4];
	string s, s1, s2;
	cin >> s >> s1 >> s2;
	if(s == s1 && s1 == s2) return cout << 0, 0;
	if((s == s1) || (s == s2) || (s1 == s2)) return cout << 1, 0;
	v[mp[s[1]]].push_back(s[0] - '0');
	v[mp[s1[1]]].push_back(s1[0] - '0');
	v[mp[s2[1]]].push_back(s2[0] - '0');
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	sort(v[2].begin(), v[2].end());
	//for(auto i: v[0]) cout << i << " ";
	for(int i = 1; i <= 7; i++){
		if(v[0].size() == 3){
			if(v[0][0] == i && v[0][1] == i + 1 && v[0][2] == i + 2)
				return cout << 0, 0;
			if((v[0][2] - v[0][1] <= 2) || (v[0][1] - v[0][0] <= 2))
				return cout << 1, 0;
		}
		if(v[1].size() == 3){
			if(v[1][0] == i && v[1][1] == i + 1 && v[1][2] == i + 2)
				return cout << 0,0;
			if((v[1][2] - v[1][1] <= 2) || (v[1][1] - v[1][0] <= 2))
				return cout << 1, 0;
		}
		if(v[2].size() == 3){
			if(v[2][0] == i && v[2][1] == i + 1 && v[2][2] == i + 2)
				return cout << 0,0;
			if((v[2][2] - v[2][1] <= 2) || (v[2][1] - v[2][0] <= 2))
				return cout << 1, 0;
		}
		if(v[0].size() == 2){
			if(v[0][0] == i && v[0][1] == i + 2)
				return cout << 1, 0;
		}
		if(v[1].size() == 2){
			if(v[1][0] == i && v[1][1] == i + 2)
				return cout << 1, 0;
		}
		if(v[2].size() == 2){
			if(v[2][0] == i && v[2][1] == i + 2)
				return cout << 1, 0;
		}
	}
	//cout << "yo" << endl;
	for(int i = 1; i <= 8; i++){
		if(v[0].size() == 2){
			if(v[0][0] == i && v[0][1] == i + 1)
				return cout << 1, 0;
		}
		if(v[1].size() == 2){
			if(v[1][0] == i && v[1][1] == i + 1)
				return cout << 1, 0;
		}
		if(v[2].size() == 2){
			if(v[2][0] == i && v[2][1] == i + 1)
				return cout << 1, 0;
		}
	}
	cout << 2;
	//cout << "yo" <<endl;
	return 0;
}
