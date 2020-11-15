#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, w, s, t;
    cin >> n >> w;
    vector<pair<int, int>> arr(n), dep(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s >> t;
        arr[i].first = s;
        arr[i].second = i;
        dep[i].first = t;
        dep[i].second = i;
        cin >> p[i];
    }
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int cur = 0, res = 0, i = 0, j = 0;
    while (i < n && j < n)
    {
        while (j < n && dep[j] <= arr[i])
        {
            cur -= p[dep[j].second];
            j++;
        }
        cur += p[arr[i].second];
        i++;
        cout << cur << "\n";
        res = max(res, cur);
    }
    if (res > w)
        cout << "No\n";
    else
        cout << "Yes\n";
    return 0;
}