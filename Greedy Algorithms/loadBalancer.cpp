/*
(4)
BALIFE - Load Balancing
https://www.spoj.com/problems/BALIFE/
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[9000];

	int n, diff;
	while (1) {

		int rounds = 0, load = 0;
		cin >> n;

		//stop taking input if n = -1
		if (n == - 1)
			break;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			load += arr[i];
		}

		if (load % n != 0) {
			cout << -1 << endl;
			continue;
		}

		//find the load that has to be equally divided
		load = load / n;

		diff = 0;
		//greedy step
		for (int i = 0; i < n - 1; i++) {
			diff += (arr[i] - load);
			rounds = max(rounds , abs(diff));
		}

		cout << rounds << endl;
	}

	return 0;
}