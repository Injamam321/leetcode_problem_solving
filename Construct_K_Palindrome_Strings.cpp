// 1400. Construct K Palindrome Strings
// cpp Solution! problem-1400

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        // Base condition: If k is greater than the length of the string, it's impossible
        if (k > s.length()) return false;

        // Count the frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Count the number of characters with odd frequencies
        int oddCount = 0;
        for (auto it : freq) {
            if (it.second % 2 != 0) {
                oddCount++;
            }
        }

        // If the number of odd frequencies is greater than k, return false
        return oddCount <= k;
    }
};
