// https://codeforces.com/problemset/problem/344/B
// Simple Molecules

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve(vector<int> &val)
{
    int sum = 0, idx = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += val[i];
        if (val[i] > val[idx])
            idx = i;
    }
    int MAX = val[idx], other = sum - val[idx];
    vector<int> bond(3);
    if (MAX > other || MAX % 2 != other % 2)
    {
        cout << "Impossible\n";
        return;
    }
    int extra = (other - MAX) / 2;
    // 0-1 1-2 2-0
    if (idx == 0)
    {
        bond[1] = extra;
        bond[0] = val[1] - extra;
        bond[2] = val[2] - extra;
    }
    else if (idx == 1)
    {
        bond[2] = extra;
        bond[0] = val[0] - extra;
        bond[1] = val[2] - extra;
    }
    else
    {
        bond[0] = extra;
        bond[1] = val[1] - extra;
        bond[2] = val[0] - extra;
    }
    for (int b: bond)
        cout << b << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> val(3);
    cin >> val[0] >> val[1] >> val[2];
    solve(val);
    return 0;
}