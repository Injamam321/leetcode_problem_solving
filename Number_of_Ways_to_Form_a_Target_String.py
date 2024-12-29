# 1639. Number of Ways to Form a Target String Given a Dictionary
# Python3 Solution! problem-1639

from collections import defaultdict
from functools import lru_cache

class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        MOD = 10**9 + 7
        m, n = len(words), len(words[0])  # Number of words and length of each word
        t_len = len(target)

        # Step 1: Count frequency of each character in each column of words
        freq = [defaultdict(int) for _ in range(n)]
        for word in words:
            for i, char in enumerate(word):
                freq[i][char] += 1

        # Step 2: Dynamic programming table
        dp = [[0] * (t_len + 1) for _ in range(n + 1)]
        dp[0][0] = 1  # Base case: 1 way to form empty target

        # Step 3: Fill the DP table
        for i in range(1, n + 1):  # Iterate over columns
            for j in range(t_len + 1):  # Iterate over target characters
                dp[i][j] = dp[i - 1][j]  # Skip current column
                if j > 0 and target[j - 1] in freq[i - 1]:
                    dp[i][j] += dp[i - 1][j - 1] * freq[i - 1][target[j - 1]]
                    dp[i][j] %= MOD

        # Step 4: Return the result
        return dp[n][t_len]
