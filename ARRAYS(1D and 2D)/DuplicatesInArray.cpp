// brute force :
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            int correct = nums[i] - 1;

            if (nums[i] != nums[correct]) {
                swap(nums[i], nums[correct]);
            }
            else {
                i++;
            }
        }

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};
// optimal approach:
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){

            int idx = abs(nums[i]) - 1;

            if(nums[idx] < 0)
                ans.push_back(abs(nums[i]));
            else
                nums[idx] = -nums[idx];
        }

        return ans;
    }
};

//another approach:
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n= nums.size()+1;
        vector<int> freq(n, 0);
        for(int i =0; i<nums.size(); i++){
            freq[nums[i]]++;
        }   
        nums.clear();
        for(int i=0; i<freq.size(); i++){
            if(freq[i]==2){
                nums.push_back(i);
            }
        }   
        return nums;
    }
};

//approach
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set <int> s;
      for(int i =0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i]==nums[j]){
                s.insert(nums[i]);
            }
        }
      }
      nums.clear();
      for(auto x:s){
        nums.push_back(x);
      }
      return nums;
    }
};



//two patterns are main here one is using set, and another is by using an extra array(frequency);