// You are given an integer array nums, an integer array queries, and an integer x.

// For each queries[i], you need to find the index of the queries[i]th occurrence of x in the nums array. If there are fewer than queries[i] occurrences of x, the answer should be -1 for that query.

// Return an integer array answer containing the answers to all queries.

 

// Example 1:

// Input: nums = [1,3,1,7], queries = [1,3,2,4], x = 1

// Output: [0,-1,2,-1]

// Explanation:

// For the 1st query, the first occurrence of 1 is at index 0.
// For the 2nd query, there are only two occurrences of 1 in nums, so the answer is -1.
// For the 3rd query, the second occurrence of 1 is at index 2.
// For the 4th query, there are only two occurrences of 1 in nums, so the answer is -1.
// Example 2:

// Input: nums = [1,2,3], queries = [10], x = 5

// Output: [-1]

// Explanation:

// For the 1st query, 5 doesn't exist in nums, so the answer is -1.
 

// Constraints:

// 1 <= nums.length, queries.length <= 105
// 1 <= queries[i] <= 105
// 1 <= nums[i], x <= 104





//Brute Force Approach:
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {

        vector<int> ans;

        // Process each query independently.
        for (int q : queries) {

            int count = 0;
            int index = -1;

            // Traverse the entire array.
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == x) {
                    count++;

                    // Found the required occurrence.
                    if (count == q) {
                        index = i;
                        break;
                    }
                }
            }

            ans.push_back(index);
        }

        return ans;
    }
};




//Optimal Approach: Store Occurrence Indices
// Time Complexity: O(n + q)
// Space Complexity: O(k), where k is the number of occurrences of x.
//
// Idea:
// 1. Traverse the array once and store the indices where 'x' occurs.
// 2. For each query:
//    - If the required occurrence number is greater than the total
//      number of occurrences, return -1.
//    - Otherwise, return the index stored for that occurrence.
//
// Since queries are 1-based and vectors are 0-based,
// the k-th occurrence is stored at occ[k - 1].

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {

        // Store the indices where x occurs
        vector<int> occ;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                occ.push_back(i);
            }
        }

        // Answer each query
        for (int i = 0; i < queries.size(); i++) {

            // If the required occurrence doesn't exist
            if (queries[i] > occ.size()) {
                queries[i] = -1;
            }
            else {
                // Queries are 1-based, vector is 0-based
                queries[i] = occ[queries[i] - 1];
            }
        }

        return queries;
    }
};