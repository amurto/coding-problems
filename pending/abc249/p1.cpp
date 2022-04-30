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

int cnt_dis(int a, int b, int c, int x)
{
    bool rest = false;
    int dis = 0;
    while (x > 0)
    {
        if (rest)
        {
            x -= c;
            rest = false;
        }
        else
        {
            dis += min(a, x) * b;
            x -= a;
            rest = true;
        }
    }
    return dis;
}

string solve()
{
    int a1, b1, c1, a2, b2, c2, x;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> x;
    int dis1 = cnt_dis(a1, b1, c1, x), dis2 = cnt_dis(a2, b2, c2, x);
    if (dis1 > dis2)
        return "Takahashi";
    else if (dis1 == dis2)
        return "Draw";
    return "Aoki";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}