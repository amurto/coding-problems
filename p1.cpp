#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int mxn = 26;
vector<int> arr(mxn);
string fix(string &str, vector<int> &arr, int n, int p)
{
    string res = "";
    for (int i = 0; i < n; i++)
        if (arr[str[i] - 'a'] >= p)
            res.pb(str[i]);
    return str;
}
string solve()
{
    int n, k;
    string str;
    cin >> n >> k >> str;
    vector<int> freq(mxn), ord(mxn), rem(mxn);
    vector<bool> vis(n);
    for (int i = 0; i < mxn; i++)
        cin >> arr[i];
    for (char ch : str)
        freq[ch - 'a']++;
    auto cmp = [&](int &i1, int &i2) {
        return arr[i1] > arr[i2];
    };
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), cmp);
    int tmp = k, itr = 0, p = 0, req = k;
    while (tmp >= 0 && itr < mxn)
    {
        int cur = 0;
        p = arr[ord[itr]];
        while (itr < mxn && arr[ord[itr]] == p)
        {
            cur += freq[ord[itr]];
            itr++;
        }
        tmp -= cur;
    }
    if (tmp == 0)
        return fix(str, arr, n, p);
    queue<int> qx;
    vector<queue<int>> qv(mxn);
    for (int i = 0; i < n; i++)
    {
        if (arr[str[i] - 'a'] > p)
        {
            vis[i] = true;
            qx.push(i);
            req--;
        }
        else if (arr[str[i] - 'a'] == p)
            qv[str[i] - 'a'].push(i);
    }
    rem[n - 1] = (arr[str[n - 1] - 'a'] == p);
    for (int i = n - 2; i >= 0; i--)
        rem[i] = (arr[str[i] - 'a'] == p) + rem[i + 1];
    int idx = 0;
    while (idx < n && req > 0)
    {
        for (int i = 0; i < mxn; i++)
            while (!qv[i].empty() && qv[i].front() < idx)
                qv[i].pop();
        while (!qx.empty() && qx.front() < idx)
            qx.pop();
        bool f = false;
        int nxt = qx.empty() ? 26 : str[qx.front()] - 'a';
        int id = qx.empty() ? n : qx.front();
        for (int j = 0; !f && j < mxn; j++)
        {
            if (j == nxt)
            {
                if (rem[id] >= req)
                {
                    idx = id + 1;
                    f = true;
                }
            }
            else
            {
                if (qv[j].empty() || qv[j].front() > id || rem[qv[j].front()] < req)
                    continue;
                vis[qv[j].front()] = true;
                f = true;
                idx = qv[j].front() + 1;
                req--;
            }
        }
    }
    string res = "";
    for (int i = 0; i < n; i++)
        if (vis[i])
            res.pb(str[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}