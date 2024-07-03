int height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
TreeNode *balanceBST(TreeNode *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    int flag=0;
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    cout<<leftheight<<endl;
    cout<<rightheight<<endl;
    TreeNode* check;
    if(abs(leftheight-rightheight)>1)
    {
        if(leftheight>rightheight)
        {
            check=root->left;
            root->left=NULL;
            TreeNode * temp=check;
            while(temp->right!=NULL)
            {
                temp=temp->right;
            }
            temp->right=root;
            root=check;
        }
        if(leftheight<rightheight)
        {
            check=root->right;
            root->right=NULL;
            TreeNode * temp=check;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            temp->left=root;
            root=check;
        }
        flag=1;
    }
    TreeNode* leftnode;
    TreeNode* rightnode;
    if(flag==0){
    leftnode=balanceBST(root->left);
    rightnode=balanceBST(root->right);}
    else
    {
        leftnode=balanceBST(check);
        rightnode=balanceBST(check); 
    }
    if(leftnode!=NULL) root->left=leftnode;
    if(rightnode!=NULL) root->right=rightnode;
    return root;
}