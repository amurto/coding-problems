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

// Formula for prefix xors 0 ^ 1 ^ .... ^ k:
int xorUpToK(int k)
{
    switch (k % 4)
    {
    case 0:
        return k;
    case 1:
        return 1;
    case 2:
        return k + 1;
    case 3:
        return 0;
    }
    return 0;
}

int solve()
{
    int a, b;
    cin >> a >> b;
    int x = xorUpToK(a - 1);
    int len = a;
    if (x == b)
        return len;
    if ((x ^ b) != a)
        return len + 1;
    return len + 2;
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