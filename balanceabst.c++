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
int height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
TreeNode *balanceBST1(TreeNode *root)
{
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    if (abs(leftheight - rightheight) <= 1)
        return root;
    if (leftheight > rightheight)
    {
        TreeNode *check = root->left;
        root->left = NULL;
        TreeNode *temp = check;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = root;
        root = check;
    }
    if (leftheight < rightheight)
    {
        TreeNode *check = root->right;
        root->right = NULL;
        TreeNode *temp = check;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        temp->left = root;
        root = check;
    }
    TreeNode* ans=balanceBST1(root);
    return ans;
}
TreeNode *balanceBST(TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    root=balanceBST1(root);
    TreeNode *leftnode = balanceBST(root->left);
    TreeNode *rightnode = balanceBST(root->right);
    if (leftnode != NULL)
        root->left = leftnode;
    if (rightnode != NULL)
        root->right = rightnode;
    return root;
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
