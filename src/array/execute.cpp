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

    // Fizz Buzz - LeetCode 412
    // https://leetcode.com/problems/fizz-buzz/
    // Time Complexity: O(n) - where n is the input number
    // Space Complexity: O(1) - excluding the space required for the output list
    vector<string> fizzBuzz(int n)
    {
        vector<string> result;
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 && i % 5 == 0)
            {
                result.push_back("FizzBuzz");
            }
            else if (i % 3 == 0)
            {
                result.push_back("Fizz");
            }
            else if (i % 5 == 0)
            {
                result.push_back("Buzz");
            }
            else
            {
                result.push_back(to_string(i));
            }
        }
        return result;
    }

    // Number of Steps to Reduce a Number to Zero - LeetCode 1342
    // https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero
    // Time Complexity: O(log n) - where n is the input number
    // Space Complexity: O(1) - using only a constant amount of extra space
    int numberOfSteps(int num)
    {
        int steps = 0;
        while (num > 0)
        {
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else
            {
                num -= 1;
            }
            steps++;
        }
        return steps;

        // Recursive Approach
        // Time Complexity: O(log n) - where n is the input number
        // Space Complexity: O(log n) - due to the recursion stack
        // if (num == 0) return 0;
        // if (num % 2 == 0) {
        //     return 1 + numberOfSteps(num / 2);
        // } else {
        //     return 1 + numberOfSteps(num - 1);
        // }
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

    // Fizz Buzz
    vector<string> fizzBuzzResult = solution.fizzBuzz(15);

    cout << "Fizz Buzz Result:" << endl;
    for (const string &s : fizzBuzzResult)
    {
        cout << s << endl;
    }

    // Number of Steps to Reduce a Number to Zero
    int steps = solution.numberOfSteps(14);
    cout << "Number of Steps to Reduce 14 to Zero: " << steps << endl;

    return 0;
}