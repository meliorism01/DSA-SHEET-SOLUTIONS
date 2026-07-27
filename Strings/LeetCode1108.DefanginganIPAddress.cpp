// 1108. Defanging an IP Address
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given a valid (IPv4) IP address, return a defanged version of that IP address.

// A defanged IP address replaces every period "." with "[.]".

 

// Example 1:

// Input: address = "1.1.1.1"
// Output: "1[.]1[.]1[.]1"
// Example 2:

// Input: address = "255.100.50.0"
// Output: "255[.]100[.]50[.]0"
 

// Constraints:

// The given address is a valid IPv4 address.



//BruteForce Approach:
// Time Complexity -> O(n^2){because Every time you do:
// address.replace(i, 1, "[.]");
// the string becomes longer, and all the characters after i have to be shifted to the right.
// If there are many . characters, this shifting happens repeatedly, leading to O(n²) time in the worst case.}
// Space Complexity : O(1);
// '' is used for single character string i.e. string literal, and "" is used for multicharacter string.
class Solution {
public:
    string defangIPaddr(string address) {
        for(int i =0; i<address.size(); i++){
            if(address[i]=='.'){
                address.replace(i, 1, "[.]");
                i+=2;
            }
        }
        return address;
    }
};




//Optimised Solution
//Time Complexity : O(n), Space Complexity O(n)
// Learnings :
// We cant use push_back() function to push a string
// Either use : ans += "[.]"; or ans.append("[.]")

class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for (auto x : address) {
            if (x == '.') {
                ans.append("[.]");
            } else {
                ans.push_back(x);
            }
        }
        return ans;
    }
};