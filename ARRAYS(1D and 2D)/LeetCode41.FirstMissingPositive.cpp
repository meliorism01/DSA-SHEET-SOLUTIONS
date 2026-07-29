// Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

// Example 1:

// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.
// Example 2:

// Input: nums = [3,4,-1,1]
// Output: 2
// Explanation: 1 is in the array but 2 is missing.
// Example 3:

// Input: nums = [7,8,9,11,12]
// Output: 1
// Explanation: The smallest positive integer 1 is missing.
 

// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1







//BruteForce Approach:
// create an extra array for positive elements only and sort them
//check if the array is empty, return 1
// check if the first element is greater than 1, return 1
// run a loop in the positive elemets array, to check any breakage i.e.
// if any element doesnt follow the exact lexicography and skips any integer in between
//  if (ans[i + 1] != ans[i] + 1)
//              return ans[i] + 1;
// by default return the element after the last element is the array :
// for the case if the array starts from 1 and follows perfect lexicography.
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> ans;

        for (int x : nums) {
            if (x > 0)
                ans.push_back(x);
        }

        if (ans.empty())
            return 1;

        sort(ans.begin(), ans.end());

        if (ans[0] > 1)
            return 1;

        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] == ans[i + 1]) //to skip the duplicates
                continue;             //example : [1,1,2,2,3,3,3]
                                      //as if (ans[i + 1] != ans[i] + 1) will give wrong return in case of duplicates
            if (ans[i + 1] != ans[i] + 1)
                return ans[i] + 1;
        }

        return ans.back() + 1;
    }
};