// brute force: class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int count =0;
        for(int i =0; i<rows; i++){
            for(int j=0;j<cols; j++){
                if(matrix[i][j]==target){
                    count++;
                    break;
                }
            }
        }
        if(count>0){
            return true;
        }else{
        return false;
        }
    }
};
//or
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }

        return false;
    }
};



//optimised as per asked:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int>temp;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp.push_back(matrix[i][j]);
            }
        }
        int low=0, high =temp.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(temp[mid]==target){
                return true;
            }else if(temp[mid]>target){
                high = mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
    }
};
  

// most optimised solution as per the question
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low=0, high =(rows*cols)-1;
       while (low <= high) {
    int mid = low + (high - low) / 2;

    int row = mid / cols;
    int col = mid % cols;

    if (matrix[row][col] == target)
        return true;
    else if (matrix[row][col] < target)
        low = mid + 1;
    else
        high = mid - 1;
}

return false;
    }
};