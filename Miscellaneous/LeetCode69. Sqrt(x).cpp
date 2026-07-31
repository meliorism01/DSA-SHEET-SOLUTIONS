// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

// Example 1:

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.
// Example 2:

// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

// Constraints:

// 0 <= x <= 231 - 1


//BruteForce Approach:
// using the conditon that if i*i>x, returning i - 1
// because if a value doesnt have a perfect square root, and has a float square root
// the square root will be rounded to the floor value
// and in case of perfect square root, we use the condition i*i==x, returning i;
// Time Complexity : O(n)
class Solution {
public:
    int mySqrt(int x) {
        for(long i =0; i<=x; i++){
                if((i*i)>x){
                    return i-1;
                }else if((i*i)==x){
                    return i;
                }
        }
        return 0;
    }
};


//Optimal Approach:
// using Binary Search
// Time complexity : O(logn), but creates a significantly large difference from the bruteforce approach 
// as the given constraints are 0 <= x <= 231 - 1

class Solution {
public:
    int mySqrt(int x) {
       long start = 0;
       long end = x;
       while(start<=end){
        long mid = (start+end)/2;
        if((mid*mid)>x&&((mid-1)*(mid-1))<x){
                    return mid-1;
                }else if((mid*mid)==x){
                    return mid;
                }else if((mid*mid)>x){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
       }
        return 0;
    }
};