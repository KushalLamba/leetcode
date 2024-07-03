#include <bits/stdc++.h>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *input(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    queue<TreeNode *> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        TreeNode *front = pendingnodes.front();
        pendingnodes.pop();
        cout << "leftdata: " << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            TreeNode *leftnode = new TreeNode(leftdata);
            front->left = leftnode;
            pendingnodes.push(leftnode);
        }
        cout << "rightdata: " << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            TreeNode *rightnode = new TreeNode(rightdata);
            front->right = rightnode;
            pendingnodes.push(rightnode);
        }
    }
    return root;
}
void print(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<TreeNode *> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        TreeNode *front = pendingnodes.front();
        pendingnodes.pop();
        cout << front->val << endl;
        if (front->left != NULL)
        {
            pendingnodes.push(front->left);
        }
        if (front->right != NULL)
        {
            pendingnodes.push(front->right);
        }
    }
    return;
}
void helper(TreeNode *root,vector<int>& inorder)
{
    if(root==NULL)
    {
        return;
    }
    helper(root->left,inorder);
    inorder.push_back(root->val);
    helper(root->right,inorder);
}
TreeNode *maker(vector<int>& inorder,int start,int end)
{
    TreeNode* root;
    if(start>=end) return root;
    int mid=(start+end)/2;
    root->val=inorder[mid];
    root->left=maker(inorder,start,mid-1);
    root->right=maker(inorder,mid+1,end);
    return root;
}
TreeNode *balanceBST(TreeNode *root)
{
    vector<int> inorder;
    helper(root,inorder);
    return maker(inorder,0,inorder.size()-1);
}
int main()
{
    cout << "Enter The rootnode: " << endl;
    int rootdata;
    cin >> rootdata;
    TreeNode *root;
    if (rootdata != -1)
    {
        root = new TreeNode(rootdata);
        root = input(root);
    }
    root = balanceBST(root);
    // print(root);
}