// You are given an integer array nums consisting of unique integers.

// Originally, nums contained every integer within a certain range. However, some integers might have gone missing from the array.

// The smallest and largest integers of the original range are still present in nums.

// Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.

 

// Example 1:

// Input: nums = [1,4,2,5]

// Output: [3]

// Explanation:

// The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. Among these, only 3 is missing.

// Example 2:

// Input: nums = [7,8,6,9]

// Output: []

// Explanation:

// The smallest integer is 6 and the largest is 9, so the full range is [6,7,8,9]. All integers are already present, so no integer is missing.

// Example 3:

// Input: nums = [5,1]

// Output: [2,3,4]

// Explanation:

// The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. The missing integers are 2, 3, and 4.

 

// Constraints:

// 2 <= nums.length <= 100
// 1 <= nums[i] <= 100






//BrruteForce Approach :
// Sort the array to bring all elements into ascending order.
// Traverse the sorted array and compare adjacent elements.
// If the difference between consecutive elements is greater than 1,
// it indicates that one or more numbers are missing.
// Calculate the gap between the two consecutive elements.
// Add all the missing numbers from the current gap to the answer vector.
// Sort the answer vector since missing numbers were inserted in reverse order.
// Return the list of missing elements.
// Time Complexity
// Sorting input array: O(n log n)
// Traversing the array: O(n)
// Adding missing elements: O(k), where k is the number of missing elements.
// Sorting the answer: O(k log k)
// Overall: O(n log n + k log k)
// Space Complexity
// O(1) auxiliary space (excluding the output vector).
// O(k) for the returned answer.
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i<n-1; i++){
            if((nums[i+1]-nums[i])!=1){
                int count = nums[i+1]-nums[i];
                int x = 1;
                while(count>1){
                ans.push_back(nums[i+1]-x);
                x++;
                count--;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


//Syntactically optimised :
// Instead of:
// int count = nums[i+1]-nums[i];
// int x = 1;
// while(count>1){
//     ans.push_back(nums[i+1]-x);
//     x++;
//     count--;
// }
// you can write:
// for (int x = nums[i] + 1; x < nums[i + 1]; x++) {
//     ans.push_back(x);
// }
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n - 1; i++) {
            for (int x = nums[i] + 1; x < nums[i + 1]; x++) {
                ans.push_back(x);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};




//Optimal Solution:
// Find the minimum and maximum elements in the array.
// Create a presence array to mark the existing elements.
// Mark each element of the input array as present.
// Traverse all numbers between the minimum and maximum values.
// If a number is not marked as present,
// add it to the answer vector as a missing element.
// Return the list of missing elements.
// Time Complexity:
// Finding the minimum element    : O(n)
// Finding the maximum element    : O(n)
// Marking elements in the vector : O(n)
// Traversing the range           : O(range)
// Overall Time Complexity        : O(n + range)
// Space Complexity:
// Presence vector                : O(mx)
// Answer vector                  : O(k)
// Auxiliary Space                : O(mx)
// Total Space Complexity         : O(mx + k)

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        // Presence array
        vector<int> present(mx + 1, 0);

        // Mark all existing elements
        for (int num : nums) {
            present[num] = 1;
        }

        vector<int> ans;

        // Find missing elements
        for (int i = mn + 1; i < mx; i++) {
            if (present[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};