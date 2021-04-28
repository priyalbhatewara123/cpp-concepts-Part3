/*
(7)
EXPEDI - Expedition
https://www.spoj.com/problems/EXPEDI/
*/

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1 , pair<int, int> p2) {
	return p1.first > p2.second;  //stop with greatest distance from town is nearer to truck
}

int main() {
	int flag = 0; int ans = 0;
	int t, n, d, f, D, F;

	cin >> t;

	while (t--) {
		vector < pair<int, int>> v; //to store distance and fuel of each stop
		priority_queue <int> pq; //to store fueling capacity of stops

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> d >> f;
			v.push_back(make_pair(d, f));
		}

		//sort according to there locations
		sort(v.begin(), v.end(), compare);

		cin >> D >> F;

		//update the distance of all fuel stations from truck
		for (int i = 0; i < n; i++) {
			v[i].first = D - v[i].first;
		}

		int prev = 0; //previous stop
		int x = 0; //current stop

		while (x < n) {

			//if we have enough fuel to go to next city
			if (F >= v[x].first - prev) {
				F = F - (v[x].first - prev);
				pq.push(v[x].second);

				prev = v[x].first;
			}

			else {

				//check if you have some fueling station in priority_queue
				if (pq.empty()) {
					flag = 1;
					break;
				}

				//otherwise refuel the truck with fuel station with higher capacity
				F += pq.top();
				pq.pop();
				ans += 1;
				continue; //this continue is very imp as it will take the control to the begining of while loop again

			}

			x++;
		}

		if (flag == 1) {
			cout << -1 << endl;
			continue;
		}

		//You have travelled n fuel stations , now you have to reach town from the last stop
		D = D - v[n - 1].first;

		if (F >= D) {
			cout << ans << endl;
			continue;
		}

		while (F < D) {

			//continue to recharge
			if (pq.empty()) {
				flag = 1;
				break;
			}

			F += pq.top();
			pq.pop();
			ans += 1;
		}

		if (flag == 1) {
			cout << -1 << endl;
			continue;
		}

		cout << ans << endl;
	}

	return 0;
}