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
        
        bool isLeaf(TreeNode* root){
                if(root==NULL) return false;
                if(root->left==NULL && root->right==NULL){
                        return true;
                }
                return false;
        }
        
        void storeLeafs(TreeNode* root,vector<int> &vec){
                if(root==NULL) return;
                if(isLeaf(root))
                vec.push_back(root->val);
                storeLeafs(root->left,vec);
                storeLeafs(root->right,vec);
        }
        
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
         vector<int> vec1,vec2;
            storeLeafs(root1,vec1);
            storeLeafs(root2,vec2);
            if(vec1.size()!=vec2.size()) return false;
            for(int i=0;i<vec1.size();i++){
                    if(vec1[i]!=vec2[i]) return false;
            }
            // for(int i=0;i<vec1.size();i++){
            //         cout<<vec1[i]<<" "<<vec2[i]<<"\n";
            // }
            
            return true;
    }
};
