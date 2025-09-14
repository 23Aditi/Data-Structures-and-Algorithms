#include <iostream>
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

TreeNode* createRoot(){
    TreeNode* root = new TreeNode(3);
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

void inorder(TreeNode* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);

}

void leafNodes(TreeNode* root){
    if(!root){return;}
    if(!root->left && !root->right){
        cout << root->val << " ";
        return;
    }
    leafNodes(root->left);
    leafNodes(root->right);
}

void leftTraversal(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    
    if(root->left){leftTraversal(root->left);}
    else {leftTraversal(root->right);}
}

void leftTraversalWithOutLeft(TreeNode* root){
    if(!root->left && !root->right){
        return;
    }
    cout << root->val << " ";
    
    if(root->left){leftTraversalWithOutLeft(root->left);}
    else {leftTraversalWithOutLeft(root->right);}
}

void rightTraversal(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    if(root->right){
        rightTraversal(root->right);
    }else{
        rightTraversal(root->left);
    }
}


void rightTraversalWithOutLeaf(TreeNode* root){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        return;
    }
    cout << root->val << " ";
    if(root->right){
        rightTraversalWithOutLeaf(root->right);
    }else{
        rightTraversalWithOutLeaf(root->left);
    }
}

int main(){
    TreeNode* root = createRoot();
    rightTraversalWithOutLeaf(root);
}












