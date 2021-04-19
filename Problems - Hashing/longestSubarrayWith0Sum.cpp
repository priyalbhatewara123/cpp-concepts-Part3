/*
(2)
Problem Link : https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/

int maxLen(int a[], int n)
{
    // Your code here
    int csum = 0;
    int maxLength = 0;
    unordered_map <int, int> m;
    for (int i = 0; i < n; i++) {

        csum += a[i];

        //check if csum is 0
        if (csum == 0) {
            maxLength = max(maxLength , i + 1);
        }

        //if csum is not already present in the map store it's first occurence
        if (m.find(csum) == m.end()) {
            m[csum] = i;
        }
        else {
            //csum is already present so check for max length
            maxLength = max(maxLength , i - m[csum]);
        }

    }
    return maxLength;
}
