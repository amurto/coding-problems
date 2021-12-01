#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int len(int x)
{
    int cnt = 0;
    while (x > 0)
    {
        cnt++;
        x /= 10;
    }
    return cnt;
}

char solve()
{
    int x1, x2, p1, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    int len1 = len(x1), len2 = len(x2);
    len1 += p1;
    len2 += p2;
    if (len1 != len2)
        return len1 < len2 ? '<' : '>';
    len1 -= p1;
    len2 -= p2;
    while (len1 < len2)
    {
        len1++;
        x1 *= 10;
    }
    while (len2 < len1)
    {
        len2++;
        x2 *= 10;
    }
    if (x1 == x2)
        return '=';
    return x1 < x2 ? '<' : '>';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}