// // Problem Statement :
// Max Diff with Below and Right in Grid
// Solved
// Difficulty: HardAccuracy: 48.13%Submissions: 4K+Points: 8
// Given a square matrix mat[][] of size n * n, select two elements such that the second element lies strictly below and strictly to the right of the first element.

// Return the maximum possible difference between these two elements.

// In other words, for any two elements mat[a][b] and mat[c][d], find the maximum value of mat[c][d] - mat[a][b] such that c > a and d > b.

// Examples:

// Input: mat = [[ 1,  2, -1, -4, -20],
//              [-8, -3,  4,  2,   1],
//              [ 3,  8,  6,  1,   3],
//              [-4, -1,  1,  7,  -6],
//              [ 0, -4, 10, -5,   1]]
// Output: 18
// Explanation: Choose -8 at position (1, 0) and 10 at position (4, 2). Since the second element is strictly below and strictly to the right of the first element, 10 - (-8) = 18, which is the maximum possible difference.
// Input: mat = [[5, 4],
//              [3, 2]]
// Output: -3
// Explanation: The only valid pair is 5 and 2. 2 - 5 = -3. Hence, the maximum possible difference is -3.
// Constraints:
// 2 ≤ n ≤ 103
// -103 ≤ mat[i][j] ≤ 103
class Solution {
public:
    int findMaxValue(vector<vector<int>>& mat) {
        int n = mat.size();

        // maxArr[i][j] stores the maximum element
        // in the submatrix from (i,j) to (n-1,n-1)
        vector<vector<int>> maxArr(n, vector<int>(n));

        // Initialize bottom-right corner
        maxArr[n-1][n-1] = mat[n-1][n-1];

        // Fill last row
        for (int j = n - 2; j >= 0; j--) {
            maxArr[n-1][j] = max(mat[n-1][j], maxArr[n-1][j + 1]);
        }

        // Fill last column
        for (int i = n - 2; i >= 0; i--) {
            maxArr[i][n-1] = max(mat[i][n-1], maxArr[i + 1][n-1]);
        }

        int ans = INT_MIN;

        // Fill remaining cells
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {

                // Compute maximum difference
                ans = max(ans, maxArr[i + 1][j + 1] - mat[i][j]);

                // Update maxArr
                maxArr[i][j] = max({
                    mat[i][j],
                    maxArr[i][j + 1],
                    maxArr[i + 1][j]
                });
            }
        }

        return ans;
    }
};