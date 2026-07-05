first attempt
class Solution {
public:
    void segregateElements(vector<int>& arr) {
        vector<int> pos;
        vector<int> neg;
        for (int i = 0;i < arr.size();i++) {
            if (arr[i] >= 0) {
                pos.push_back(arr[i]);
            }
            else if (arr[i] < 0) {
                neg.push_back(arr[i]);
            }
        }
        for (int j = 0;j < neg.size();j++) {
            pos.push_back(neg[j]);
        }
        arr.clear();
        for (int k = 0;k < pos.size();k++) {
            arr.push_back(pos[k]);
        }
    }
};
second attempt
class Solution {
public:
    void segregateElements(vector<int>& arr) {
        vector<int> pos;
        vector<int> neg;
        for (int i = 0;i < arr.size();i++) {
            if (arr[i] >= 0) {
                pos.push_back(arr[i]);
            }
            else if (arr[i] < 0) {
                neg.push_back(arr[i]);
            }
        }
        pos.insert(pos.end(), neg.begin(), neg.end());
        /* for(int j=0;j<neg.size();j++){
             pos.push_back(neg[j]);}*/

        arr.clear();
        for (int k = 0;k < pos.size();k++) {
            arr.push_back(pos[k]);
        }
    }
};
third attempt
class Solution {
public:
    void segregateElements(vector<int>& arr) {
        vector<int> pos;
        vector<int> neg;
        for (int i = 0;i < arr.size();i++) {
            if (arr[i] >= 0) {
                pos.push_back(arr[i]);
            }
            else if (arr[i] < 0) {
                neg.push_back(arr[i]);
            }
        }
        pos.insert(pos.end(), neg.begin(), neg.end());
        /* for(int j=0;j<neg.size();j++){
             pos.push_back(neg[j]);}

         arr.clear();
          for(int k=0;k<pos.size();k++){
             arr.push_back(pos[k]);
     }*/
        arr = pos;
    }
};