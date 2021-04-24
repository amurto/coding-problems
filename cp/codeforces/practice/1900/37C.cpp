// https://codeforces.com/contest/37/problem/C
// Old Berland Language

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void addOne(string &str)
{
    int sz = str.length();
    int i = sz - 1;
    while (i >= 0 && str[i] == '1')
        i--;
    str[i] = '1';
    for (int j = i + 1; j < sz; j++)
        str[j] = '0';
}

bool allOnes(string &str)
{
    return count(str.begin(), str.end(), '0') == 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), seq(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    iota(seq.begin(), seq.end(), 0);
    sort(seq.begin(), seq.end(), [&](int &i1, int &i2) {
        return arr[i1] < arr[i2];
    });
    string cur = "0";
    vector<string> res(n);
    for (int i = 0; i < n;)
    {
        int r = i, sz = cur.length();
        if (allOnes(cur))
        {
            cout << "NO\n";
            return;
        }
        if (i > 0)
            addOne(cur);
        while (r < n && arr[seq[i]] == arr[seq[r]])
            r++;
        for (int j = sz; j < arr[seq[i]]; j++)
            cur.pb('0');
        for (int j = i; j < r; j++)
        {
            if (allOnes(cur))
            {
                cout << "NO\n";
                return;
            }
            if (j > i)
                addOne(cur);
            res[seq[j]] = cur;
        }
        i = r;
    }
    cout << "YES\n";
    for (string r : res)
        cout << r << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}