// You are given a 0-indexed array of integers nums.

// A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only of nums[0] is sequential.

// Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix.

 

// Example 1:

// Input: nums = [1,2,3,2,5]
// Output: 6
// Explanation: The longest sequential prefix of nums is [1,2,3] with a sum of 6. 6 is not in the array, therefore 6 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.
// Example 2:

// Input: nums = [3,4,5,1,12,14,13]
// Output: 15
// Explanation: The longest sequential prefix of nums is [3,4,5] with a sum of 12. 12, 13, and 14 belong to the array while 15 does not. Therefore 15 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.
 

// Constraints:

// 1 <= nums.length <= 50
// 1 <= nums[i] <= 50



//BruteForce Approach :
// Find the sum of the longest sequential prefix
// For every candidate, scan the entire array
// to check whether the candidate is present
// Candidate is not present, so it is the answer
// Candidate exists, so check the next integer
// Time: O(n²)
// Space: O(1)

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int ans = nums[0];

        // Find sum of sequential prefix
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1)
                ans += nums[i];
            else
                break;
        }

        // Brute force: check every candidate in the array
        while (true) {
            bool found = false;

            for (int i = 0; i < n; i++) {
                if (nums[i] == ans) {
                    found = true;
                    break;
                }
            }

            if (!found)
                return ans;

            ans++;
        }
    }
};




//Optimized Approach :
// Find the sum of the longest sequential prefix
// Mark every number that exists in the array
// Move forward while the current candidate exists
// First unmarked value is the smallest missing integer
// Time: O(n)
// Space: O(1) — fixed-size array due to bounded constraints
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        // Find sequential prefix sum
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                ans += nums[i];
            } else {
                break;
            }
        }

        // Mark all numbers present
        vector<bool> present(1001, false);

        for (int x : nums) {
            present[x] = true;
        }

        // Find smallest missing number >= ans
        while (ans < present.size() && present[ans]) {
            ans++;
        }

        return ans;
    }
};