#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~Node()
    {
        delete left;
        delete right;
    }
};
class cmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
class solution
{
public:
    void traverse(Node *root,vector<string>& ans,string temp)
    {
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(temp);
            return; 
        }
        traverse(root->left,ans,temp+'0');
        traverse(root->right,ans,temp+'1');
    }
    vector<string> huffcode(vector<int> f, int n)
    {
        priority_queue<Node *, vector<Node *>, cmp> ans;
        for (int i = 0; i < n; i++)
        {
            Node *newnode = new Node(f[i]);
            ans.push(newnode);
        }
        while (ans.size() > 1)
        {
            Node *left = ans.top();
            ans.pop();
            Node *right = ans.top();
            ans.pop();
            Node *newnode = new Node(left->data + right->data);
            newnode->left = left;
            newnode->right = right;
        }
        Node *root = ans.top();
        ans.pop();
        vector<string> value;
        string temp = "";
        traverse(root, value, temp);
        return value;
    }
};
int main()
{
    
}