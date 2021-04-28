/*
(2)
Busy Man - https://www.spoj.com/problems/BUSYMAN/
*/

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> p1 , pair<int, int> p2) {
	return p1.second < p2.second;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t, n, s, e;
	cin >> t;

	vector<pair<int, int> > v;

	while (t--) {

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s >> e;
			v.push_back(make_pair(s, e));
		}

		//activity selection algorithm

		//1. sort acc to the end time
		sort(v.begin(), v.end(), cmp);

		//2.start picking activities
		int res = 1; //we will always pick first activity
		int finishTime = v[0].second;

		//iterate over remaining activities
		for (int i = 1; i < n; i++) {
			if (v[i].first >= finishTime) {
				res++;
				finishTime = v[i].second;
			}
		}
		cout << res << endl;
		v.clear();
	}

	return 0;
}