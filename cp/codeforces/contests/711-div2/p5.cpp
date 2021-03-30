#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

bool query(int a, int b)
{
    string str;
    cout << "? " << a << " " << b << "\n";
    fflush(stdout);
    cin >> str;
    return str == "Yes";
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), inc(n + 1);
    for (int i = 0; i < n; i++)
        cin >> inc[i + 1];
    iota(arr.begin(), arr.end(), 1);
    auto cmp = [&](int &i1, int &i2) {
        return inc[i1] < inc[i2];
    };
    sort(arr.begin(), arr.end(), cmp);
    int last = -1;
    for (int i = 0; i < n && inc[arr[i]] == 0; i++)
    {
        for (int j = i + 1; j < n; j++)
            inc[arr[j]]--;
        last = i;
    }
    vector<pii> edge;
    for (int i = last + 1; i < n; i++)
        for (int j = i + 1; j < n; j++)
            edge.pb({arr[j], arr[i]});
    auto cmpp = [&](pii &p1, pii &p2) {
        return abs(inc[p1.first] - inc[p1.second]) > abs(inc[p2.first] - inc[p2.second]);
    };
    sort(edge.begin(), edge.end(), cmpp);
    for (pii p : edge)
    {
        if (query(p.first, p.second))
        {
            cout << "! " << p.first << " " << p.second << "\n";
            fflush(stdout);
            return;
        }
    }
    cout << "! 0 0\n";
    fflush(stdout);
}

int main()
{
    solve();
    return 0;
}