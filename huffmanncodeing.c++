#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
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
    void traverse(Node* root,vector<string>& ans, string temp)
    {
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(temp);
            return;
        }
        traverse(root->left,ans,temp+'0');
        traverse(root->right,ans,temp+'1');
    }
    vector<string> huffcode(string s, vector<int> f, int n)
    {
        priority_queue<Node *, vector<Node *>, cmp> minheap;
        for (int i = 0; i < n; i++)
        {
            Node *newnode = new Node(f[i]);
            minheap.push(newnode);
        }
        while(minheap.size()>1)
        {
            Node* first=minheap.top();
            minheap.pop();
            Node* second=minheap.top();
            minheap.pop();
            Node* newnode=new Node(first->data+second->data);
            newnode->left=first;
            newnode->right=second;
            minheap.push(newnode);
        }
        Node* root=minheap.top();
        minheap.pop();
        vector<string> ans;
        string temp="";
        traverse(root,ans,temp);
        return ans;
    }
};
int main()
{
    string s;
    cout << "Enter the string: " << endl;
    cin >> s;
    cout << "Enter The frequency: " << endl;
    vector<int> f(s.length(),0);
    for (int i = 0; i < s.length(); i++)
    {
        cin >> f[i];
    }
    solution ans;
    vector<string>ans1=ans.huffcode(s,f,s.length());
    for(int i=0;i<ans1.size();i++)
    {
        cout<<s[i]<<" "<<ans1[i]<<endl;
    }
}