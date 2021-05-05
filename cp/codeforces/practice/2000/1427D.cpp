// https://codeforces.com/contest/1427/problem/D
// Unshuffling a Deck

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<int> op(vector<int> t, vector<int> arr, int n)
{
    vector<int> tmp;
    int i = 0;
    stack<int> st;
    for (int k : t)
    {
        for (int j = i + k - 1; j >= i; j--)
            st.push(arr[j]);
        i += k;
    }
    while (!st.empty())
    {
        tmp.pb(st.top());
        st.pop();
    }
    return tmp;
}

vector<int> perform(vector<int> &arr, int prev, int cur, int n)
{
    vector<int> t;
    for (int j = 0; j <= cur; j++)
        t.pb(1);
    t.pb(prev - cur);
    if (n - 1 > prev)
        t.pb(n - prev - 1);
    return t;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    for (int e = 2, p = 0; e <= n; e++)
    {
        int prev = 0, cur = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == e - 1)
                prev = i;
            else if (arr[i] == e)
                cur = i;
        }
        vector<int> t;
        if (p == 0)
        {
            if (cur > prev)
            {
                swap(cur, prev);
                if (cur == prev + 1)
                    continue;
                p ^= 1;
            }
            t = perform(arr, prev, cur, n);
            arr = op(t, arr, n);
            res.pb(t);
        }
        else
        {
            reverse(arr.begin(), arr.end());
            prev = n - 1 - prev;
            cur = n - 1 - cur;
            if (cur > prev)
            {
                swap(cur, prev);
                if (cur == prev + 1)
                {
                    reverse(arr.begin(), arr.end());
                    continue;
                }
                p ^= 1;
            }
            t = perform(arr, prev, cur, n);
            arr = op(t, arr, n);
            reverse(t.begin(), t.end());
            res.pb(t);
            reverse(arr.begin(), arr.end());
        }
    }
    if (arr[0] == n)
    {
        vector<int> t(n, 1);
        res.pb(t);
        reverse(arr.begin(), arr.end());
    }
    cout << res.size() << "\n";
    for (vector<int> t : res)
    {
        cout << t.size() << " ";
        for (int e : t)
            cout << e << " ";
        cout << "\n";
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