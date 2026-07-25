//Brute force approach:
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int>temp;
        for(int i = 0; i<n; i++){
            int count =0;
            for(int j = i; j < n; j++){
                if(arr[i]<arr[j%n]){
                    count++;
                    break;
                }
            }
            if(count==0){
                temp.push_back(arr[i]);
            }
        }
        return temp;
    }
};

//OR

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> leaders;

        for(int i = 0; i < n; i++) {
            bool isLeader = true;

            for(int j = i + 1; j < n; j++) {
                if(arr[i] < arr[j]) {
                    isLeader = false;
                    break;
                }
            }

            if(isLeader) {
                leaders.push_back(arr[i]);
            }
        }

        return leaders;
    }
};


//Optimal Approach:

class Solution {
public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int maxi = INT_MIN;

        for(int i = arr.size() - 1; i >= 0; i--){
            if(arr[i] >= maxi){
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//OPTIMISED APPROACH:
// No reverse is needed.
// using ans.insert(ans.begin(), arr[i]); function
class Solution {
public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int maxi = INT_MIN;

        for(int i = arr.size() - 1; i >= 0; i--){
            if(arr[i] >= maxi){
                ans.insert(ans.begin(), arr[i]);
                maxi = arr[i];
            }
        }
        return ans;
    }
};