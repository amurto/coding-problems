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

// king moves
int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// knight moves
int di[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dj[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}