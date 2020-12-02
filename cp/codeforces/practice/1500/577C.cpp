// https://codeforces.com/contest/577/problem/C
// Vasya and Petya's Game

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e3 + 1;
bool P[N];

// O(nlognlogn)
void sieve()
{
    memset(P, true, sizeof(P));
    P[0] = P[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (!P[i])
            continue;
        for (int j = 2; i * j < N; j++)
            P[i * j] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int n;
    cin >> n;
    vector<int> seq;
    for (int i = 2; i <= n; i++)
    {
        if (!P[i])
            continue;
        for (int j = i; j <= n; j *= i)
            seq.pb(j);
    }
    cout << seq.size() << "\n";
    for (int s: seq) 
        cout << s << " ";
    return 0;
}