class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        for(int i=0; i<a.size(); i++){
            for(int j=i+1; j<a.size(); j++){
                if(a[i]==a[j]){
                    a.erase(a.begin() + j);
                    j--;
                }
            }
        }
        for(int i=0; i<b.size(); i++){
            bool found=false;
            for(int j=0; j<a.size();j++){
                if(b[i]==a[j]){
                    found= true;
                }
            }
            if(!found){
                a.push_back(b[i]);
            }
        }
        sort(a.begin(),a.end());
        return a;
    }
};


// 2nd approach: