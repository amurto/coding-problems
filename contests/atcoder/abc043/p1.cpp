#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, sum = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
        sum += i;
    cout << sum << "\n";
    return 0;
}