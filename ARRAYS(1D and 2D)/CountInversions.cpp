// brute force:
class Solution {
  public:
    int inversionCount(vector<int> &arr) {
   int count;
        for(int i=0; i<arr.size(); i++){
            for(j=i+1;j<arr.size(); j++){
                if(i<j&&arr[i]>arr[j]){
                    count++;
                }
            }
        }
        
    }
};