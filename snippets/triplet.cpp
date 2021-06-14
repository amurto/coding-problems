#include<bits/stdc++.h>
using namespace std;

class triplet
{
public:
    int first, second, third;
    triplet() {}
    triplet(int first, int second, int third) : first(first), second(second), third(third) {}
    bool operator<(const triplet &other) const
    {
        if (first == other.first)
            return (second <= other.second);
        else
            return (first <= other.first);
    }
};