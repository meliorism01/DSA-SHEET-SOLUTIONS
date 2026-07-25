// 1636. Sort Array by Increasing Frequency
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

// Return the sorted array.

 

// Example 1:

// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
// Example 2:

// Input: nums = [2,3,1,3,2]
// Output: [1,3,3,2,2]
// Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
// Example 3:

// Input: nums = [-1,1,-6,4,5,-6,1,4,1]
// Output: [5,-1,4,4,-6,-6,1,1,1]
 

// Constraints:

// 1 <= nums.length <= 100
// -100 <= nums[i] <= 100




//BruteForce Approach :
// doesn't work fro negative elements
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        int maxValue = *max_element(nums.begin(), nums.end());
        vector<int> temp(maxValue + 1, 0);
        for (int i = 0; i < n; i++) {
            temp[nums[i]]++;
        }
        vector<int> ans;
        for (int i = 0; i < temp.size(); i++) {
            while (temp[i] > 0) {
                ans.push_back(i);
                temp[i]--;
            }
        }
        return ans;
    }
};

// OPTIMAL APPROACH:
// Why +100?

// The vector indices are:

// Number	Index
// -100	      0
// -99	      1
// -1	      99
// 0	      100
// 1	      101
// 100	      200
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        vector<int> freq(201, 0);

        // Count frequencies
        for (int x : nums)
            freq[x + 100]++;

        // Sort nums using frequency vector
        sort(nums.begin(), nums.end(), [&](int a, int b) {

            if (freq[a + 100] == freq[b + 100])
                return a > b;

            return freq[a + 100] < freq[b + 100];
        });

        return nums;
    }
};

//OPTIMISED SOLUTION:
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<pair<int,int>> freq;
        
        for(int i = 0; i < nums.size(); ){
            int count = 1;
            int j = i + 1;

            while(j < nums.size() && nums[i] == nums[j]){
                count++;
                j++;
            }

            freq.push_back({count, nums[i]});
            i = j;
        }

        sort(freq.begin(), freq.end(), [](pair<int,int> a, pair<int,int> b){
            
            if(a.first == b.first)
                return a.second > b.second;
            
            return a.first < b.first;
        });

        vector<int> ans;

        for(auto p : freq){
            for(int i = 0; i < p.first; i++){
                ans.push_back(p.second);
            }
        }

        return ans;
    }
};