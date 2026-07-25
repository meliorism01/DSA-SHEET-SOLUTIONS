// Min and Max in Array
// Solved
// Difficulty: BasicAccuracy: 68.55%Submissions: 542K+Points: 1Average Time: 10m
// Given an array arr[]. Your task is to find the minimum and maximum elements in the array.

// Examples:

// Input: arr[] = [1, 4, 3, 5, 8, 6]
// Output: [1, 8]
// Explanation: minimum and maximum elements of array are 1 and 8.
// Input: arr[] = [12, 3, 15, 7, 9]
// Output: [3, 15]
// Explanation: minimum and maximum element of array are 3 and 15.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 109

// BruteForce Solution :
class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
       int n = arr.size();
       int max = INT_MIN;
       int min = INT_MAX;
       for(int i =0; i<n; i++){
           if(arr[i]>max){
               max = arr[i];
           }
           if(arr[i]<min){
               min =arr[i];
           }
       }
       vector<int>ans;
       ans.push_back(min);
       ans.push_back(max);
       return ans;
    }
};


// optimised(using inbuilt function):

class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
       int n = arr.size();
       int maxx = INT_MIN;
       int minn = INT_MAX;
       for(int i =0; i<n; i++){
          minn = min(minn, arr[i]);
          maxx = max(maxx, arr[i]);
       }
       vector<int>ans;
       ans.push_back(minn);
       ans.push_back(maxx);
       return ans;
    }
};
