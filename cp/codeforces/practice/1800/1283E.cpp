// https://codeforces.com/contest/1283/problem/E
// New Year Parties

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int mx(vector<int> &arr, int n)
{
    vector<int> st(n + 2);
    for (int x : arr)
    {
        if (st[x - 1] > 0)
        {
            if (st[x] > 0)
                st[x + 1]++;
            else
                st[x]++;
        }
        else
            st[x - 1]++;
    }
    int cnt = 0;
    for (int c : st)
        cnt += (c > 0);
    return cnt;
}

int mn(vector<int> &arr, int n)
{
    int cnt = 0;
    vector<int> st(n + 2);
    for (int x : arr)
        st[x] = 1;
    for (int i = 1; i < n + 2; i++)
    {
        if (st[i] > 0)
        {
            cnt++;
            i += 2;
        }
    }
    return cnt;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    cout << mn(arr, n) << " " << mx(arr, n) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}