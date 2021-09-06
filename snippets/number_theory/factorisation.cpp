#include<bits/stdc++.h>
using namespace std;

void factor(int num)
{
    unordered_map<int, int> F;
    for (int i = 2; i * i <= num; i++)
    {
        while (num % i == 0)
        {
            num /= i;
            F[i]++;
        }
    }
    if (num > 1)
        F[num]++;
}