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

    // Richest Customer Wealth - LeetCode 1672
    // https://leetcode.com/problems/richest-customer-wealth/
    // Time Complexity: O(m * n) - where m is the number of customers and n is the number of banks
    // Space Complexity: O(1) - using only a constant amount of extra space
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int maxWealth = 0;
        for (const auto &customer : accounts)
        {
            int currentWealth = 0;
            for (int bankBalance : customer)
            {
                currentWealth += bankBalance;
            }
            maxWealth = max(maxWealth, currentWealth);
        }
        return maxWealth;
    }
};

int main()
{
    Solution solution;

    // Running Sum of 1D Array
    vector<int> nums = {3, 1, 2, 10, 1};

    vector<int> result = solution.runningSum(nums);

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << "\t";
    }

    // Richest Customer Wealth
    vector<vector<int>> accounts = {
        {7, 1, 3},
        {2, 8, 1},
        {1, 9, 5}};

    int richestWealth = solution.maximumWealth(accounts);
    cout << "\nRichest Customer Wealth: " << richestWealth << endl;

    return 0;
}