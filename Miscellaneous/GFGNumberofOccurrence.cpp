// Given a sorted array arr[] and a number target, find the number of occurrences of target in given array. 

// Examples:

// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
// Output: 4
// Explanation: target = 2 occurs 4 times in the given array so the output is 4.
// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
// Output: 0
// Explanation: target = 4 is not present in the given array so the output is 0.
// Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
// Output: 3
// Explanation: target = 12 occurs 3 times in the given array so the output is 3.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i] ≤ 106
// 1 ≤ target ≤ 106




//BruteForce Approach:
//Linear Search:
// Time Complexity:
// Worst Case : O(n)
// Best Case  : O(n)
// Space Complexity: O(1)
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        int freq = 0;
        for(int i = 0; i<n; i++){
            if(arr[i]==target){
                freq++;
            } //else if(arr[i]>target){
            //     break;
            // }
        }
        return freq;
    }
};


//Early Exit Optimisation:
// breaking the loop just after we get the occurences of the target number
// Time Complexity:
// Worst Case : O(n)
// Best Case  : O(1)
// Space Complexity: O(1)
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        int freq = 0;
        for(int i = 0; i<n; i++){
            if(arr[i]==target){
                freq++;
            }else if(arr[i]>target){
                break;
            }
        }
        return freq;
    }
};





//Optimal Approach: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
//
// Since the array is sorted, we perform two binary searches:
// 1. Find the first (leftmost) occurrence of the target.
// 2. Find the last (rightmost) occurrence of the target.
//
// If the target is not found, return 0.
// Otherwise, the frequency is calculated as:
//      lastOccurrence - firstOccurrence + 1
class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1;
        int left = -1, right = -1;

        // Find first occurrence
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                left = mid;
                end = mid - 1;
            } else if (arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        if (left == -1)
            return 0;

        start = 0;
        end = arr.size() - 1;

        // Find last occurrence
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                right = mid;
                start = mid + 1;
            } else if (arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return right - left + 1;
    }
};


