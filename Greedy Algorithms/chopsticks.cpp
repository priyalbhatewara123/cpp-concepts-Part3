/*
(6)
CHOPSTICKS - https://www.codechef.com/problems/TACHSTCK
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	// your code goes here
	ll N, D; cin >> N >> D;
	ll L[100000];
	for (int i = 0; i < N; i++)
	{
		cin >> L[i];
	}
	sort(L , L + N);
	ll ans = 0;
	for (int i = 0; i < N - 1;) {
		int diff = L[i + 1] - L[i];
		if (diff <= D) {
			ans++;
			i += 2;
		}
		else {
			i++;
		}
	}
	cout << ans;
	return 0;
}
