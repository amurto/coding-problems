// https://codeforces.com/contest/483/problem/C
// Diverse Permutation

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> res = {1};
    int pt[2] = {2, n}, cur = 1;
    while (k-- > 1)
    {
        if (cur == 0)
            res.pb(pt[cur]++);
        else
            res.pb(pt[cur]--);
        cur ^= 1;
    }
    int inc = res.back() <= (n + 1) / 2 ? 1 : -1;
    while (res.size() < n)
        res.pb(res.back() + inc);
    for (int r : res)
        cout << r << " ";
    return 0;
}