class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        if(idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = n - 1; i > idx; i--) {
            if(nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }

        reverse(nums.begin() + idx + 1, nums.end());
    }
};





// another approach
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int pivot = -1;
        int idx = -1;

        // Find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = nums[i];
                idx = i;
                break;
            }
        }

        // No pivot -> highest permutation
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

       vector<int> ext;

for (int i = idx + 1; i < n; i++) {
    ext.push_back(nums[i]);
}


sort(ext.begin(), ext.end());
int pivot2=-1;
        for (int i = 0; i < n ; i++) {
            if (ext[i]>pivot) {
                pivot2 = ext[i];
                break;
            }
        }

        // Swap with the RIGHTMOST occurrence of pivot2
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] == pivot2) {
                swap(nums[idx], nums[i]);
                break;
            }
        }

        reverse(nums.begin() + idx + 1, nums.end());
    }
};

//approach
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
