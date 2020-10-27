#include <bits/stdc++.h>
using namespace std;

struct bucket
{
    // self balancing bst can be used for faster operations
    vector<pair<int, int>> b;
    void put(int key, int val)
    {
        for (pair<int, int> &p : b)
            if (p.first == key)
            {
                p.second = val;
                return;
            }
        b.push_back({key, val});
    }
    int get(int key)
    {
        for (pair<int, int> p : b)
            if (p.first == key)
                return p.second;
        return 0;
    }
    bool find(int key)
    {
        for (pair<int, int> p : b)
            if (p.first == key)
                return true;
        return false;
    }
    void display()
    {
        for (pair<int, int> p : b)
            cout << p.first << " -> " << p.second << "\n";
    }
};

// hashset can be implemented similarly
class hashmap
{
private:
    int size;
    bucket *container;

public:
    hashmap(int num)
    {
        // initialize size
        // greater the size, lesser time, greater memory
        size = num;
        container = new bucket[num];
    }
    int hash(int val)
    {
        // easy hash function
        // complicated hash function can be implemented
        return val % size;
    }
    int get(int key)
    {
        return container[hash(key)].get(key);
    }
    void put(int key, int val)
    {
        container[hash(key)].put(key, val);
    }
    bool containsKey(int key)
    {
        return container[hash(key)].find(key);
    }
    void display()
    {
        // key -> value
        for (int i = 0; i < size; i++)
            container[i].display();
    }
};

int main()
{
    return 0;
}