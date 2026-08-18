// You are given an integer array nums and an integer k.

// An integer x is almost missing from nums if x appears in exactly one subarray of size k within nums.

// Return the largest almost missing integer from nums. If no such integer exists, return -1.

// A subarray is a contiguous sequence of elements within an array.
 

// Example 1:

// Input: nums = [3,9,2,1,7], k = 3

// Output: 7

// Explanation:

// 1 appears in 2 subarrays of size 3: [9, 2, 1] and [2, 1, 7].
// 2 appears in 3 subarrays of size 3: [3, 9, 2], [9, 2, 1], [2, 1, 7].
// 3 appears in 1 subarray of size 3: [3, 9, 2].
// 7 appears in 1 subarray of size 3: [2, 1, 7].
// 9 appears in 2 subarrays of size 3: [3, 9, 2], and [9, 2, 1].
// We return 7 since it is the largest integer that appears in exactly one subarray of size k.

// Example 2:

// Input: nums = [3,9,7,2,1,7], k = 4

// Output: 3

// Explanation:

// 1 appears in 2 subarrays of size 4: [9, 7, 2, 1], [7, 2, 1, 7].
// 2 appears in 3 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7].
// 3 appears in 1 subarray of size 4: [3, 9, 7, 2].
// 7 appears in 3 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7].
// 9 appears in 2 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1].
// We return 3 since it is the largest and only integer that appears in exactly one subarray of size k.

// Example 3:

// Input: nums = [0,0], k = 1

// Output: -1

// Explanation:

// There is no integer that appears in only one subarray of size 1.

 

// Constraints:

// 1 <= nums.length <= 50
// 0 <= nums[i] <= 50
// 1 <= k <= nums.length



// firstly i tried to implement the brute force approach.
// based on the test cases i started coding and solved it greedily.
// i checked the first and last elements of the array and then checked if any element in between is equal to them.
// if any element in between is equal to them then return the other element.
// if the first and last elements are equal then return -1
// if the first and last elements are not equal then return the max of them

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int st = nums[0];
        int end = nums[n-1];
        for(int i = 1; i<n-1; i++){
            if(nums[i]==st){
                return end;
            }else if(nums[i]==end){
                return st;
            }else if(nums[i]==0){

            }
        }
        if(st==end){
        return -1; 
        }
        return max(st, end);
    }
};

//this approach is not correct for all test cases.
// as when i used my own test cases i found that it is not correct for all test cases.
// example : [3,3,9,2,1,7,7]
// k =
// 3
// Output
// 7
// Expected
// -1
// here the output is 7 but the expected output is -1
// because 7 appears in 2 subarrays of size 3: [1,7,7] and [7,7,?] (the last subarray is incomplete but still counts as a subarray of size 3).