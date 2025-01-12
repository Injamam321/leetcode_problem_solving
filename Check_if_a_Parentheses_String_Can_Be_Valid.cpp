// 2116. Check if a Parentheses String Can Be Valid
// cpp Solution! problem-2116

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool canBeValid(string s, string locked) 
    {
        int n = s.length();
        
        // If the length is odd, it's impossible to balance
        if (n % 2 != 0) return false;
        
        int open = 0; // Number of open parentheses allowed
        int close = 0; // Number of close parentheses allowed
        
        // Forward pass
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0' || s[i] == '(') 
            {
                ++open; // Treat as an open parenthesis
            } 
            else 
            {
                --open; // Consume an open parenthesis
            }
            if (open < 0) return false; // Too many close brackets
        }
        
        open = 0;
        
        // Backward pass
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '0' || s[i] == ')') 
            {
                ++open; // Treat as a close parenthesis
            } 
            else 
            {
                --open; // Consume a close parenthesis
            }
            if (open < 0) return false; // Too many open brackets
        }
        
        return true; // Passed both checks
    }
};

// Time Complexity: 𝑂(𝑛), where n is the length of the string.
// Space Complexity: 𝑂(1), as no extra space is used.