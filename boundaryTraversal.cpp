#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int num)
    {
        val = num;
        left = nullptr;
        right = nullptr;
    }
};

void print(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << "  ";
    }
}

TreeNode *createRoot()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);
    root->left->left->right = new TreeNode(10);
    root->left->left->right->left = new TreeNode(11);
    root->left->right->left = new TreeNode(12);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);
    root->right->left->right = new TreeNode(13);
    return root;
}

void leafNodes(TreeNode *root, vector<int> &result)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        result.push_back(root->val);
        return;
    }
    leafNodes(root->left, result);
    leafNodes(root->right, result);
}

void leftTraversalWithOutLeaf(TreeNode *root, vector<int> &result)
{
    if (!root->left && !root->right)
    {
        return;
    }
    result.push_back(root->val);

    if (root->left)
    {
        leftTraversalWithOutLeaf(root->left, result);
    }
    else
    {
        leftTraversalWithOutLeaf(root->right, result);
    }
}

void rightTraversalWithOutLeaf(TreeNode *root, vector<int> &result)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        return;
    }
    result.push_back(root->val);
    if (root->right)
    {
        rightTraversalWithOutLeaf(root->right, result);
    }
    else
    {
        rightTraversalWithOutLeaf(root->left, result);
    }
}

void boundaryTraversal(TreeNode *root)
{
    vector<int> result;
    vector<int> vec;
    leftTraversalWithOutLeaf(root, result);
    leafNodes(root, result);
    rightTraversalWithOutLeaf(root, vec);
    print(result);
    reverse(vec.begin(),vec.end());
    print(vec);
}

int main()
{
    TreeNode *root = createRoot();
    boundaryTraversal(root);
}
