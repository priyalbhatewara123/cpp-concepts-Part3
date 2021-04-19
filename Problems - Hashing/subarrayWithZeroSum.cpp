/*
(1)
Check if the array has a subarray with sum zero.

Time complexity is almost O(n).
*/

#include <bits/stdc++.h>
using namespace std;

bool checkSum(int arr[] , int n) {

	unordered_set <int> s;

	int prefixSum = 0;
	for (int i = 0; i < n; i++) {
		prefixSum += arr[i];

		//if prefix sum is 0 or prefix sum is already present in set than we found a subarray with sum 0
		if (prefixSum == 0 or s.find(prefixSum) != s.end())  //find func works in O(1) time in set
			return true;

		s.insert(prefixSum);
	}

	return false;
}

int main() {
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (checkSum(arr, n)) {
		cout << "Yes";
	}
	else {
		cout << "NO";
	}

	return 0;
}