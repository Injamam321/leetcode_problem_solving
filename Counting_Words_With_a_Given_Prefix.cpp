// 2185. Counting Words With a Given Prefix
// cpp Solution! problem-2185

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (const string& word : words) {
            // Check if the current word starts with the prefix 'pref'
            if (word.substr(0, pref.length()) == pref) {
                count++;
            }
        }
        return count;
    }
};