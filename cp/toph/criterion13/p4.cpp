#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

map<string, int> mp;
vector<string> mon = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
vector<int> mlen = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int mask()
{
    string m, dd;
    int y;
    cin >> m >> dd >> y;
    dd = dd.substr(0, dd.length() - 1);
    int cnt = stoi(dd);
    for (int i = 1942; i < y; i++)
        cnt += 365;
    for (int i = 0; mon[i] != m; i++)
    {
        if (i == 1 && y % 4 == 0)
            cnt += 29;
        else
            cnt += mlen[i];
    }
    return cnt;
}

void solve()
{
    int n, y, q;
    cin >> n;
    string m, dd;
    vector<int> date(n);
    for (int i = 0; i < n; i++)
        date[i] = mask();
    sort(date.begin(), date.end());
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a = mask(), b = mask();
        if (a > b)
            swap(a, b);
        int lb = lower_bound(date.begin(), date.end(), a) - date.begin();
        int ub = upper_bound(date.begin(), date.end(), b) - date.begin();
        cout << ub - lb << "\n";
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