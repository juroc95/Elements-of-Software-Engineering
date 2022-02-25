// Juhwan Lee
// CS300: Elements of Software Engineering
// Professor Fei Xie
// In Class Programming Assignment 16

#include <algorithm>

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int size = nums.size();
        int counter;
        if (size >= 1)
            counter = 1;
        else
            counter = 0;
        vector<int> results;
        for (int i = 0; i + 1 < size; ++i)
        {
            if (nums[i] < nums[i + 1])
                ++counter;
            else
            {
                results.push_back(counter);
                counter = 1;
            }
        }
        results.push_back(counter);
        int result = *max_element(results.begin(), results.end());
        return result;
    }
};