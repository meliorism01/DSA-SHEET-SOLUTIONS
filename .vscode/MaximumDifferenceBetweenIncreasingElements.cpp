// bruteforce appproach:
// using two loops and storing the differences in diff for each iteration such that diff is sompared to maxdiff and then maxdiff is printed
// Example 1:

// Input: nums = [7,1,5,4]
// Output: 4
// Explanation:
// The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
// Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.
// Example 2:

// Input: nums = [9,4,3,2]
// Output: -1
// Explanation:
// There is no i and j such that i < j and nums[i] < nums[j].
// Example 3:

// Input: nums = [1,5,2,10]
// Output: 9
// Explanation:
// The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.

 int maximumDifference(vector<int>& nums) {
        int maxdiff= -1; 
        for(int i=0; i<nums.size();i++ ){
           int diff =0;
            for(int j=i+1; j<nums.size(); j++){
                    diff=nums[j]-nums[i];
                    {maxdiff=max(diff,maxdiff);}
              
            }
        }if(maxdiff>0){return maxdiff;}else{return -1;}
        
    }

//     optimal approach:
//     Approach: Prefix Minimum Value
// Intuition
// When we fix j, the chosen index i must satisfy 0≤i<j and nums[i] must be the smallest among those indices. Therefore, we can iterate over j while maintaining the prefix minimum of nums[0..j−1], denoted as premin. In this way:

// If nums[j]>premin, we update the answer with nums[j]−premin.

// Otherwise, we update the prefix minimum value premin using nums[j].
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1, premin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > premin) {
                ans = max(ans, nums[i] - premin);
            } else {
                premin = nums[i];
            }
        }
        return ans;
    }
};