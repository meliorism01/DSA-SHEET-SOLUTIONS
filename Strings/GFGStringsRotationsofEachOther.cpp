// You are given two strings s1 and s2, of equal lengths. The task is to check if s2 is a rotated version of the string s1.

// Note: A string is a rotation of another if it can be formed by moving characters from the start to the end (or vice versa) without rearranging them.

// Examples :

// Input: s1 = "abcd", s2 = "cdab"
// Output: true
// Explanation: After 2 right rotations, s1 will become equal to s2.
// Input: s1 = "aab", s2 = "aba"
// Output: true
// Explanation: After 1 left rotation, s1 will become equal to s2.
// Input: s1 = "abcd", s2 = "acbd"
// Output: false
// Explanation: Strings are not rotations of each other.
// Constraints:
// 1 ≤ s1.size(), s2.size() ≤ 105
// s1, s2 consists of lowercase English alphabets.






// BruteForce Approach:
// using %(modulo operator) for the circular traversal
// Time Complexity: O(n²)
// Space Complexity: O(n)

class Solution {
	public:
	bool areRotations(string &s1, string &s2) {
		int n = s1.size();
		string ans;
		
		for (int i = 0; i<n; i++) {
			for (int k = 0; k < n; k++) {
				ans.push_back(s1[(i + k) % n]);
			}
			if (ans == s2) {
				return true;
                break;
			} else {
				ans.clear();
			}
		}
		return false;
	}
};


//Optimal Solution :

class Solution {
public:
    bool areRotations(string &s1, string &s2) {

        if (s1.size() != s2.size()){
            return false;
        }
        string s3 = s1 + s1;

        return s3.find(s2) != string::npos;
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
