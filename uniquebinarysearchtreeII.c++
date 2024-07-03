#include <bits/stdc++.h>
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
TreeNode* rootfinder(int n)
{
    TreeNode *root = new TreeNode(1);
    queue<TreeNode *> pendingnodes;
    for (int i = 2; i < n; i++)
    {
        TreeNode *front = pendingnodes.front();
        front->right = new TreeNode(i);
        pendingnodes.pop();
    }
    return root;
}
vector<TreeNode*> helper(TreeNode* root,vector<TreeNode*> ans)
{
    if(root==NULL) 
    {
        ans.push_back(root);
    }

}
vector<TreeNode *> generateTrees(int n)
{
    TreeNode* root=rootfinder(n);
    vector<TreeNode*> ans;
    helper(root,ans);
    return ans;
}
int main()
{
}