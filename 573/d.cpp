#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int a[N];
set<int> st;
int main(){
	fast;
	int n;
	cin >> n;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		st.insert(a[i]);
		sum += a[i];
	}
	if(n == 1){
		if(a[0] % 2 == 0) return cout << "cslnb", 0;
		else return cout << "sjfnb", 0;
	}
	if(st.size() == n){
		if(sum % 2 == 0) return cout << "sjfnb", 0;
		else return cout << "cslnb", 0;
	}
	else if(n - st.size() == 1){
		sort(a, a + n);
		int pos;
		for(int i = 0; i < n - 1; i++){
			if(a[i] == a[i + 1]){
				pos = i;
				break;
			}
		}
		if(a[pos] == 0) return cout << "cslnb", 0;
		a[pos]--;
		sum = 0;
		for(int i = 0; i < n - 1; i++){
			if(a[i] == a[i + 1]) return cout << "cslnb", 0;
			sum += a[i];
		}
		if(sum % 2 == 0) return cout << "cslnb", 0;
		else return cout << "sjfnb", 0;
	}
	else
		return cout << "cslnb", 0;
	
	return 0;
}
