/*
(1)
Indian Coin Change
*/

#include <bits/stdc++.h>
using namespace std;

int make_change(int *coins , int n , int money) {
	int ans = 0;
	while (money > 0) {

		int idx = upper_bound(coins , coins + n , money) - 1 - coins;
		money = money - coins[idx];
		ans++;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int money; cin >> money;
	int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

	int coinsRequired = make_change(coins, 10, money);

	cout << coinsRequired;
	return 0;
}