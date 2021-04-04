/*
Problem Statement : https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#
*/

//Solution function
long long minCost(long long arr[], long long n) {
	// Your code here
	priority_queue <int , vector<int> , greater<int> > pq(arr, arr + n);
	long long cost = 0;
	while (pq.size() > 1) {
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();

		long long newRope = (a + b);
		cost += newRope;
		pq.push(newRope);
	}

	return cost;
}