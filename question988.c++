#include <iostream>
#include<climits>
#include <algorithm>
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

string smaller(TreeNode* root,int min1)
{
    if(root==NULL)
    {
        return "z";
    }
    if(root->left==NULL && root->right==NULL)
    {
        if(min1==root->val) return string(1,char(root->val+'a'));
        return string(1,(min(min1,root->val)+'a'));
    }
    string left=smaller(root->left,min1);
    string right=smaller(root->right,min1);
    return min(right,left)+string(1,char(root->val+'a'));
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->left->right->left=new TreeNode(0);
    cout<<smaller(root,INT_MAX);
    return 0;
}
