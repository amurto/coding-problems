#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string dup(string cur, int n)
{
    string d = "";
    int sz = cur.length(), id = 0;
    for (int i = 0; i < n; i++, id++)
    {
        id %= sz;
        d.pb(cur[id]);
    }
    return d;
}

string solve()
{
    int n, k;
    string str, cur = "";
    cin >> n >> k >> str;
    vector<string> arr;
    for (int i = 0; i < n; i++)
    {
        cur.pb(str[i]);
        arr.pb(dup(cur, k));
    }
    sort(arr.begin(), arr.end());
    return arr[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}