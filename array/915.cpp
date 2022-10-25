#include <vector>

// 分割数组
class Solution {
public:
    int partitionDisjoint(std::vector<int>& nums) {
        // 连续数组，划分为连续的left 和 right, 返回left的长度
        // 1.left的长度要尽可能的小
        // 2.要求非空且left right都连续
        // 3.而且每个元素都要小于或者等于right的元素
        int curMax = nums[0];
        int leftMax = nums[0];
        int leftPos = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > curMax) curMax = nums[i];
            // left要尽可能的短，所以一定是要比上一轮的最大值小，才不得不加进去
            if (nums[i] < leftMax) 
            {
                leftMax = curMax;
                leftPos = i + 1;
            }
        }
        return leftPos;

        // 这道题的思路在于，确定的点，一定有一个分割的方案
    }
};