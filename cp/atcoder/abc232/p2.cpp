#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    string s, t;
    cin >> s >> t;
    int n = (int)s.length();
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = t[i] - s[i];
        while (arr[i] < 0)
            arr[i] += 26;
    }
    sort(arr.begin(), arr.end());
    return arr[0] == arr.back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}