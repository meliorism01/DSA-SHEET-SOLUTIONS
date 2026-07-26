// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

 

// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
// Example 2:

// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]
 

// Constraints:

// 1 <= s.length <= 105
// s[i] is a printable ascii character.


//BruteForce Solution:
class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> temp;

        for (int i = s.size() - 1; i >= 0; i--) {
            temp.push_back(s[i]);
        }

        s = temp;
    }
};



// Optimised Solution:
// using two pointer approach
//one pointer at start and one at the end
//swapping the characters associated with both
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i =0, j = n-1;
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};