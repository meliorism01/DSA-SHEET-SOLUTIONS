// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

 

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 105





//BrueForce Approach :
// storing frequency of each element in another vector
// Time Complexity : O(n+M)
// Space Complexity : O(M)
// where M is the largest element of the given array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(nums[n-1] + 1, 0);
        for(int i = 0; i<nums.size(); i++){
            ans[nums[i]]++;
        }
        for(int i =0; i<ans.size(); i++){
            if(ans[i]==1){
                return i;
            }
        }
        return 0;
    }
};