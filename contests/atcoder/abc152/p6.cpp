#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    vector<int> a(N), b(N);
    for (int i = 0; i < N-1; i++)
        cin >> a[i];
    for (int i = 0; i < N-1; i++)
        cin >> b[i];
    vector<int> u(M), v(M);
    for (int i = 0; i < M; i++)
        cin >> u[i];
    for (int i = 0; i < M; i++)
        cin >> v[i];
    return 0;
}