#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int pre[N], suff[N];

vector<int> kmp(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


int main(){
	fast;
	string s;
	cin >> s;
	int nn = (int)s.size();
	int n;
	int ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		memset(pre, 0, sizeof pre);
		memset(suff, 0, sizeof suff);
		string ss;
		cin >> ss;
		int m = (int)ss.size();
		vector<int> kp = kmp(ss);
		int pt = 0, pt1 = 0;
		while(pt < m && pt1 < nn){
			if(s[pt1] == ss[pt]){
				//cout << pt1  << " " << pt << "\n";
				if(!pre[pt]) pre[pt] = pt1 + 1;
				pt++;
				pt1++;
			}
			else{
				if(pt == 0) pt1++;
				pt = kp[max(0, pt - 1)];
			}
			
		}
		reverse(ss.begin(), ss.end());
		vector<int> kpp = kmp(ss);
		pt1 = nn, pt = 0;
		while(pt < m && pt1 >= 0){
			if(s[pt1] == ss[pt]){
				if(!suff[pt]) suff[pt] = pt1 + 1;
				pt++;
				pt1--;
			}
			else{
				if(pt == 0) pt1--;
				pt = kpp[max(0, pt - 1)];
			}
			
		}
		/*for(int i = 0; i < m; i++) cout << pre[i] << " ";
			cout << "\n";
		for(int i = 0; i < m; i++) cout << suff[i] << " ";
			cout << "\n";*/
		for(int i = 0; i < m; i++){
			//cout << pre[i] << " " << suff[m - i - 2] << "\n";
			if(pre[i] && suff[m - i - 2] && pre[i] < suff[m - i - 2]){
				ans++;
				break;
			}
		}
	}
	cout << ans;
	
	return 0;
}
