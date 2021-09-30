#include <bits/stdc++.h>
using namespace std;

// for 64 bit, use mt19937_64
mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
#define pb push_back

// Just call rand(minValue, maxValue);
// Note: it doesn't guarantee distinct values.
int rand(int l, int r)
{
    static mt19937
        rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> ludo(l, r);
    return ludo(rng);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}