// bruteforce approach:


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        int t;
        t=k;
       while(k>0){
        for(int i =nums.size()-1; i>0 ; i--){ 
            ans.push_back(nums[i]);
            nums.erase(nums.begin() + i);
            k--;
        }
    }
    for(int i=0; i<nums.size(); i++){
        ans.push_back(nums[i]);
        nums.erase(nums.begin() + i);
    }
    
    nums = ans;
   reverse(nums.begin(),nums.begin()+t);
       reverse(nums.begin()+t,nums.end());
    }
};

//another brute force approach:
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        vector<int> ans;

        for(int i = n-k; i < n; i++) {
            ans.push_back(nums[i]);
        }

        nums.erase(nums.begin() + (n-k), nums.end());

        nums.insert(nums.begin(), ans.begin(), ans.end());
    }
};

// optimal approach:

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
}; 
100xsystems

// another approach
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int a = k % n;

        for (int i = n - a; i < n; i++) {
            ans.push_back(nums[i]);
        }

        for (int i = 0; i < n - a; i++) {
            ans.push_back(nums[i]);
        }

        nums = ans;
    }
};

//another approach 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n = nums.size();
       k%=n;
       int a=n-k;
       reverse(nums.begin(), nums.end()-k);
       reverse(nums.begin()+a, nums.end());
       reverse(nums.begin(), nums.end());
    }
};


// the main pattern in array rotation is regarding the key k, as if key is greater than the nums.size then its miserable to do n-k,, so instead of that we do k%n

The pattern in this question is about splitting the array into two parts and swapping their order.

Right Rotation by k

// Suppose:

// nums = [1,2,3,4,5,6,7]
// k = 3

// The last 3 elements should come to the front.

// Split the array into two parts:

// [1,2,3,4] | [5,6,7]
//     A      |    B

// After rotation:

// B + A

// [5,6,7,1,2,3,4]

// Notice:

// B contains the last k elements.
// A contains the first n-k elements.

// That's why the code is:

// for (int i = n-k; i < n; i++)   // Copy B
//     ans.push_back(nums[i]);

// for (int i = 0; i < n-k; i++)   // Copy A
//     ans.push_back(nums[i]);
// Another Example
// nums = [10,20,30,40,50]
// k = 2

// Split:

// [10,20,30] | [40,50]
//       A     |    B

// Result:

// [40,50,10,20,30]

// Again:

// B = last k elements
// A = remaining elements
// Left Rotation Pattern

// If the question asked to rotate left by k, then the split is different.

// Example:

// nums = [1,2,3,4,5,6,7]
// k = 3

// Split:

// [1,2,3] | [4,5,6,7]
//     A    |     B

// Result:

// B + A

// [4,5,6,7,1,2,3]

// Code:

// for (int i = k; i < n; i++)
//     ans.push_back(nums[i]);

// for (int i = 0; i < k; i++)
//     ans.push_back(nums[i]);
// General Pattern
// Right Rotate by k
// Original:

// |------ n-k ------|---- k ----|
//        A                B

// Answer:

// B + A

// Starting index = n - k

// Left Rotate by k
// Original:

// |---- k ----|------ n-k ------|
//       A              B

// Answer:

// B + A

// Starting index = k

// Trick to remember

// Ask yourself:

// Right rotation → "Which elements move to the front?"
// ➜ The last k elements → start at n - k.
// Left rotation → "Which elements move to the back?"
// ➜ The first k elements → start at k.