// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.
 

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false
 

// Constraints:

// 1 <= s.length, goal.length <= 100
// s and goal consist of lowercase English letters.






//BruteForce Approach :
class Solution {
public:
    bool rotateString(string s, string goal) {
         int n = s.size();
		string ans;
		
		for (int i = 0; i<n; i++) {
			for (int k = 0; k < n; k++) {
				ans.push_back(s[(i + k) % n]);
			}
			if (ans == goal) {
				return true;
                break;
			} else {
				ans.clear();
			}
		}
		return false;
    }
};




// Fully Optimised approach :
class Solution {
public:
    bool rotateString(string s, string goal) {
         if (s.size() != goal.size()){
            return false;
        }
        string s3 = s + s;

        return s3.find(goal) != string::npos;
    }
};

// return s3.find(s2) != string::npos;

// Let's understand it step by step.

// Case 1: s2 is found
// string s3 = "abcdabcd";
// string s2 = "cdab";
// s3.find(s2)

// returns:

// 2

// Now evaluate:

// 2 != string::npos

// which is:

// true

// So the function returns:

// return true;
// Case 2: s2 is not found
// string s2 = "abdc";
// s3.find(s2)

// returns:

// string::npos

// Now:

// string::npos != string::npos

// becomes:

// false
