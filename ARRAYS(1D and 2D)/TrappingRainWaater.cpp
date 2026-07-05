//brute force
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;

        for (int i = 0; i < n; i++) {

            int leftMax = height[i];
            for (int j = i; j >= 0; j--) {
                leftMax = max(leftMax, height[j]);
            }

            int rightMax = height[i];
            for (int j = i; j < n; j++) {
                rightMax = max(rightMax, height[j]);
            }

            water += min(leftMax, rightMax) - height[i];
        }

        return water;
    }
};


//optimal approach:
class Solution {
public:
    int trap(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int water = 0;

        while (left <= right) {

            if (height[left] <= height[right]) {

                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    water += leftMax - height[left];

                left++;

            } else {

                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    water += rightMax - height[right];

                right--;
            }
        }

        return water;
    }
};




//optimal approach :
class Solution {
public:
    int trap(vector<int>& height) {
        int index = max_element(height.begin(), height.end()) - height.begin();
        int n =height.size();
        int rightmax = height[n - 1];
        int leftmax = height[0];
        int count = 0;

        for (int i = 1; i <= index; i++) {
            leftmax = max(leftmax, height[i]);
            count += leftmax - height[i];
        }

        for (int i = n - 2; i >= index; i--) {
            rightmax = max(rightmax, height[i]);
            count += rightmax - height[i];
        }
        return count;
    }
};