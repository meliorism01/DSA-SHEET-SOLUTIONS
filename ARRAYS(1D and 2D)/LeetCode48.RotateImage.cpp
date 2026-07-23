// QUESTION:
//  given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]
// Example 2:


// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 20
// -1000 <= matrix[i][j] <= 1000



//BRUTEFORCE SOLUTION:

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> temp(n, vector<int>(n));
        for(int i =0; i<n; i++){
            for(int j = 0; j<n;j++){
                temp[j][i]=matrix[i][j];
            }
                }
                
        for(int i =0; i<n; i++){
            int low =0, high = n-1;
             while(low<=high){
                swap(temp[i][low],temp[i][high]);
                low++;
                high--;
             }
        }
        matrix = temp;
     
    }
};



// ANOTHER BRUTEFORCE:
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> matrix1(n,vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j =0; j<n; j++){
           matrix1[j][n - 1 - i] = matrix[i][j];
            }
        }
        matrix = matrix1;

    }
};

// The key thing you're trying to achieve is this:

// When rotating 90° clockwise, the column in the new matrix should decrease by 1 for every new row of the original matrix.

// For n = 4, the destination columns should be:

// Original row (i)    Destination column

// 0                   3
// 1                   2
// 2                   1
// 3                   0

// Notice the pattern:

// 3, 2, 1, 0

// which is exactly

// n - 1 - i




// optimisd solution :

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = n - 1;

            while (left < right) {
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};

//key point to remember:
//90 = transpose + reverse row
// 180 = reverse row + reverse column
// 270 = transpose + reverse col
