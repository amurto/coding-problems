#include<bits/stdc++.h>
using namespace std;

class triplet
{
public:
    int first, second, third;
    triplet() {}
    triplet(int first, int second, int third) : first(first), second(second), third(third) {}
    bool operator<(const triplet &j) const
    {
        if (first == j.first)
            return (second <= j.second);
        else
            return (first <= j.first);
    }
};