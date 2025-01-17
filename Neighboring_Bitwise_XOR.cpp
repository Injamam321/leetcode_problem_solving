// 2683. Neighboring Bitwise XOR
// cpp Solution! problem-2683

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        // Count the number of set bits in num2
        int count2 = __builtin_popcount(num2);

        int x = 0;
        // Set bits of x based on num1
        for (int i = 31; i >= 0 && count2 > 0; --i)
        {
            if (num1 & (1 << i))
            {
                x |= (1 << i);
                --count2;
            }
        }

        // Add extra bits if needed
        for (int i = 0; i <= 31 && count2 > 0; ++i)
        {
            if (!(x & (1 << i)))
            {
                x |= (1 << i);
                --count2;
            }
        }

        return x;
    }
};

// Complexity:

// Time Complexity: 𝑂(32), as we iterate over 32 bits in the worst case.
// Space Complexity: 𝑂(1), as we use a constant amount of extra space.