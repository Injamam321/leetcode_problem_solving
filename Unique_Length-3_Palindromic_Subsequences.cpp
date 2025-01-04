// 1930. Unique Length-3 Palindromic Subsequences
// cpp Solution! problem-1930

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int countPalindromicSubsequence(string s) 
    {
        vector<int> first(26, -1), last(26, -1);
        int n = s.size();
        for (int i = 0; i < n; ++i) 
        {
            if (first[s[i] - 'a'] == -1) 
            {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }

        unordered_set<string> palindromes;

        for (int i = 0; i < 26; ++i) 
        {
            if (first[i] != -1 && last[i] != -1 && first[i] < last[i]) 
            {
                unordered_set<char> middleChars;
                for (int j = first[i] + 1; j < last[i]; ++j) 
                {
                    middleChars.insert(s[j]);
                }

                for (char c : middleChars) 
                {
                    string palindrome = "";
                    palindrome += (char)(i + 'a');
                    palindrome += c;
                    palindrome += (char)(i + 'a');
                    palindromes.insert(palindrome);
                }
            }
        }

        return palindromes.size();
    }
};

int main() 
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    Solution solution;
    int result = solution.countPalindromicSubsequence(s);

    cout << "Number of unique palindromic subsequences of length 3: " << result << endl;
    return 0;
}
