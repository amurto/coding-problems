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
    vector<pii> arr(n);
    vector<int> inc(n + 1);
    for (int i = 0; i < n; i++)
    {
        arr[i].second = i + 1;
        cin >> arr[i].first;
        inc[i + 1] = arr[i].second;
    }
    sort(arr.begin(), arr.end());
    int e = n - 1, last = -1;
    for (int i = 0; i < n; i++)
    {
        int outdeg = e - arr[i].first;
        if (outdeg == e)
        {
            for (int j = i + 1; j < n; j++)
                arr[j].first--;
            e--;
            last = i;
            continue;
        }
        for (int j = n - 1; j > last; j--)
        {
            if (j == i)
                continue;
            if (query(arr[j].second, arr[i].second))
            {
                cout << "! " << arr[i].second << " " << arr[j].second << "\n";
                fflush(stdout);
                return;
            }
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