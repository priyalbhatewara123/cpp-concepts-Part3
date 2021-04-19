/*
(3)
Problem link : https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
*/

class Solution {
public:
    int lenOfLongSubarr(int A[],  int N, int K)
    {
        // Complete the function
        int csum = 0;
        int maxLength = 0;
        unordered_map <int, int> m;
        for (int i = 0; i < N; i++) {

            csum += A[i];

            //check if csum is k
            if (csum == K) {
                maxLength = max(maxLength , i + 1);
            }

            //if csum is not already present in the map store it
            if (m.find(csum) == m.end()) {
                m[csum] = i;
            }

            if (m.find(csum - K) != m.end()) {
                maxLength = max(maxLength , i - m[csum - K]);
            }

        }
        return maxLength;
    }

};

//This might not work if k is 0