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

void solve()
{
    int n, q, abc = 0;
    string str;
    cin >> n >> q >> str;
    for (int i = 2; i < n; i++)
        if (str[i - 2] == 'a' && str[i - 1] == 'b' && str[i] == 'c')
            abc++;
    for (int i = 0; i < q; i++)
    {
        int idx;
        char ch;
        cin >> idx >> ch;
        idx--;
        for (int l = max(0, idx - 2), r = max(0, idx - 2) + 2; r < min(n, idx + 3); l++, r++)
            if (str[l] == 'a' && str[l + 1] == 'b' && str[l + 2] == 'c')
                abc--;
        str[idx] = ch;
        for (int l = max(0, idx - 2), r = max(0, idx - 2) + 2; r < min(n, idx + 3); l++, r++)
            if (str[l] == 'a' && str[l + 1] == 'b' && str[l + 2] == 'c')
                abc++;
        cout << abc << "\n";
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