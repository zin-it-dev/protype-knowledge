#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Running Sum of 1D Array - LeetCode 1480
    // https://leetcode.com/problems/running-sum-of-1d-array/
    // Time Complexity: O(n) - where n is the number of elements in the input array
    // Space Complexity: O(1) - modifying the input array in place
    vector<int> runningSum(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
        return nums;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 1, 2, 10, 1};

    vector<int> result = solution.runningSum(nums);

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << "\t";
    }

    return 0;
}