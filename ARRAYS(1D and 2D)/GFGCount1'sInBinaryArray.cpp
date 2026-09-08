// You are given a binary array that is sorted in non-increasing order, meaning all the 1's appear before the 0's. Find the total number of 1's present in the array.

// Examples:

// Input: arr[] = [1, 1, 1, 1, 1, 0, 0, 0]
// Output: 5
// Explaination: Count of 1's in the array is 5.
// Input: arr[] = [1, 1, 1, 1, 1, 1, 1]
// Output: 7
// Explaination: Count of 1's in the array is 7.
// Constraints:
// 1 ≤ arr.size() ≤ 105 
// 0 ≤ arr[i] ≤ 1

// brute force approach :
// time complexity : O(n)
// space complexity : O(1)
class Solution {
  public:
    int countOnes(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(arr[i]==1){
                count++;
            }
        }
        return count;
    }
};






//brute force approach :
// time complexity : O(log n)
// space complexity : O(1)
// This approach uses binary search to find the last occurrence of 1 in the array. The count of 1's will be the index of the last occurrence + 1.
class Solution {
public:
    int countOnes(vector<int>& arr) {
        int st = 0;
        int end = arr.size() - 1;
        int lastOne = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] == 1) {
                lastOne = mid;
                st = mid + 1;       // Look for more 1s on the right
            }
            else {
                end = mid - 1;      // 0 means all after it are also 0
            }
        }

        return lastOne + 1;
    }
};