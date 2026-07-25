// 1752. Check if Array Is Sorted and Rotated
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

 

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
// Example 2:

// Input: nums = [2,1,3,4]
// Output: false
// Explanation: There is no sorted array once rotated that can make nums.
// Example 3:

// Input: nums = [1,2,3]
// Output: true
// Explanation: [1,2,3] is the original sorted array.
// You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100



//BruteForce Approach:
// Check if the array is sorted for every rotation between 0 to n-1;

class Solution {
public:
    bool isSorted(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    bool check(vector<int>& nums) {
        int n = nums.size();

        for (int k = 0; k < n; k++) {
            vector<int> temp;

            // Rotate by k positions
            for (int i = 0; i < n; i++) {
                temp.push_back(nums[(i + k) % n]);
            }

            if (isSorted(temp))
                return true;
        }

        return false;
    }
};



//APPROACH 1:
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        
        if(count<=1){
            return true;
        }else{
            return false;
        };
    }
};
// in this approach i have used %n concept as if ill continue the comparisons.. 
// it will send back to the first iteration..
// like if we compare if(nums[i] > nums[(i + 1)).. then due to n +1 it will overflow and returns error.
//     but in case of if(nums[i] > nums[(i + 1) % n]) it will send back to the first iteration.
// APPROACH 2:
class Solution {
public:
    bool check(vector<int>& nums) {
        if (nums.size() <= 1) {
            return true;
        }
        int count = 0;
        for (int i = 1;i < nums.size();i++) {
            if (nums[i] < nums[i - 1]) ++count;
        }
        if (count > 1) return false;
        if (count == 0) return true;
        return nums.back() <= nums.front();
    }
};

// in this approach we compare by using i-1 so that it does not overflow and no extra use of %n
// The algorithm has two checks:
// How many times does the order decrease?
// More than one decrease → impossible.
// If there is exactly one decrease, does the last element correctly wrap around to the first?
// last <= first → valid rotation.
// last > first → invalid rotation.