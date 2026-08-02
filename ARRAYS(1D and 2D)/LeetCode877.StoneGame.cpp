// Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

// The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

// Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

// Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

 

// Example 1:

// Input: piles = [5,3,4,5]
// Output: true
// Explanation: 
// Alice starts first, and can only take the first 5 or the last 5.
// Say she takes the first 5, so that the row becomes [3, 4, 5].
// If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
// If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
// This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
// Example 2:

// Input: piles = [3,7,2,3]
// Output: true
 

// Constraints:

// 2 <= piles.length <= 500
// piles.length is even.
// 1 <= piles[i] <= 500
// sum(piles[i]) is odd.






//Greedy Approach :
// in this approach we simply make alice and bob pick the largest piles from the bothe ends for the row alternately,
// which satisfies the condition of the leetcode problem because alice always wins but does not stimulate the stone game originally as:
// in a stone game, you next move deepends upon your current move i.e, if the pile is [7,8,1,9] then
// alice should pick up 7 first as in hte next turn he'll be able to pick 8 instead of 1
// another example:
// Example:
// piles = {8, 15, 3, 7}
//
// Greedy:
// Alice -> 8
// Bob   -> 15
// Alice -> 7
// Bob   -> 3
// Alice = 15, Bob = 18 (loses)
//
// Optimal:
// Alice -> 7
// Bob   -> 8
// Alice -> 15
// Bob   -> 3
// Alice = 22, Bob = 11 (wins)

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int alice = 0;
        int bob = 0; 
        int low = 0;
        int high = piles.size()-1;
        int count = 1;
        while(low<=high){
            if(count==1){
                count = 0;
                if(piles[high]>piles[low]){
                    alice+=piles[high];
                    high--;
                }else if(piles[high]<piles[low]){
                    alice+=piles[low];
                    low++;
                }else{
                    alice+=piles[low];
                    low++;
                }
            }else if(count==0){
                count = 1;
                if(piles[high]>piles[low]){
                    bob+=piles[high];
                    high--;
                }else if(piles[high]<piles[low]){
                    bob+=piles[low];
                    low++;
                }else{
                    bob+=piles[low];
                    low++;
                }
            }
        }
        if(alice>bob){
            return true;
        }
        return false;
    }
};