// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
 

// Constraints:

// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.



//BruteForce Solution:

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size();) {
            if (isupper(s[i])) {
                s[i] = tolower(s[i]);
                i++;
            } else if (islower(s[i])) {
                i++;
            } else if (s[i] >= '0' && s[i] <= '9') {
                i++;
            } else {
            s.erase(s.begin() + i);
        }
        }
         int x = s.size();
    string temp;
    for (int i = x - 1; i >= 0; i--) {
        temp.push_back(s[i]);
    }
    if (temp == s) {
        return true;
    }
    return false;
    }
  
}
;


//Optimised Approach:
// using isalnum() function 
// instead of using two different functions for lowercase letters and integers(numbers)
class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size();) {
            if (isupper(s[i])) {
                s[i] = tolower(s[i]);
                i++;
            } else if (isalnum(s[i])) {
                i++;
            } else {
            s.erase(s.begin() + i);
        }
        }
         int x = s.size();
    string temp;
    for (int i = x - 1; i >= 0; i--) {
        temp.push_back(s[i]);
    }
    if (temp == s) {
        return true;
    }
    return false;
    }
  
}
;



//Even Optimised Approach:
// uses lesser time than the previous algorithm
// no use of erase function which takes extra time and increases time complexity

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string x;
        for(int i = 0; i < n; i++){
            if(isalnum(s[i])){
                x.push_back(tolower(s[i]));
            }
        }
        string temp;
        for(int i =x.size()-1; i>=0; i--){
            temp.push_back(x[i]);
        }
        if(x==temp){
            return true;
        }
        return false;
    }
};



//Fully Optimal approach:
// used continue in this part :
            // if(!isalnum(s[i])){
            //     i++;
            //     continue;
            // }
            // if(!isalnum(s[j])){
            //     j--;
            //     continue;
// because:
// What goes wrong?

// Suppose:

// s = ".,"

// Initially:

// i = 0
// j = 1

// Iteration:

// s[i] = '.' → not alphanumeric → i++ → i = 1
// s[j] = ',' → not alphanumeric → j-- → j = 0

// Now your code still executes:

// tolower(s[i]) == tolower(s[j])

// even though i > j.

// On other inputs, i can even become s.size(), causing the heap-buffer-overflow.

// Correct approach

// After skipping invalid characters, you must restart the loop instead of immediately comparing.
class Solution {
public:
    bool isPalindrome(string s) {
         int i = 0;
         int j = s.length()-1;
          while(i<j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            if(tolower(s[i])==tolower(s[j])){
                i++; 
                j--;
            }else{
                return false;
            }
          }
          return true;
    }
};