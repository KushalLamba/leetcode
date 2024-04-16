#include <iostream>
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
int finder(TreeNode *root, int ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int currsum = ans * 10 + root->val;
    if (root->left == NULL && root->right == NULL)
    {
        return currsum;
    }
    int left = finder(root->left, currsum);
    int right = finder(root->right, currsum);
    return left + right;
}
int sumNumbers(TreeNode *root)
{
    return finder(root, 0);
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    cout << sumNumbers(root);
}