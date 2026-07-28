// Given a sorted array arr[] with possibly some duplicates, find the first and last occurrences of an element x in the given array.
// Note: If the number x is not found in the array then return both the indices as -1.

// Examples:

// Input: arr[] = [1, 3, 5, 5, 5, 5, 67, 123, 125], x = 5
// Output: [2, 5]
// Explanation: First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5
// Input: arr[] = [1, 3, 5, 5, 5, 5, 7, 123, 125], x = 7
// Output: [6, 6]
// Explanation: First and last occurrence of 7 is at index 6
// Input: arr[] = [1, 2, 3], x = 4
// Output: [-1, -1]
// Explanation: No occurrence of 4 in the array, so, output is [-1, -1]
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i], x ≤ 109




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






