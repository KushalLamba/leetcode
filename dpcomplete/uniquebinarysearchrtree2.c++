#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<TreeNode *> helper(int n, int start, int end,map<pair<int,int>,vector<TreeNode*>> mp)
{
    if (start > end)
        return {NULL};
    if (start == end)
    {
        TreeNode *root = new TreeNode(start);
        return {root};
    }
    if (mp.find(make_pair(start,end))!=mp.end()) return mp[make_pair(start,end)];
    vector<TreeNode *> result;
    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> leftv = helper(n, start, i - 1, mp);
        vector<TreeNode *> rightv = helper(n, i + 1, end, mp);
        for (int l = 0; l < leftv.size(); l++)
        {
            for (int j = 0; j < rightv.size(); j++)
            {
                TreeNode *root = new TreeNode(i);
                root->left = leftv[l];
                root->right = rightv[j];
                result.push_back(root);
            }
        }
    }
    return mp[make_pair(start,end)]= result;
}
vector<TreeNode *> generateTrees(int n)
{
    map<pair<int,int>,vector<TreeNode*>> mp;
    return helper(n, 1, n, mp);
}
int main()
{

    return 0;
}