/*
(4)
Problem Link : https://leetcode.com/problems/longest-consecutive-sequence/
*/

//Method - 3 Using unordered Map

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {

		//key -> number and value -> streak length
		unordered_map <int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			int no = nums[i];

			//in case duplicate elements are present in the vector ignore all the occurences after first one
			if (m.count(no)) {
				continue;
			}

			//Case 1 - start new streak
			if (m.count(no - 1) == 0 and m.count(no + 1) == 0)
				m[no] = 1;

			//Case 2 - concatenate two streaks
			else if (m.count(no - 1) and m.count(no + 1)) {
				int lenLeft = m[no - 1];
				int lenRight = m[no + 1];

				int newLength = lenLeft + 1 + lenRight;

				//update streak length of starting and end point
				m[no - lenLeft] = newLength;
				m[no + lenRight] = newLength;
				m[no] = newLength;
			}

			//Case 3 - Right Expansion of a streak
			else if (m.count(no - 1) and !m.count(no + 1)) {
				int len = m[no - 1];
				m[no - len] = len + 1; //starting point
				m[no] = len +  1; //end point
			}

			//Case 4 - Left Expansion of a streak
			else {
				int len = m[no + 1];
				m[no + len] = len + 1; //end point
				m[no] = len +  1; //starting point
			}
		}

		//find largest value in hashmap
		int largest = 0;
		for (auto p : m) {
			largest = max(largest , p.second);
		}

		return largest;
	}
};