#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll type[N];
stack<ll> zero, both, clown, acro;
deque<ll> first, sec;


void calc(){
	while(zero.size() >= 2){
		first.push_back(zero.top());
		zero.pop();
		sec.push_back(zero.top());
		zero.pop();

	}
	while(both.size() >= 2){
		first.push_back(both.top());
		both.pop();
		sec.push_back(both.top());
		both.pop();
	}
	if(both.size()){
		if(first.size() && type[first.front()] == 2){
			sec.push_back(first.front());
			first.pop_front();
			first.push_back(both.top());
			first.push_back(zero.top());
		}
		else if(sec.size() && type[sec.front()] == 1){
			first.push_back(sec.front());
			sec.pop_front();
			sec.push_back(both.top());
			first.push_back(zero.top());
		}
		else{
			cout << -1;
			exit(0);
		}
	}
}

int main(){
	fast;
	ll n;
	cin >> n;
	string s, ss;
	cin >> s >> ss;
	for(int i = 0; i < n; i++){
		if(s[i] == '0' && ss[i] == '0'){
			zero.push(i);
		}
		else if(s[i] == '1' && ss[i] == '1'){
			both.push(i);
		}
		else if(s[i] == '1'){
			clown.push(i);
			type[i] = 1;
		}
		else{
			acro.push(i);
			type[i] = 2;
		}
	}
	while(!acro.empty()){
		first.push_back(acro.top());
		acro.pop();
	}
	while(!clown.empty()){
		sec.push_back(clown.top());
		clown.pop();
	}
	if(first.size() > sec.size()){
		while(sec.size() != first.size() && zero.size()){
			sec.push_back(zero.top());
			zero.pop();
		}
		if(sec.size() < first.size()){
			ll ct = first.size() - sec.size() ;
			while(ct--){
				sec.push_back(first.back());
				first.pop_back();
			}
			while(first.size() < sec.size() && both.size()){
				first.push_back(both.top());
				both.pop();
			}
			if(sec.size() > first.size()){
				return cout << -1, 0;
			}
			else{
				calc();
			}

		}
		else{
			calc();
		}

	}
	else if(first.size() < sec.size()){
		while(sec.size() != first.size() && zero.size()){
			first.push_back(zero.top());
			zero.pop();
		}
		if(first.size() < sec.size()){
			ll ct = sec.size() - first.size();
			while(ct--){
				first.push_back(sec.back());
				sec.pop_back();
			}
			while(sec.size() < first.size() && both.size()){
				sec.push_back(both.top());
				both.pop();
			}
			if(first.size() > sec.size()){
				return cout << -1, 0;
			}
			else{
				calc();
			}
			
		}
		else calc();
	}
	else calc();
	for(auto i: first) cout << i + 1 << " ";
		/*cout << "\n";
	for(auto i: sec) cout << i + 1 << " ";*/

	
	return 0;
}