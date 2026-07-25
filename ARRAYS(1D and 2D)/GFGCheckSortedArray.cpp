// Check Sorted Array
// Solved
// Difficulty: EasyAccuracy: 39.37%Submissions: 427K+Points: 2Average Time: 15m
// Given an array arr[], check whether it is sorted in non-decreasing order. Return true if it is sorted otherwise false.

// Examples:

// Input: arr[] = [10, 20, 30, 40, 50]
// Output: true
// Explanation: The given array is sorted.
// Input: arr[] = [90, 80, 100, 70, 40, 30]
// Output: false
// Explanation: The given array is not sorted.
// Constraints:
// 1 ≤ arr.size ≤ 10^6
// - 10^9 ≤ arr[i] ≤ 10^9



//BruteForce Approach:
class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        int n = arr.size();
        int count=1;
        for(int i = 0; i < n-1; i++){
            if(arr[i]<=arr[i+1]){
                count++;
            }
        }
        if(count == n){
            return true;
        }
        return false;
    }
};


//Fully Optimised Solution:
// does not need to traverse the full array/vector
// return true as soon as the voilation(unsorted array) is found

class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        int n = arr.size();
        int count=1;
        for(int i = 0; i < n-1; i++){
            if(arr[i]>arr[i+1]){
                return false;
            }
                
        }
                    return true;
    }
};