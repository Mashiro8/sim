#include<iostream>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void mid(TreeNode* root) 
{
    if (root == NULL) 
    {
        return;
    }   
    mid(root->left);  
    cout << root->val << " ";   
    mid(root->right);
}
int main() {
    //tạo cây nhị phân
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);  
    //thứ tự duyệt
    cout << "thu tu duyet la ";
    mid(root);
    return 0;
}