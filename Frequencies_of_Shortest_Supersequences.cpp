// 3435. Frequencies of Shortest Supersequences
// cpp Solution! problem-3435

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> supersequences(vector<string> &words)
    {
        sort(words.begin(), words.end());
        vector<int> bg(26, -1), ed(26, 0);
        map<string, bool> mp;
        map<char, bool> mp2;
        for (auto &x : words)
        {
            mp[x] = true;
            mp2[x[0]] = mp2[x[1]] = true;
        }
        vector<int> tans(26, 0);
        for (char c = 'a'; c <= 'z'; c++)
        {
            string aux = "";
            aux += c;
            aux += c;
            if (mp.count(aux))
            {
                tans[c - 'a'] = 2;
            }
            else if (mp2.count(c))
            {
                tans[c - 'a'] = 1;
            }
        }
        vector<string> wtc;
        for (auto &x : words)
        {
            if (tans[x[0] - 'a'] != 2 && tans[x[1] - 'a'] != 2)
            {
                wtc.push_back(x);
            }
        }
        for (int i = 0; i < wtc.size(); i++)
        {
            int l = wtc[i][0] - 'a';
            if (bg[l] == -1)
                bg[l] = i;
            ed[l] = i;
        }
        vector<vector<int>> ans;
        if (wtc.size() == 0)
        {
            ans.push_back(tans);
            return ans;
        }
        else
        {
            vector<int> ns;
            for (int i = 0; i < 26; i++)
            {
                if (tans[i] == 1)
                    ns.push_back(i);
            }
            vector<int> gm;

            for (int i = 0; i < (1 << ns.size()); i++)
            {
                vector<int> indg(26);
                for (int j = 0; j < ns.size(); j++)
                {
                    if (i & (1 << j))
                    {
                        tans[ns[j]] = 2;
                    }
                    else
                    {
                        tans[ns[j]] = 1;
                    }
                }
                for (auto &w : wtc)
                {
                    if (tans[w[0] - 'a'] != 2 && tans[w[1] - 'a'] != 2)
                    {
                        indg[w[1] - 'a']++;
                    }
                }
                // dfs check cycle
                vector<int> chk;
                for (int i = 0; i < 26; i++)
                {
                    if (indg[i] == 0 && tans[i] == 1)
                        chk.push_back(i);
                }
                while (chk.size())
                {
                    int u = chk.back();
                    chk.pop_back();
                    if (bg[u] == -1)
                        continue;
                    for (int i = bg[u]; i <= ed[u]; i++)
                    {
                        int l = wtc[i][1] - 'a';
                        if (tans[l] == 2)
                            continue;
                        indg[l]--;
                        if (indg[l] == 0)
                            chk.push_back(l);
                    }
                }
                if (*max_element(indg.begin(), indg.end()) == 0)
                    gm.push_back(i);
            }

            int minb = 20;
            for (auto &x : gm)
            {
                minb = min(minb, __builtin_popcount(x));
            }
            for (auto &x : gm)
            {
                if (__builtin_popcount(x) == minb)
                {
                    for (int j = 0; j < ns.size(); j++)
                    {
                        if (x & (1 << j))
                        {
                            tans[ns[j]] = 2;
                        }
                        else
                        {
                            tans[ns[j]] = 1;
                        }
                    }
                    ans.push_back(tans);
                }
            }
            return ans;
        }
    }
};