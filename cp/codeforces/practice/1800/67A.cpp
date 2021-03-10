// https://codeforces.com/contest/67/problem/A
// Partial Teacher

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    string str;
    cin >> n >> str;
    vector<int> tof(n), diff(n);
    tof[0] = 1;
    for (int l = 0, r = 1; r < n; l++, r++)
    {
        if (str[l] == '=')
            tof[r] = tof[l];
        else if (str[l] == 'R')
            tof[r] = tof[l] + 1;
        else
        {
            tof[r] = 1;
            if (tof[l] == 1)
                tof[l]++;
        }
    }
    for (int l = n - 2, r = n - 1; l >= 0; l--, r--)
    {
        if (str[l] == 'L' && tof[l] <= tof[r])
            tof[l] = tof[r] + 1;
        else if (str[l] == '=' && tof[l] < tof[r])
            tof[l] = tof[r];
    }
    for (int t : tof)
        cout << t << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}