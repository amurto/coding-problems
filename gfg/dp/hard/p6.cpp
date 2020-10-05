// https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1
// Partition array to K subsets

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool dfs(int sum, int cur, int *A, vector<bool> &vis) {
    if (sum==0)
        return true;
    if (cur<0)
        return false;
    if (!vis[cur] && (sum-A[cur] >=0)) {
        bool res = dfs(sum-A[cur], cur-1, A, vis);
        if (res) {
            cout<<A[cur]<<" ";
            vis[cur] = true;
            return true;
        }
    }
    return dfs(sum, cur-1, A, vis);
}
bool isKPartitionPossible(int A[], int N, int K)
{
    if (K==1)
        return true;
    if (K>N)
        return false;
    int sum=0;
    for (int i=0; i<N; i++) 
        sum+=A[i];
    if (sum%K > 0)
        return false;
    int reqSum = sum/K;
    sort(A, A+N);
    vector<bool> vis(N, false);
    while (K>0) {
        cout<<"\n";
        bool res = dfs(reqSum, N-1, A, vis);
        if (res) K--;
        else return 0;
    }
    return true;
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int N, K;
        cin>>N>>K;
        int A[N];
        for (int i=0; i<N; i++) 
            cin>>A[i];
        cout<<isKPartitionPossible(A, N, K)<<"\n";
    }
    return 0;
}