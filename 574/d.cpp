#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
int cc, bb, aa;
int a[N];
int go(int idx, int val, int pre){
	if(idx == n) return 0;
	if(a[idx] <= val){
		if(pre == 2) return 3 + go(idx + 1, val, 1);
		else return 1 + go(idx + 1, val, pre);
	}
	else{
		if(pre == 1) return 3 + go(idx + 1, val , 2);
		else return 1 + go(idx + 1, val, pre);
	}
}

int main(){
	cin >> cc >> bb >> aa;
	cin >> n;
	int res = 1e9 + 5;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = bb - 1; i <= aa; i++){
		int x = go(0, i, 1);
		int y = go(0, i, 2);
		res = min(res, min(x, y));
	}
	cout << res;
}

