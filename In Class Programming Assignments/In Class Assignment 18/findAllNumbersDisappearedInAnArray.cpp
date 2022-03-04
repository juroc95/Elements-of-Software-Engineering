// Juhwan Lee
// CS300: Elements of Software Engineering
// Professor Fei Xie
// In Class Programming Assignment 18

#include <algorithm>

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> result;
        int temp = 1;
        for (int i = 0; i < size; ++i)
        {
            if (nums[i] != temp)
            {
                if (nums[i] > temp)
                {
                    result.push_back(temp);
                    ++temp;
                    --i;
                }
            }
            else
            {
                ++temp;
            }
        }
        while (temp <= size)
        {
            result.push_back(temp);
            ++temp;
        }
        return result;
    }
};