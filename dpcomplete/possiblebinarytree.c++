#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<TreeNode *> helper(int n, unordered_map<int,vector<TreeNode*>> &mp)
{
    if (n % 2 == 0)
        return {};
    if (n == 1)
    {
        TreeNode *root = new TreeNode(0);
        return {root};
    }
    if(mp.find(n)!=mp.end()) return mp[n];
    vector<TreeNode *> result;
    for (int i = 1; i < n; i += 2)
    {
        vector<TreeNode *> leftv = helper(i,mp);
        vector<TreeNode *> rightv = helper(n - i - 1,mp);
        for (int k = 0; k < leftv.size(); k++)
        {
            for (int j = 0; j < rightv.size(); j++)
            {
                TreeNode *root = new TreeNode(0);
                root->left = leftv[k];
                root->right = rightv[j];
                result.push_back(root);
            }
        }
    }
    return mp[n]=result;
}
vector<TreeNode *> allPossibleFBT(int n)
{
    unordered_map<int,vector<TreeNode*>> mp;
    return helper(n,mp);
}
int main()
{

    return 0;
}