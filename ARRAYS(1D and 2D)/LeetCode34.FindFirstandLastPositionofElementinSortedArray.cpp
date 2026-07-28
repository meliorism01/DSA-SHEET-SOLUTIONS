// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109








//Brute Force Solution:
// keep the ans vector {-1, -1} by default
// while traversing the giver array, check if the element is = target;
// if it is so, push it into ans vector in the place of first ocurrence, using an if condition
//  if (ans[0] == -1) : to avoid pushing other occurences in place of first
// keep updation last occurrence
class Solution {
public:
    vector<int> find(vector<int>& arr, int x) {
        vector<int> ans = {-1, -1};

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) {
                if (ans[0] == -1)
                    ans[0] = i;   // First occurrence

                ans[1] = i;       // Keep updating last occurrence
            }
        }

        return ans;
    }
};



// BruteForce Solution(keeping given constraints in mind):
// Used Binary Search
// In case arr[mid]== x;
// push the value of mid for both first and last occurence(){just in case the integer occurs only one time}
// start 2 consecutive for loop after passing values
// from mid to high and from mid to low : to find first and last occurence if the element has more than one occurances
// If x is not found, return {-1, -1}.
// Time Complexity: O(n) in the worst case
// Space Complexity: O(1)

class Solution {
public:
    vector<int> find(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;

        vector<int> ans = {-1, -1};

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) {

                // Find first occurrence
                ans[0] = mid;
                for (int i = mid; i > low; i--) {
                    if (arr[i] != arr[i - 1]) {
                        ans[0] = i;
                        break;
                    }
                    if (i - 1 == low) {
                        ans[0] = low;
                    }
                }

                // Find last occurrence
                ans[1] = mid;
                for (int i = mid; i < high; i++) {
                    if (arr[i] != arr[i + 1]) {
                        ans[1] = i;
                        break;
                    }
                    if (i + 1 == high) {
                        ans[1] = high;
                    }
                }

                break;
            }
            else if (arr[mid] > x) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};


//Optimal Approach:
// using two binary searches :
// one for the first occurrence{whenever we find arr[mid]= target, we do high =mid-1}
// another for the last occurrece{whenever we find arr[mid]= target, we do low = mid+1}
//Brute Force Solution:
// keep the ans vector {-1, -1} by default
// while traversing the giver array, check if the element is = target;
// if it is so, push it into ans vector in the place of first ocurrence, using an if condition
//  if (ans[0] == -1) : to avoid pushing other occurences in place of first
// keep updation last occurrence
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if (ans[0] == -1)
                    ans[0] = i;   // First occurrence

                ans[1] = i;       // Keep updating last occurrence
            }
        }

        return ans;
    }
};



// BruteForce Solution(keeping given constraints in mind):
// Used Binary Search
// In case arr[mid]== x;
// push the value of mid for both first and last occurence(){just in case the integer occurs only one time}
// start 2 consecutive for loop after passing values
// from mid to high and from mid to low : to find first and last occurence if the element has more than one occurances
// If x is not found, return {-1, -1}.
// Time Complexity: O(n) in the worst case
// Space Complexity: O(1)

class Solution {
public:
    vector<int> find(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;

        vector<int> ans = {-1, -1};

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) {

                // Find first occurrence
                ans[0] = mid;
                for (int i = mid; i > low; i--) {
                    if (arr[i] != arr[i - 1]) {
                        ans[0] = i;
                        break;
                    }
                    if (i - 1 == low) {
                        ans[0] = low;
                    }
                }

                // Find last occurrence
                ans[1] = mid;
                for (int i = mid; i < high; i++) {
                    if (arr[i] != arr[i + 1]) {
                        ans[1] = i;
                        break;
                    }
                    if (i + 1 == high) {
                        ans[1] = high;
                    }
                }

                break;
            }
            else if (arr[mid] > x) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};



//Optimal Approach:
// using two binary searches :
// one for the first occurrence{whenever we find arr[mid]= target, we do high =mid-1}
// another for the last occurrece{whenever we find arr[mid]= target, we do low = mid+1}
class Solution {
	public:
	vector<int> find(vector<int>& arr, int x) {
		int n = arr.size();
		int low = 0;
		int low1 = 0;
		int high = n - 1;
		int high1 = n - 1;
		vector<int> ans = {-1, -1};
		while (low <= high) {
			int mid = low + (high - low) / 2;
			
			if (arr[mid] == x) {
				ans[0] = mid;
				high = mid - 1; // Keep searching left
			}
			else if (arr[mid] < x) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		while (low1 <= high1) {
			int mid = low1 + (high1 - low1) / 2;
			
			if (arr[mid] == x) {
				ans[1] = mid;
				low1 = mid + 1; // Keep searching right
			}
			else if (arr[mid] < x) {
				low1 = mid + 1;
			}
			else {
				high1 = mid - 1;
			}
		}
		return ans;
	}
};

