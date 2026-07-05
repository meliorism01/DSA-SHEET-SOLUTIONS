//APPROACH 1:
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        
        if(count<=1){
            return true;
        }else{
            return false;
        };
    }
};
// in this approach i have used %n concept as if ill continue the comparisons.. 
// it will send back to the first iteration..
// like if we compare if(nums[i] > nums[(i + 1)).. then due to n +1 it will overflow and returns error.
//     but in case of if(nums[i] > nums[(i + 1) % n]) it will send back to the first iteration.
// APPROACH 2:
class Solution {
public:
    bool check(vector<int>& nums) {
        if (nums.size() <= 1) {
            return true;
        }
        int count = 0;
        for (int i = 1;i < nums.size();i++) {
            if (nums[i] < nums[i - 1]) ++count;
        }
        if (count > 1) return false;
        if (count == 0) return true;
        return nums.back() <= nums.front();
    }
};

// in this approach we compare by using i-1 so that it does not overflow and no extra use of %n