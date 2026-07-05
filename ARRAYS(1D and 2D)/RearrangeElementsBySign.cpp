class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>positive;
        vector<int>negative;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                negative.push_back(nums[i]);
            }else if(nums[i]>=0){
                positive.push_back(nums[i]);
            }
        }
        nums.clear();
        for(int i=0; i<positive.size(); i++){
            nums.push_back(positive[i]);
            nums.push_back(negative[i]);
        } 
        return nums;
    }
   
};

//2nd approach:
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int pos = 0;  // even indices
        int neg = 1;  // odd indices

        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2;
            }
            else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;
    }
};