// use the concept that the sequence(ascending) will break(an element will be greater than it's preceding element).
// eg: Example 1:

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
// Example 2:

// Input: nums = [2,1,3,4]
// Output: false
// Explanation: There is no sorted array once rotated that can make nums.
// Example 3:

// Input: nums = [1,2,3]
// Output: true
// Explanation: [1,2,3] is the original sorted array.
    // You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
    #include <iostream>
using namespace std;
bool checkIfAnArrayIsSortedAndRotated(vector<int>& A) {
    int n = A.size();
    int count=0;
    for(int i =0; i<n; i++){

        if(nums[i]>nums[(i+1)%n]){
            count++;
        } // checks the pairs of consecutive elemens and the % is used to compare the first and last digit.
        //nums = [3,4,5,1,2]
       // n = 5
      //  | i | (i+1)%n | Compared elements |
//| - | ------- | ----------------- |
//| 0 | 1       | 3 vs 4            |
//| 1 | 2       | 4 vs 5            |
//| 2 | 3       | 5 vs 1            |
//| 3 | 4       | 1 vs 2            |
//| 4 | 0       | 2 vs 3            |

    }
    if(count==1){
        return true;
    }else{return false;}
}