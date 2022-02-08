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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // Lambda recursive function
    auto rec = [&](const auto &self, int i) -> int
    {
        if (i == 0)
            return 1;
        return self(self, i - 1) + 1ll;
    };
    cout << rec(rec, 10) << "\n";
    return 0;
}