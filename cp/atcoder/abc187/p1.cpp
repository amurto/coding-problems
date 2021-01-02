#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int S(int val)
{
    int sum = 0;
    while (val > 0)
    {
        sum += val % 10;
        val /= 10;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    cout << max(S(a), S(b)) << "\n";
    return 0;
}