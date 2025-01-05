// 2381. Shifting Letters II
// cpp Solution! problem-2381

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        int n = s.size();
        vector<int> delta(n + 1, 0);

        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int change = (direction == 1) ? 1 : -1;
            delta[start] += change;
            delta[end + 1] -= change;
        }
        int cumulative = 0;
        for (int i = 0; i < n; ++i) 
        {
            cumulative += delta[i];
            int newChar = ((s[i] - 'a') + cumulative) % 26; 
            if (newChar < 0) newChar += 26; 
            s[i] = 'a' + newChar;
        }

        return s;
    }
};
int main() 
{
    Solution solution;
    string s = "abc";
    vector<vector<int>> shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
    string result = solution.shiftingLetters(s, shifts);
    cout << "Resulting string: " << result << endl; 
    return 0;
}