// approach 1:
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxdiff= -1; 
        for(int i=0; i<nums.size();i++ ){
           int diff =0;
            for(int j=i+1; j<nums.size(); j++){
                    diff=nums[j]-nums[i];
                    {maxdiff=max(diff,maxdiff);}
              
            }
        }if(maxdiff>0){return maxdiff;}else{return -1;}
        
    }
};

// approach 2

class Solution {
public:
int diff=-1;
    int maximumDifference(vector<int>& nums) {
                for(int i=0;i<nums.size();i++){
            for(int j=1+i;j<nums.size();j++){
               if(nums[j]>nums[i]){
                int diff2=nums[j]-nums[i];
                if(diff2>diff){
                    diff=diff2;
                }
               }
            }
           
        } 
        return diff;
    }
};



// new lesson learnt 

//   maxdiff = max(maxdiff, nums[i] - nums[j]);