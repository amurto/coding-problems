// https://codeforces.com/contest/430/problem/B
// Balls Game

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int destroy(vector<pair<int, int>> &b, int idx)
{
    int res = 2;
    for (int i = idx - 1, j = idx + 1; i >= 0 && j < b.size(); i--, j++)
    {
        if (b[i].first + b[j].first < 3 || b[i].second != b[j].second)
            return res;
        if (b[i].first == b[j].first)
            res += 4;
        else
            res += 3;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> arr(n);
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n;)
    {
        if (i + 1 < n && arr[i] == arr[i + 1])
        {
            b.pb({2, arr[i]});
            i += 2;
        }
        else
        {
            b.pb({1, arr[i]});
            i++;
        }
    }
    int res = 0;
    for (int i = 0; i < b.size(); i++)
        if (b[i].first == 2 && b[i].second == x)
            res = max(res, destroy(b, i));
    cout << res << "\n";
    return 0;
}