//Binary Search is an algorithm that is only applicable on a sorted data structure,
// It fundamentally searchs the required element lexicographically(like in a dictionary).
// whenever we are given an element to search we check weather it occurs in the first half of the dTA STRUCTURE 
// OR in the second half of the data structure
// and we apply the pointers accordingly
// Example:
// Array: [2, 5, 8, 12, 16, 23, 38]
// Target: 16
// Step	low	high	mid	arr[mid]	Action
// 1	0	6	3	12	12 < 16 → low = 4
// 2	4	6	5	23	23 > 16 → high = 4
// 3	4	4	4	16	✅ Found at index 4
// Pointer Visualization
// Step 1
// L      M        H
// ↓      ↓        ↓
// 2  5  8  12 16 23 38
// Step 2
//             L  H
//             ↓  ↓
// 2  5  8  12 16 23 38
//                ↑
//                M
// Step 3
//             L/M/H
//               ↓
// 2  5  8  12 16 23 38
// Result: Target 16 found at index 4.



// Iterative Binary Search:
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size() - 1;
        int low = 0;
        int ans = -1;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                break;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};


//Recursive Binary Search :
class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        if (low > high)
            return -1;

        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] > target)
            return binarySearch(nums, low, mid - 1, target);

        return binarySearch(nums, mid + 1, high, target);
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};