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


//Fully Optimised:
// reduced number of compaerisons
// comparing consecutive pairs
// greater one is overwritten as max element
// smaller one is overwritten as min element
// if both are equal, compare first one with the maix and min
// for an array/vector with odd length use if(n%2==1) case and compare n-1th element with both max and min
class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
       int n = arr.size();
       int maxx = INT_MIN;
       int minn = INT_MAX;
       for(int i =0; i<n-1; i+=2){
           if(arr[i]>arr[i+1]){
          minn = min(minn, arr[i+1]);
          maxx = max(maxx, arr[i]);
           } else if (arr[i]<arr[i+1]){
             minn = min(minn, arr[i]);
             maxx = max(maxx, arr[i+1]);
           }else{
               minn = min(minn, arr[i]);
               maxx = max(maxx, arr[i]);
           }
       }
       if(n%2==1){
       minn = min(minn, arr[n-1]);
       maxx = max(maxx, arr[n-1]);
       }
       vector<int>ans;
       ans.push_back(minn);
       ans.push_back(maxx);
       return ans;
    }
};