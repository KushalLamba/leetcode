#include <iostream>
using namespace std;
class TriesNode
{
public:
    char data;
    TriesNode **children;
    bool isterminal;
    TriesNode(char data)
    {
        this->data = data;
        children = new TriesNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isterminal = false;
    }
};
class Tries
{
    TriesNode *root;

public:
    Tries()
    {
        root = new TriesNode('\0');
    }
    void insert(TriesNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isterminal = true;
            return;
        }
        int index = word[0] - 'a';
        TriesNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TriesNode(word[0]);
            root->children[index] = child;
        }
        insert(child, word.substr(1));
    }
    bool search(TriesNode *root, string ans)
    {
        if (ans.size() == 0)
        {
            if (root->isterminal)
            {
                return true;
            }
            return false;
        }
        int index = ans[0] - 'a';
        if (root->children[index] == NULL)
        {
            return false;
        }
        if (search(root->children[index], ans.substr(1)))
        {
            return true;
        }
        return false;
    }
    void insert(string word)
    {
        insert(root, word);
    }
    bool search(string ans)
    {
        if(search(root, ans))
        {
            return true;
        }
        return false;
    }
};
int main()
{
    string word;
    string ans;
    Tries t;
    int n;
    cout<<"Enter Number of words insert: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>word;
        t.insert(word);
    }
    cout<<"Enter The word that you want to find: "<<endl;
    cin>>ans;
    cout<<t.search(ans);
}