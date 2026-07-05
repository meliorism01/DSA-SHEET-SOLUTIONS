//brute force approaach

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max = INT_MIN;
        int row = -1;
        for(int i =0; i<mat.size(); i++){
            int freq=0;
            for(int j =0; j<mat[0].size(); j++){
                if(mat[i][j]==1){
                    freq++;
                }
            }
            if(freq>max){
                max= freq;
                row = i;
            }
        }     
        vector <int> ans;
        ans.push_back(row);
        ans.push_back(max);
        
        return ans;
    }
};

