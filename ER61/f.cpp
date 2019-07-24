#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll ans[N], ans1[N];
int main(){
	fast;
	ll n, lst[27] = {0}, lst1[27] = {0};
	cin >> n;
	string s, temp;
	cin >> s;
	stack<char> st;
	for(int i = 0; i < n; i++){
		if(st.empty()){
			st.push(s[i]);
			temp += s[i];
		}
		else if(st.top() != s[i]){
			st.push(s[i]);
			temp += s[i];
		}
	}
	//cout << temp << "\n";
	for(int i = 0; i < temp.size(); i++){
		lst[temp[i] - 'a'] = i;
	}
	while(!st.empty()) st.pop();
	ll ct = 0;
	for(int i = 0; i < temp.size(); i++){
		if(st.empty()) st.push(temp[i]);
		else if(st.top() != temp[i]) st.push(temp[i]);
		if(lst[temp[i] - 'a'] == i){
			stack<char> stt;
			ll ct1 = 0;
			while(!st.empty()){
				char ch = st.top();
				if(ch != temp[i]){
					ct1++; stt.push(ch);}
				else{
					ct++;
					if(ct1 == 1 && !stt.empty()) stt.pop();
					ct1 = 0;
				}
				st.pop();
			}
			while(!stt.empty()){
				if(st.empty()) st.push(stt.top());
				else if(st.top() != stt.top()) st.push(stt.top());
				stt.pop();
			}

		}
		ans1[i] = ct;
	}
	for(int i = (int)temp.size() - 1; i >= 0; i--){
		lst1[temp[i] - 'a'] = i;
	}
	while(!st.empty()) st.pop();
	ll ct2 = 0;
	for(int i = (int)temp.size() - 1; i >= 0; i--){
		if(st.empty()) st.push(temp[i]);
		else if(st.top() != temp[i]) st.push(temp[i]);
		if(lst1[temp[i] - 'a'] == i){
			stack<char> stt;
			ll ct1 = 0;
			while(!st.empty()){
				char ch = st.top();
				if(ch != temp[i]){
					ct1++; stt.push(ch);}
				else{
					ct2++;
					if(ct1 == 1 && !stt.empty()) stt.pop();
					ct1 = 0;
				}
				st.pop();
			}
			while(!stt.empty()){
				if(st.empty()) st.push(stt.top());
				else if(st.top() != stt.top()) st.push(stt.top());
				stt.pop();
			}

		}
		ans[i] = ct2;
	}
	//cout << ct2 << "\n";
	//cout << min(ct, ct2);
	ll out = 1e18;
	for(int i = 0; i < temp.size(); i++){
		out = min(out, ans1[i] + ans[i]);
		cout << ans1[i] << " " << ans[i] << "\n";
	}
	//out = min(out, ans1[0]);
	cout << out << "\n";

	
	return 0;
}

