/*
(5)
Defence of a kingdom - https://www.spoj.com/problems/DEFKIN/
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {

		int w, h, n;
		cin >> w >> h >> n;
		int x[40010]; //to store x coordinates of all towers
		int y[40010]; //to store y coordinates of all towers

		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
		}

		//sorting to know sequence of towers
		sort(x, x + n);
		sort(y, y + n);

		//calculate dx , dy
		int dx = x[0] - 1;
		int dy = y[0] - 1;

		for (int i = 1; i < n; i++) {
			dx = max(dx , x[i] - x[i - 1] - 1);
			dy = max(dy , y[i] - y[i - 1] - 1);
		}

		//corner case
		dx = max(dx, w - x[n - 1]);
		dy = max(dy, h - y[n - 1]);

		cout << dx*dy << endl;
	}
}