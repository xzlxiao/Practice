#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
        size_t s_size = s.size();
        int i = 0;
        string max_str, tmp_str;
        int max_num = 0, tmp_num = 0;
        bool isRep = false;
        while (i < s_size)
        {
                if(s_size == 1)
                {
                        tmp_str.push_back(s.at(i));
                        ++tmp_num;
                        max_num = tmp_num;
                        max_str = tmp_str;
                        break;
                }
                if (tmp_num == 0)
                {
                        tmp_str.push_back(s.at(i));
                        ++tmp_num;
                        ++i;
                }
                else if(tmp_num > 0)
                {
                        for (int j = 0; j < tmp_num; ++j)
                        {
                                if (tmp_str.at(j) == s.at(i))
                                {
                                        isRep = true;
                                        break;
                                }
                                else
                                        isRep = false;
                        }
                        if (isRep == true)
                        {
                                if (tmp_num > max_num)
                                {
                                        max_num = tmp_num;
                                        max_str = tmp_str;
                                }
                                tmp_num = 0;
                                tmp_str.clear();
                        }
                        else if (i == (s_size - 1))
                        {
                                tmp_num++;
                                tmp_str.push_back(s.at(i));
                                if (tmp_num > max_num)
                                {
                                        max_num = tmp_num;
                                        max_str = tmp_str;
                                }
                                break;
                        }
                        else
                        {
                                tmp_str.push_back(s.at(i));
                                ++tmp_num;
                                ++i;
                        }
                }
        }
        cout << "MAX_LENGTH: " << max_num << endl;
        cout << "MAX_STRING: " << max_str << endl;
        return max_num;
}

int main()
{
        string str = "px";
        lengthOfLongestSubstring(str);
        return 0;
}