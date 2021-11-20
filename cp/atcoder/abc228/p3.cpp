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

void solve()
{
    int n, k, S = 1205;
    cin >> n >> k;
    vector<vector<int>> arr(n, vector<int>(3));
    vector<int> score(n), cnt(S);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
            score[i] += arr[i][j];
        }
        cnt[score[i]]++;
    }
    for (int i = S - 2; i >= 0; i--)
        cnt[i] += cnt[i + 1];
    for (int i = 0; i < n; i++)
    {
        if (cnt[score[i] + 1] < k || cnt[score[i] + 301] < k)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}