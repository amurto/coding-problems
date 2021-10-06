// https://codeforces.com/contest/1305/problem/E
// Kuroni and the Score Distribution

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

const int N = 1e4 + 5;
int cnt[N];

void display(vector<int> &arr, int n)
{
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void solve()
{
    memset(cnt, 0, sizeof(cnt));
    map<int, int> cnt;
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    iota(arr.begin(), arr.end(), 0);
    if (n <= 2)
    {
        if (m > 0)
        {
            cout << "-1\n";
            return;
        }
        display(arr, n);
        return;
    }
    cnt[3]++;
    int i = 3;
    for (i = 3; m > 0 && i <= n; i++)
    {
        if (m == 0)
        {
            int cur = arr[i - 1] + 1;
            while (cnt[cur] > 0)
                cur++;
            arr[i] = cur;
        }
        else if (cnt[i] > m)
        {
            int cur = i;
            while (cnt[cur] > m)
                cur++;
            m -= cnt[cur];
            arr[i] = cur;
        }
        else if (cnt[i] <= m)
        {
            m -= cnt[i];
            arr[i] = i;
        }
        for (int j = 1; j < i; j++)
            cnt[arr[j] + arr[i]]++;
    }
    if (m > 0)
    {
        cout << "-1\n";
        return;
    }
    if (i <= n)
    {
        int mx = *max_element(arr.begin(), arr.end());
        mx++;
        arr[n] = 1e9;
        for (int j = n - 1; j >= i; j--)
            arr[j] = arr[j + 1] - mx;
    }
    display(arr, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}