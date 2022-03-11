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

int solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    array<int, 2> arr{0, 0};
    arr[a & 1]++;
    arr[b & 1]++;
    arr[c & 1]++;
    if (arr[0] == 3 || arr[1] == 3)
        return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}