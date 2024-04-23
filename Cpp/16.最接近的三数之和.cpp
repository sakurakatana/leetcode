/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <iterator>
#include <string>
#include <map>
#include <set>
#include <functional>

using namespace std;

// @lc code=start
int binary_search(vector<int>& nums, int value, int start, int sum, int target);

class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int mins = 100000;
        int result;
        int tmp; 
        int diff;
        stable_sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = -1;
            int target_diff = -1;
            for (int j = i + 1; j < nums.size(); j++)
            {
                sum = nums[i] + nums[j];
                target_diff = target - sum;
                tmp = binary_search(nums, target_diff, j + 1, sum, target);
                diff = abs(target - tmp);
                if (mins > diff)
                {
                    mins = diff;
                    result = tmp;
                }
            }
        }
        return result;
    }
};

int binary_search(vector<int>& nums, int value, int start, int sum, int target)
{
    int l = start;
    int r = nums.size() - 1;
    int index = -1;
    while (l <= r)
    {
        index = (l + r) / 2;
        if (nums[index] < value)
            l = index + 1;
        else
            r = index - 1;
    }
    int result = 1000000, tmp_min = 1000000;
    if (l < nums.size() and l >= start)
    {
        int diff = abs(target - sum - nums[l]);
        if (tmp_min > diff)
        {
            tmp_min = diff;
            result = sum + nums[l];
        }
    }
    if (r < nums.size() and r >= start)
    {
        int diff = abs(target - sum - nums[r]);
        if (tmp_min > diff)
        {
            tmp_min = diff;
            result = sum + nums[r];
        }
    }
    return result;
}

// @lc code=end