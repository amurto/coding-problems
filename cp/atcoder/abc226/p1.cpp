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

int solve()
{
    int res = 0;
    string str;
    cin >> str;
    int i = 0;
    while (str[i] != '.')
    {
        res *= 10;
        res += str[i] - '0';
        i++;
    }
    if (str[i + 1] >= '5')
        res++;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}