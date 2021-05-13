// https://codeforces.com/contest/1296/problem/E2
// String Coloring (hard version)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, k = 26;
    string str;
    cin >> n >> str;
    vector<int> col(k, 1), cnt(k);
    for (char ch : str)
        cnt[ch - 'a']++;
    for (int i = n - 1; i >= 0; i--)
    {
        int cur = str[i] - 'a';
        cnt[cur]--;
        for (int j = cur + 1; j < k; j++)
            if (cnt[j] > 0 && col[j] == col[cur])
                col[j]++;
        // cout << "\n";
        // for (int j = 0; j < 5; j++)
        //     cout << col[j] << " ";
        // cout << "\n";
    }
    int res = 0;
    for (int c : col)
        res = max(res, c);
    cout << res << "\n";
    for (char ch : str)
        cout << col[ch - 'a'] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}