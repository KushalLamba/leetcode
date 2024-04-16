#include <iostream>
#include<queue>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *addOneRow(TreeNode *root, int val, int depth)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (depth == 1)
    {
        return root;
    }
    TreeNode *ans1 = addOneRow(root->left, val, depth - 1);
    TreeNode *ans2 = addOneRow(root->right, val, depth - 1);
    TreeNode *left1 = new TreeNode(val);
    TreeNode *right1 = new TreeNode(val);
    if (ans1 != NULL)
        left1->left = ans1;
    if (ans2 != NULL)
        right1->right = ans2;
    root->left = left1;
    root->right = right1;
    return root;
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    int value=1;
    int depth=3;
    TreeNode* ans=addOneRow(root,value,depth);
    queue<TreeNode*> pendingnodes;
    pendingnodes.push(ans);
    pendingnodes.push(NULL);
    while(!pendingnodes.empty())
    {
        TreeNode* front=pendingnodes.front();
        pendingnodes.pop();
        if(front==NULL)
        {
            cout<<endl;
            pendingnodes.push(NULL);
        }
        else
        cout<<front->val<<endl;
        if(front->left!=NULL)
        {
            pendingnodes.push(front->left);
        }
        if(front->right!=NULL)
        {
            pendingnodes.push(front->right);
        }
    }
}