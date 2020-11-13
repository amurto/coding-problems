#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool invalid(vector<bool> &d, int num)
{
    while (num > 0)
    {
        if (d[num % 10])
            return true;
        num /= 10;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, K, v;
    cin >> N >> K;
    vector<bool> d(10);
    for (int i = 0; i < K; i++)
    {
        cin >> v;
        d[v] = true;
    }
    while (invalid(d, N))
        N++;
    cout << N << "\n";
    return 0;
}