/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

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


class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> maps;
        char maps[10][5] = {{'a', 'b', 'c'},
                            {'d', 'e', 'f'},
                            {'g', 'h', 'i'},
                            {'j', 'k', 'l'},
                            {'m', 'n', 'o'},
                            {'p', 'q', 'r', 's'},
                            {'t', 'u', 'v'},
                            {'w', 'x', 'y', 'z'}};
       
        string tmp;
        vector<string> result;
        for (string::iterator iter = digits.begin(); iter != digits.end(); ++iter)
        {
            tmp = maps[int(*iter) - 2];
            for (int i = 0; i < tmp.size(); i++)
            {
                if (result.empty())
                {

                }
                for (vector<string>::iterator v_it=result.begin(); v_it != result.end(); ++v_it)
                {
                    v_it->append(tmp[i]);

                }
            }
        }

    }
};
// @lc code=end

