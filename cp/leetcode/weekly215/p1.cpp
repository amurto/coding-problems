#include<bits/stdc++.h>
using namespace std;

class OrderedStream {
public:
    int ptr = 1, sz=0;
    string str[1001];
    priority_queue<int, vector<int>, greater<int>> pq; 
    OrderedStream(int n) {
        sz = n;
    }
    
    vector<string> insert(int id, string value) {
        str[id] = value;
        pq.push(id);
        vector<string> res;
        while (!pq.empty() && pq.top() == ptr) {
            pq.pop();
            res.push_back(str[ptr]);
            ptr++;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */