// 2375. Construct Smallest Number From DI String
// cpp Solution! problem-2375

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "1", temp;
        for (int i = 0; i < pattern.size(); i++) {
            if (pattern[i] == 'I') 
                ans += temp + char(i + '2'), temp = ""; // Flush temp and add next
            else 
                temp = char(ans.back()) + temp, ans.pop_back(), ans += char(i + '2'); // Store in temp
        }
        return ans + temp;
    }
};
