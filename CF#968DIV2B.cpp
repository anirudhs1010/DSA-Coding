// Source: https://codeforces.com/contest/2003/problem/B

#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;

	cin >> a;
	vector<int> v;
	for (int i = 0; i < a; i++) {
		cin >> b;
		v.resize(b);
		for (int j = 0; j < b; j++) 
			cin >> v[j];
		sort(v.begin(), v.end());
		cout << v[v.size()/2] << endl;
	}
	return 0;
}
