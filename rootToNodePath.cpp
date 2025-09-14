#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int num){
        val = num;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* getRoot(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    return root;
}

bool path(TreeNode* node, vector<int>& ds,int target){
    if(!node){
        return false;
    }
    ds.push_back(node->val);
    if(node->val == target){return true;}
    if(path(node->left,ds,target) || path(node->right,ds,target)){
        return true;
    }
    ds.pop_back();
    return false;
}

void print(vector<int>& vec){
    for(auto e : vec){
        cout << e << "   ";
    }
    cout << endl;
}

int main(){
    TreeNode* root = getRoot();
    vector<int> ds;
    path(root,ds,7);
    print(ds);
    ds={};
    path(root,ds,3);
    print(ds);
    return 0;
}




