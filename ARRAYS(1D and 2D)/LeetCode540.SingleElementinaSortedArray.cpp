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




//BruteForce Approach after space optimisatiom : Linear Scan Approach
// Time Complexity : O(n)
// Space Complexity : O(1)
// checked whether the size of given array is 1 then returned the only existing element
// then checked if the first for last element has unique occurence
// then iterated through the array and checked if the current element is not equal to its previous and next element then returned the current element
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
           return nums[0]; 
        }
        else if(nums[0]!=nums[1]){
            return nums[0];
        }else if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }
        for(int i = 1; i<nums.size()-1; i++){
            if(nums[i]!=nums[i+1]&&nums[i]!=nums[i-1]){
                return nums[i];
            }
        }
        return 0;
    }
};





// Optimised solution : Binary Search Approach
// Time Complexity : O(log n)
// Space Complexity : O(1)
// checked whether the size of given array is 1 then returned the only existing element
// then checked if the first for last element has unique occurence
// thern traversed the array using binary search and checked if the mid element is not equal to its previous and next element then returned the mid element
// then got the intution that every element pair in the left from the single element will have the first occurence at even index and second occurence at odd index 
// and every element pair in the right from the single element will have the first occurence at odd index and second occurence at even index
// used condtions accordingly to move the low and high pointers to find the single element
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        if (nums[0] != nums[1])
            return nums[0];

        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1;
        int high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // mid itself is the single element
            if (nums[mid] != nums[mid - 1] &&
                nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            if (mid % 2 == 0) {
                // Correct pair should be (mid, mid+1)
                if (nums[mid] == nums[mid + 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else {
                // Correct pair should be (mid-1, mid)
                if (nums[mid] == nums[mid - 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};





//Clean Optimisation
// Initialize binary search range
// Calculate middle index
// Make mid even
// Check if pair is valid
// Search in right half
// Search in left half
// Return single element
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1])
                low = mid + 2;
            else
                high = mid;
        }

        return nums[low];
    }
};