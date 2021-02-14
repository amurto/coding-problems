#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int minOperations(string s)
{
    int n = s.length();
    int o = 0, e = 0;
    for (int i = 0, k = 0; i < n; i++, k ^= 1)
        if (s[i] - '0' != k)
            o++;
    for (int i = 0, k = 1; i < n; i++, k ^= 1)
        if (s[i] - '0' != k)
            e++;
    return min(o, e);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    cout << minOperations(s) << "\n";
    return 0;
}