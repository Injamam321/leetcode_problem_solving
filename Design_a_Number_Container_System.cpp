// 2349. Design a Number Container System
// cpp Solution! problem-2349

#include <bits/stdc++.h>
using namespace std;

class NumberContainers
{
public:
    unordered_map<int, set<int>> smallestindex;
    unordered_map<int, int> Index;
    NumberContainers()
    {
    }

    void change(int index, int number)
    {
        if (Index.find(index) != Index.end())
        {
            int prevnumber = Index[index];
            smallestindex[prevnumber].erase(index);
            if (smallestindex[prevnumber].empty())
                smallestindex.erase(prevnumber);
        }
        Index[index] = number;
        smallestindex[number].insert(index);
    }

    int find(int number)
    {
        if (smallestindex.find(number) == smallestindex.end())
            return -1;
        else
            return *smallestindex[number].begin();
    }
};
