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



//Another Bruteforce fail :
// in this approach i tried to find the frequency of each element in the array and then checked if any element has frequency 1 then return that element.
// it pased almost all the test cases but failed for some test cases.
// example : Input
// nums =
// [8,1,8]
// k =
// 3
// Use Testcase
// Output
// 1
// Expected
// 8
// here the output is 1 but the expected output is 8
// because 8 appears twice but in only one subarray of size 3: [8,1,8] and 1 appears in only one subarray of size 3: [8,1,8] but 8 is the largest almost missing integer.
// so this approach would fail in the most cases where the size of the window is equal to the size of the array and the first and last elements are equal and the middle elements are different from them.

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        int max_ele = *max_element(nums.begin(), nums.end());
        vector<int> freq(max_ele + 1, 0);

        for(int i = 0; i + k <= n; i++) {
            for(int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }
        }

        int maxi = -1;

        for(int i = 0; i <= max_ele; i++) {
            if(freq[i] == 1) {
                maxi = max(maxi, i);
            }else if(freq[i]==k&&k==n){
                maxi = i;
            }
        }

        return maxi;
    }
};



// Final brute force approach :
// Count the number of windows in which each element appears
// seen[x] ensures that an element is counted only once per window
// i + 1 acts as a unique ID for the current window
// freq[x] represents the number of different windows containing x
// Find the largest element whose frequency is exactly 1
// Time: O(nk)
// Space: O(max(nums))
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        int max_ele = *max_element(nums.begin(), nums.end());

        vector<int> freq(max_ele + 1, 0);
        vector<int> seen(max_ele + 1, 0);

        for (int i = 0; i + k <= n; i++) {

            for (int j = i; j < i + k; j++) {
                int x = nums[j];

                if (seen[x] != i + 1) {
                    freq[x]++;
                    seen[x] = i + 1;
                }
            }
        }

        int ans = -1;

        for (int i = 0; i <= max_ele; i++) {
            if (freq[i] == 1) {
                ans = max(ans, i);
            }
        }

        return ans;
    }
};


// One more brute force approach :
// A bit more clear and understandable approach
// Here we are calculating the frequency of each element from the each window existing the array, and returning the largest element whose frequency is exactly 1
// there is an edge case if the size of the window is equal to the size of the array then we can return the max element from the array as it will be the largest almost missing integer
// int x = n - k + 1; i.e, the number of windows in the array
// time complexity : O(nk) and space complexity : O(max(nums))
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int x = n - k + 1;
        int max = *max_element(nums.begin(), nums.end());
        vector<int> freq(max + 1, 0);
        if(x==1){
            return max;
        }
        for (int i = 0; i < x; i++) {
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }
        }
        for (int i = freq.size() - 1; i >= 0; i--) {
            if (freq[i] == 1) {
                return i;
            }
        }
        return -1;
    }
};