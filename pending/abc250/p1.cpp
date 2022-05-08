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
    int h, w, r, c;
    cin >> h >> w >> r >> c;
    auto is_valid = [&](int i, int j) -> int
    {
        if (i > 0 && i <= h && j > 0 && j <= w)
            return 1;
        return 0;
    };
    int cnt = is_valid(r - 1, c) + is_valid(r, c + 1) + is_valid(r + 1, c) + is_valid(r, c - 1);
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}