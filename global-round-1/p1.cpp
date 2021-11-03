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
    int b, k, odds = 0;
    cin >> b >> k;
    int last = b & 1;
    vector<int> arr(k);
    for (int i = 0; i < k; i++)
        cin >> arr[i];
    if (last == 0)
        return arr[k - 1] & 1;
    for (int i = 0; i < k; i++)
        if (arr[i] > 0 && (arr[i] & 1))
            odds++;
    return odds & 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "odd\n" : cout << "even\n";
    return 0;
}