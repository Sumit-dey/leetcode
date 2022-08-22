class Solution {
public:
    vector<int> v;
    int x, y;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    void dfs(TreeNode* root){
        if(!root) return;
        if(root->val == x){
            root->val = y;
        }
        else if(root->val == y){
            root->val = x;
        }
        dfs(root->left);
        dfs(root->right);

    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        x=INT_MIN, y=INT_MIN;
        for(int i=0; i<v.size()-1 ; i++){
            if(v[i+1]<v[i]){
                y = v[i+1];
                if(x==INT_MIN) x = v[i];
                else break;
            }
        }

        dfs(root);






    }
};
