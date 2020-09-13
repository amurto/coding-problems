// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
// Longest Increasing Subsequence

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[100001];

// Dynamic Programming
// O(n^2)
int LIS(int a[], int n, int cur) {
    if (DP[cur] == 0) {
        for (int i=cur+1; i<n; i++)
            if (a[cur] < a[i])
                DP[cur] = max(DP[cur], LIS(a, n, i)+1);
        DP[cur] = max(DP[cur], 1);
    }
    return DP[cur];
}

// Fastest approach
// O(nlogn)
// Uses Set to maintain length of Longest Increasing Subsequence
int LISusingSet(int a[], int n) {
    int MAX=0;
    set<int> SET;
    for (int i=0; i<n; i++) {
        if (SET.lower_bound(a[i]) == SET.end())
            MAX++;
        else
            SET.erase(SET.lower_bound(a[i]));
        SET.insert(a[i]);
    }
    return MAX;
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n;
        cin>>n;
        int a[n];
        for (int i=0; i<n; i++) 
            cin>>a[i];

        // memset(DP, 0, sizeof(DP));
        // int MAX=0;
        // for (int i=0; i<n; i++)
        //     MAX=max(MAX, LIS(a, n, i));
        // cout<<MAX<<endl;

        cout<<LISusingSet(a, n)<<endl;
    }
    return 0;
}