// Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

// Example 1:

// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5
// Example 2:

// Input: c = 3
// Output: false
 

// Constraints:

// 0 <= c <= 231 - 1



//BruteForce Approach :
// given: a^2 + b^2 = c.
// i.e. a&b must lie in between 0 to sqrt(c);
// give TLE(time limit error) because of poor optimisation and time complexity i.e. O(n^2)
class Solution {
public:
    bool judgeSquareSum(int c) {
        int n = sqrt(c);
        for(long i =0; i<=n; i++){
            for(long j =0; j<=n; j++){
                if(i*i+j*j==c){
                    return true;
                }
            }
        }
        return false;
    }
};


// Another BruteForce Approach(a bit optimised):
// if exact natural number b exits for any among all natural numbers  c-(i*i), it gives true
// else if it is decimal(perfect number doesnt exist), it gives false
class Solution {
public:
    bool judgeSquareSum(int c) {
        int n = sqrt(c);
        for(long i =0; i<=n; i++){
            double b = sqrt(c-(i*i));
            if(floor(b)==b){
                return true;
            }
        }
        return false;
    }
};




//Optimised Solution :
// using binary search
// two pointer approach
class Solution {
public:
    bool judgeSquareSum(int c) {
        long high = sqrt(c);
        long low = 0;
        while(low<=high){
            long sum = (high*high)+(low*low);
            if(sum==c){
                return true;
                break;
            }else if(sum<c){
                low++;
            }else{
                high--;
            }
        }
        return false;
    }
};