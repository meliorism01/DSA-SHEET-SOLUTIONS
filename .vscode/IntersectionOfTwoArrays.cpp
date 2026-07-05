// brute force approach:
// in this approach we used two loops over two vectors and appliied condition if the elements are same but we have to apply another condition too, (if there are two same elements in both the arrays, still it will be printed one time(important).
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> arr;

        for(int i = 0; i < nums1.size(); i++){

            if(i > 0 && nums1[i] == nums1[i-1]) //important condition.
                continue;

            for(int j = 0; j < nums2.size(); j++){

                if(nums1[i] == nums2[j]){
                    arr.push_back(nums1[i]);
                    break;
                }

            }
        }

        return arr;
    }
};

// OPTIMAL APPROACH:
// using set container of cpp STL as it stores unique elements only.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> s;
        vector<int> ans;

        for(int x : nums1){
            s.insert(x);
        }

        for(int x : nums2){
            if(s.count(x)){ //s.count checks if x(element) is there in the set(unique elements from nums1 vector) or not.
                ans.push_back(x);
                s.erase(x);//s.erase(x) deletes the element x from the set s.

// 2️⃣ After deleting, the set no longer contains x, so s.count(x) will return 0.

// 3️⃣ Therefore, if the same number appears again in nums2, the condition fails and it is not added again to the result, preventing duplicates
            }
        }

        return ans;
    }
};