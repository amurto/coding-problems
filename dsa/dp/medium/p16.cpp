// https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1
// Mobile numeric keypad

// 1 2 3
// 4 5 6
// 7 8 9
// * 0 #

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int di[5] = {0, 1, -1, 0, 0}, dj[5] = {0, 0, 0, -1, 1};
ll DP[4][3][26];

bool valid(int i, int j) {
    if (i<0 || i>3 || j>2 || j<0 || (i==3 && j!=1))
        return false;
    return true;
}

ll MNK(int i, int j, int N) {
    if (!valid(i,j))
        return 0;
    if (N==1)
        return 1;
    if (DP[i][j][N] < 0) {
        DP[i][j][N] = 0;
        for (int k=0; k<5; k++)
            DP[i][j][N]+=MNK(i+di[k], j+dj[k], N-1);
    }
    return DP[i][j][N];
}

ll getCount(int N) {
    ll ans = 0;
    for (int i=0; i<4; i++)
        for (int j=0; j<3; j++) 
            ans+=MNK(i,j,N);
    return ans;
}

int main() {
    int t;
    cin>>t;
    memset(DP, -1, sizeof(DP));
    while (t-->0) {
        int N;
        cin>>N;
        cout<<getCount(N)<<endl;
    }
    return 0;
}