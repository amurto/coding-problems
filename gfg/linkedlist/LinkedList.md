## Singly Linked List

```cpp
class Node
{
public:
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void insert(Node** root, int v)
{
    Node* temp = new Node(v);
    Node* ptr;
    temp->next = NULL;
    if (*root == NULL)
        *root = temp;
    else
    {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

Node *arrayToList(int n) 
{ 
    Node *root = NULL; 
    int v;
    for (int i = 0; i < n; i++) {
        cin>>v;
        insert(&root, v); 
    }
    return root; 
} 

void display(Node *root)
{
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
}

int main() {
    int n;
    cin>>n;
    Node* root = arrayToList(n);
    return 0;
}
```