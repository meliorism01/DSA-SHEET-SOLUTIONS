//bruteforce
class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        vector<int>v;
        for(int i =0; i<a.size(); i++){
            for(int j =0; j<b.size(); j++){
                if(a[i]==b[j]){
                    v.push_back(a[i]);
                }
            }
        }
        for (int i = 0; i < v.size(); ) {
    bool found = false;

    for (int j = 0; j < c.size(); j++) {
        if (v[i] == c[j]) {
            found = true;
            break;
        }
    }

    if (!found)
        v.erase(v.begin() + i);
    else
        i++;
}
        set<int>s(v.begin(),v.end());
        v.clear();
        v.insert(v.end(), s.begin(), s.end());
        return v;
    }
};


//optimised
class Solution {
public:
    vector<int> commonElements(vector<int>& a, vector<int>& b, vector<int>& c) {

        vector<int> ans;
        int i = 0, j = 0, k = 0;

        while (i < a.size() && j < b.size() && k < c.size()) {

            if (a[i] == b[j] && b[j] == c[k]) {

                if (ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);

                i++;
                j++;
                k++;
            }
            else if (a[i] < b[j])
                i++;
            else if (b[j] < c[k])
                j++;
            else
                k++;
        }

        return ans;
    }
};