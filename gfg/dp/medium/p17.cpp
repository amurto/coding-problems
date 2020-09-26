// https://practice.geeksforgeeks.org/problems/two-water-jug-problem/0
// Two water Jug problem

// m and d < n

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int TWJ(int fromCap, int toCap, int d)
{
    int step = 1, from = fromCap, to = 0;
    while (from != d && to != d)
    {
        int temp = min(from, toCap - to);
        to += temp;
        from -= temp;
        step++;
        if (from == d || to == d)
            break;
        if (from == 0)
        {
            from = fromCap;
            step++;
        }
        if (to == toCap)
        {
            to = 0;
            step++;
        }
    }
    return step;
}

int minOperations(int m, int n, int d)
{
    if (m > n)
        swap(m, n);
    if (d > n || (d % __gcd(m, n)) != 0)
        return -1;
    return min(TWJ(m, n, d), TWJ(n, m, d));
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int m, n, d;
        cin >> m >> n >> d;
        cout << minOperations(m, n, d) << endl;
    }
    return 0;
}