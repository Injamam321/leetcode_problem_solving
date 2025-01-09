// 3042. Count Prefix and Suffix Pairs I
// cpp Solution! problem-3042

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int countPrefixSuffixPairs(vector<string>& words) 
    {
        int count = 0;
        int n = words.size();

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (i < j) 
                {
                    string prefix = words[i];
                    string target = words[j];
                    
                    // Check if prefix is both a prefix and a suffix of the target
                    if (target.substr(0, prefix.size()) == prefix && 
                        target.substr(target.size() - prefix.size()) == prefix) 
                        {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};