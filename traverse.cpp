/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;
        int level = 0;
        if(root == NULL){
            return -1;
        }
        queue<TreeNode*> q;
        long long sum = 0;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* temp = q.front();

            if(temp!=NULL){
                sum = sum+temp->val;
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            else{
                level++;
                ans.push_back(sum);
                sum = 0;
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        sort(ans.begin(),ans.end());
        long long larLevelSum;
        if(k<=level){
            larLevelSum = ans[ans.size()-k];
        }
        else{
            larLevelSum = -1;
        }
        
        return larLevelSum;
    }
};