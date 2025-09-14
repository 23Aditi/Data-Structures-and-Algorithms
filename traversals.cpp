#include <iostream>
#include <stack>
#include <utility>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
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

TreeNode *createTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->right = new TreeNode(8);
    return root;
}

void inorder(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    inorder(node->left);
    cout << node->val << "   ";
    inorder(node->right);
}

void reverseInorder(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    reverseInorder(node->right);
    cout << node->val << "   ";
    reverseInorder(node->left);
}

void inorderIt(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    stack<TreeNode *> st;
    TreeNode *curr = node;
    while (curr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->val << "   ";
        curr = curr->right;
    }
}

void leftTraversal(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    cout << node->val << "   ";
    if (node->left)
        leftTraversal(node->left);
    else
        leftTraversal(node->right);
}

void rightTraversal(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    cout << node->val << "   ";
    if (node->right)
    {
        rightTraversal(node->right);
    }
    else
    {
        rightTraversal(node->left);
    }
}

void leaf(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    if (!node->left && !node->right)
    {
        cout << node->val << "   ";
    }
    leaf(node->left);
    leaf(node->right);
}

void leftTraversalWithoutLeaf(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    if (!node->left && !node->right)
        return;
    cout << node->val << "   ";
    if (node->left)
        leftTraversalWithoutLeaf(node->left);
    else
        leftTraversalWithoutLeaf(node->right);
}

void rightTraversalWithoutLeaf(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    if (!node->left && !node->right)
    {
        return;
    }
    cout << node->val << "   ";
    if (node->right)
    {
        rightTraversalWithoutLeaf(node->right);
    }
    else
    {
        rightTraversalWithoutLeaf(node->left);
    }
}

void verticalTraversal(TreeNode *node, int line, map<int, vector<int>> &mp)
{
    if (!node)
    {
        return;
    }
    mp[line].push_back(node->val);
    verticalTraversal(node->left, line - 1, mp);
    verticalTraversal(node->right, line + 1, mp);
}

void printMap(map<int, vector<int>> &mp)
{
    for (auto &[l, v] : mp)
    {
        cout << "\nLINE NO : " << l << " ->  ";
        for (auto &e : v)
        {
            cout << e << "   ";
        }
    }
}

void preorder(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    cout << node->val << "   ";
    preorder(node->left);
    preorder(node->right);
}

void preorderIt(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    stack<TreeNode *> st;
    st.push(node);
    // N L R
    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();
        cout << curr->val << "   ";
        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left); // left will be processed first so on top (LIFO)
    }
}

void reversePreorder(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    cout << node->val << "   ";
    reversePreorder(node->right);
    reversePreorder(node->left);
}

void postorder(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->val << "   ";
}

void postorderIt(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    stack<TreeNode *> st1, st2;
    st1.push(node);
    while (!st1.empty())
    {
        TreeNode *curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left)
            st1.push(curr->left);
        if (curr->right)
            st1.push(curr->right);
    }
    while (!st2.empty())
    {
        TreeNode *curr = st2.top();
        st2.pop();
        cout << curr->val << "   ";
    }
}

void levelOrder(TreeNode *node)
{
    if (!node)
        return;
    queue<TreeNode *> q;
    q.push(node);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        cout << curr->val << "   ";
        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
        }
    }
}

void levelOrderWithLevels(TreeNode *node)
{
    if (!node)
        return;
    queue<TreeNode *> q;
    q.push(node);
    int level = 0;
    while (!q.empty())
    {
        int n = q.size();
        cout << "\nLEVEL : " << level << " -> ";
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            cout << curr->val << "   ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        level++;
    }
}

int maxDepth(TreeNode *node)
{
    if (!node)
    {
        return 0;
    }
    int leftDepth = maxDepth(node->left);
    int rightDepth = maxDepth(node->right);
    return 1 + max(leftDepth, rightDepth);
}

int checkBalancedBinaryTree(TreeNode *node)
{
    if (!node)
    {
        return 0;
    }
    int leftDepth = checkBalancedBinaryTree(node->left);
    int rightDepth = checkBalancedBinaryTree(node->right);
    if (abs(leftDepth - rightDepth) > 1)
    {
        return -1;
    }
    return 1 + max(leftDepth, rightDepth);
}

bool balancedBinaryTree(TreeNode *node)
{
    if (!node)
    {
        return 1;
    }
    int h = checkBalancedBinaryTree(node);
    if (h == -1)
    {
        cout << "\nThe Tree is not balanced binary tree.";
        return false;
    }
    cout << "\nThe tree is balanced binary tree with height : " << h;
    return true;
}

int diameter(TreeNode *node, int &dia)
{
    // longest path between any two nodes
    if (!node)
    {
        return 0;
    }
    int leftDepth = diameter(node->left, dia);
    int rightDepth = diameter(node->right, dia);
    dia = max(dia, leftDepth + rightDepth);
    return 1 + max(leftDepth, rightDepth);
}

int maxPathSum(TreeNode *node, int &maxSum)
{
    if (!node)
    {
        return 0;
    }
    int leftSum = maxPathSum(node->left, maxSum);
    int rightSum = maxPathSum(node->right, maxSum);
    maxSum = max(maxSum, node->val + leftSum + rightSum);
    return node->val + max(leftSum, rightSum);
}

TreeNode *createTree1()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->right = new TreeNode(18);
    return root;
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p || !q)
    {
        return p == q;
    }
    return (p->val == q->val) && (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right));
}

void zigZagTraversal(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(node);
    int f = 1;
    vector<vector<int>> level;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            vec.push_back(curr->val);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        if (f)
        {
            level.push_back(vec);
        }
        else
        {
            reverse(vec.begin(), vec.end());
            level.push_back(vec);
        }
        f = !f;
    }
    for (int i = 0; i < level.size(); i++)
    {
        vector<int> vec = level[i];
        int n = vec.size();
        cout << "\nLEVEL : " << i << " -> ";
        for (int j = 0; j < n; j++)
        {
            cout << vec[j] << "   ";
        }
    }
}

void rightTraversalWithoutRootAndLeaf(TreeNode *node, stack<int> &st)
{
    if (!node)
        return;
    st.push(node->val);
    if (node->right)
    {
        rightTraversalWithoutRootAndLeaf(node->right, st);
    }
    else
    {
        rightTraversalWithoutRootAndLeaf(node->left, st);
    }
}

void printStack(stack<int> &st)
{
    while (!st.empty())
    {
        cout << st.top() << "   ";
        st.pop();
    }
}

void boundaryTraversal(TreeNode *node)
{
    if (!node)
        return;
    // anticlockwise
    leftTraversalWithoutLeaf(node);
    leaf(node);
    stack<int> st;
    rightTraversalWithoutRootAndLeaf(node, st);
    printStack(st);
}

void topView(TreeNode *node)
{
    if (!node)
        return;
    queue<pair<TreeNode *, int>> q; // node , line
    map<int, int> mp;               // line , node
    q.push({node, 0});
    while (!q.empty())
    {
        auto [curr, line] = q.front();
        q.pop();
        if (mp.find(line) == mp.end())
        {
            mp.insert({line, curr->val});
        }
        if (curr->left)
        {
            q.push({curr->left, line - 1});
        }
        if (curr->right)
        {
            q.push({curr->right, line + 1});
        }
    }
    cout << "\nLINE : NODE";
    for (auto p : mp)
    {
        cout << "\n"
             << p.first << "       " << p.second;
    }
}

void bottomView(TreeNode *node)
{
    if (!node)
        return;
    queue<pair<TreeNode *, int>> q;
    q.push({node, 0});
    map<int, int> mp;
    while (!q.empty())
    {
        auto [curr, line] = q.front();
        q.pop();

        if (mp.find(line) != mp.end())
        {
            mp[line] = curr->val;
        }
        else
        {
            mp.insert({line, curr->val});
        }

        if (curr->left)
            q.push({curr->left, line - 1});
        if (curr->right)
            q.push({curr->right, line + 1});
    }
    cout << "\nLINE : NODE ";
    for (auto p : mp)
    {
        cout << "\n"
             << p.first << "      " << p.second;
    }
}

void leftView(TreeNode *node, int level, queue<int> &q)
{
    if (!node)
        return;
    if (level == q.size())
    {
        q.push(node->val);
    }
    leftView(node->left, level + 1, q);
    leftView(node->right, level + 1, q);
}

void rightView(TreeNode *node, int level, queue<int> &q)
{
    if (!node)
        return;
    if (level == q.size())
    {
        q.push(node->val);
    }
    rightView(node->right, level + 1, q);
    rightView(node->left, level + 1, q);
}

void printQueue(queue<int> &q)
{
    while (!q.empty())
    {
        cout << q.front() << "   ";
        q.pop();
    }
}

void leftViewLevelOrder(TreeNode *node)
{
    if (!node)
        return;
    queue<TreeNode *> q;
    q.push(node);
    vector<int> vec;
    int level = 0;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (level == vec.size())
            {
                vec.push_back(curr->val);
            }
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        level++;
    }
    for (auto e : vec)
    {
        cout << e << "   ";
    }
}

int levelCt(TreeNode *node)
{
    if (!node)
        return 0;
    queue<TreeNode *> q;
    q.push(node);
    int level = 0;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        level++;
    }
    return level;
}

void rightViewLevelOrder(TreeNode *node)
{
    if (!node)
        return;
    queue<TreeNode *> q;
    q.push(node);
    vector<int> vec(levelCt(node), 0);
    int level = 0;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            vec[level] = curr->val;
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        level++;
    }
    for (auto e : vec)
    {
        cout << e << "   ";
    }
}

int main()
{
    TreeNode *root = createTree();
    cout << "INORDER TRAVERSAL IS ";
    inorder(root);
    cout << "\nINORDER ITERATIVE IS ";
    inorderIt(root);
    cout << "\nREVERSE INORDER IS ";
    reverseInorder(root);
    cout << "\nLEFT TRAVERSAL IS : ";
    leftTraversal(root);
    cout << "\nRIGHT TRAVERSAL IS : ";
    rightTraversal(root);
    cout << "\nLEAF NODES ARE : ";
    leaf(root);
    cout << "\nLEFT TRAVERSAL WITHOUT ROOT : ";
    leftTraversalWithoutLeaf(root);
    cout << "\nRIGHT TRAVERSAL WITHOUT ROOT : ";
    rightTraversalWithoutLeaf(root);
    cout << "\nVERTICAL ORDER TRAVERSAL IS : ";
    map<int, vector<int>> mp;
    verticalTraversal(root, 0, mp);
    printMap(mp);
    cout << "\nPREORDER TRAVERSAL IS : ";
    preorder(root);
    cout << "\nPREORDER ITERATIVE IS : ";
    preorderIt(root);
    cout << "\nREVERSE PREORDER IS : ";
    reversePreorder(root);
    cout << "\nPOSTORDER TRAVERSAL IS : ";
    postorder(root);
    cout << "\nPOSTORDER ITERATIVE TRAVERSAL IS (USING TWO STACKS) : ";
    postorderIt(root);
    cout << "\nLEVEL ORDER TRAVERSAL : ";
    levelOrder(root);
    cout << "\nLEVEL ORDER TRAVERSAL (WITH LEVELS) : ";
    levelOrderWithLevels(root);
    cout << "\nMAXIMUM DEPTH : " << maxDepth(root);
    cout << "\nCHECK BALANCED BINARY TREE : ";
    balancedBinaryTree(root);
    cout << "\nDIAMETER IS : ";
    int dia = 0;
    diameter(root, dia);
    cout << dia;
    cout << "\nMAX PATH SUM IS : ";
    int maxSum = 0;
    maxPathSum(root, maxSum);
    cout << maxSum;
    cout << "\nIS SAME TREE : ";
    TreeNode *root1 = createTree1();
    cout << isSameTree(root, root1);
    cout << "\nZIG ZAG TRAVERSAL IS : ";
    zigZagTraversal(root);
    cout << "\nBOUNDARY TRAVERSAL IS : ";
    boundaryTraversal(root);
    cout << "\nTOP VIEW IS : ";
    topView(root);
    cout << "\nBOTTOM VIEW IS : ";
    bottomView(root);
    cout << "\nLEFT VIEW IS : ";
    queue<int> q;
    leftView(root, 0, q);
    printQueue(q);
    cout << "\nRIGHT VIEW IS : ";
    queue<int> qu;
    rightView(root, 0, qu);
    printQueue(qu);
    cout << "\nLEFT VIEW (LEVEL ORDER) IS : ";
    leftViewLevelOrder(root);
    cout << "\nNUMBER OF LEVELS IS : " << levelCt(root);
    cout << "\nRIGHT VIEW (LEVEL ORDER) IS : ";
    rightViewLevelOrder(root);
    return 0;
}
