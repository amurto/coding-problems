// https://codeforces.com/contest/63/problem/C
// Bulls and Cows

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e4;
int x[10], y[10];
vector<string> q(10), res;

void match(int num, int n)
{
    string tmp = to_string(num);
    if (tmp.length() < 3)
        return;
    if (tmp.length() == 3)
        tmp = "0" + tmp;

    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if (tmp[i] == tmp[j])
                return;
    for (int i = 0; i < n; i++)
    {
        int X = 0, Y = 0;
        for (int j = 0; j < 4; j++)
        {
            if (tmp[j] == q[i][j])
                X++;
            else if (count(q[i].begin(), q[i].end(), tmp[j]) > 0)
                Y++;
        }
        if (X != x[i] || Y != y[i])
            return;
    }
    res.pb(tmp);
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i] >> x[i] >> y[i];
    for (int i = 1; i < N; i++)
        match(i, n);
    if (res.empty())
        cout << "Incorrect data\n";
    else if (res.size() > 1)
        cout << "Need more data\n";
    else
        cout << res[0] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}