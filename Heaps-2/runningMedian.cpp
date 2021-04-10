#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	priority_queue <int> leftHeap; //max heap
	priority_queue <int , vector<int> , greater<int> > rightHeap; //min heap

	int d; cin >> d;
	leftHeap.push(d);

	float median = d;
	cout << "Median : " << median << endl;

	cin >> d;
	while (d != -1) {

		if (leftHeap.size() > rightHeap.size()) {
			if (d > median) {
				rightHeap.push(d);
			}
			else {
				rightHeap.push(leftHeap.top());
				leftHeap.pop();
				leftHeap.push(d);
			}
			median = (leftHeap.top() + rightHeap.top()) / 2.0;
		}

		else if (leftHeap.size() == rightHeap.size()) {
			if (d < median) {
				leftHeap.push(d);
				median = leftHeap.top();
			}
			else {
				rightHeap.push(d);
				median = rightHeap.top();
			}
		}

		else {
			if (d > median) {
				leftHeap.push(rightHeap.top());
				rightHeap.pop();
				rightHeap.push(d);
			}
			else {
				leftHeap.push(d);
			}
			median = (leftHeap.top() + rightHeap.top()) / 2.0;
		}

		cout << "Median : " << median << endl;
		cin >> d;
	}

	return 0;
}