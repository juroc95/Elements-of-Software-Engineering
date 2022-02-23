// Juhwan Lee
// CS300: Elements of Software Engineering
// Professor Fei Xie
// In Class Programming Assignment 14

#include <algorithm>

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> result;
        int size = nums.size();
        if (size == 0)
            return result;
        int previous = nums[0];
        for (int i = 1; i < size; ++i)
        {
            if (previous == nums[i])
            {
                result.push_back(nums[i]);
                previous = nums[i];
            }
            previous = nums[i];
        }
        return result;
    }
};