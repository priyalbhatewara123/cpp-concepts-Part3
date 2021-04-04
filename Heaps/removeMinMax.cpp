/*
(2)
Remove min element from min heap or max element from max heap.

STEPS INVOLVED:
1) swap(v[1] , v[last])
2) shrink/remove the last node.
3) heapify to restore heap.

*/

#include <bits/stdc++.h>
using namespace std;

//to get min/max element
int top() {
	return v[1];
}

void pop() {

	int last = v.size() - 1;
	swap(v[1] , v[last]);

	v.pop_back();
	heapify(1);
}

//private method
void heapify(int indx) {

	//index of left child
	int left = 2 * indx;

	//index of right child
	int right = left + 1;

	int min_idx = indx;
	int last_idx = v.size() - 1;

	if (left <= last_idx and compare(v[left] , v[min_idx]))
		min_idx = left;

	if (right <= last_idx and compare(v[right] , v[min_idx]))
		min_idx = right;

	if (min_idx != indx) {
		swap(v[indx] , v[min_idx]);
		heapify(v[min_idx]);
	}
}

bool empty() {
	return v.size() == 1;
}

int main() {
	Heap h;
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int d; cin >> d;
		h.push(d);
	}

	while (!h.empty()) {
		cout << h.top() << " ";
		h.pop();
	}

	return 0;
}