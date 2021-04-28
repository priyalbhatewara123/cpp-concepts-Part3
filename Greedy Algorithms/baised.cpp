/*
(3)
BAISED - Baised Standings
https://www.spoj.com/problems/BAISED/
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[1000000] = {0};

	int t; cin >> t;
	while (t--) {
		memset(arr, 0, sizeof(arr));

		int n; cin >> n;
		string name;
		int preferredRank;
		for (int i = 1; i <= n; i++) {
			cin >> name >> preferredRank;
			arr[preferredRank] ++ ;
		}

		//Greedy approach - assign each team nearest rank available
		int actualRank = 1;
		int badness = 0;
		for (int i = 1; i <= n; i++) {

			while (arr[i]) {
				badness += abs(i - actualRank);
				arr[i]--;
				actualRank++;
			}
		}

		cout << badness << endl;
	}

	return 0;
}



/*
Approach 1
We can sort the preferred rankings in O(NlogN) time and then find the difference between
preferred and alloted ones to find the badness.

Approach 2
We can use something similar to counting sort.
This approach uses O(n) time.
*/