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
    int n;
    cin >> n;
    vector<int> X(n), Y(n);
    string str;
    for (int i = 0; i < n; i++)
        cin >> X[i] >> Y[i];
    cin >> str;
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i1, int i2)
         {
        if (Y[i1]==Y[i2])
            return X[i1] <X[i2];
        return Y[i1] < Y[i2]; });
    for (int i = 0; i < n;)
    {
        int r = i;
        while (r < n && Y[ids[i]] == Y[ids[r]])
            r++;
        for (int j = i + 1; j < r; j++)
            if (str[ids[j - 1]] == 'R' && str[ids[j]] == 'L')
                return true;
        i = r;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}