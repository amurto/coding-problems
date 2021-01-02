#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, res = 0;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (abs(p[i].second - p[j].second) <= abs(p[i].first - p[j].first))
                res++;
    cout << res << "\n";
    return 0;
}