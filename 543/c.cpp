#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
#define MAN(x, y) (x) > (y)?(x):(y);

class Test {
public:
	Test(){
		cout << "yo\n";
	}
	~Test(){
		cout << "yo 1\n";
	}
};



int main(){
	fast;
	int num[] = {1, 4, 8, 12, 16};
	int *a, *b;
	int i;
	a = num;
	b = num + 2;
	i = *a++;
	cout << i << *a << *b;
	return 0;
}

