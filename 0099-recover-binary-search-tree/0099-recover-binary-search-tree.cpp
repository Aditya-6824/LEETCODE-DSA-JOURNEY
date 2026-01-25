
class Solution {
private:
    TreeNode *first, *prev, *middle, *last;


    void Inorder(TreeNode* node){
        if(node){
            Inorder(node->left);
            

            if(prev && prev->val > node->val){
                if(!first){
                    first = prev;
                    middle = node;
                }else{
                    last = node;
                }
            }
            prev = node;

            Inorder(node->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        //initialize first, last, middle, prev pointer to null
        first = last = middle = prev = nullptr;

        //call the inorder
        Inorder(root);

        //check the nodes and swap the values
        if(first && last){
            swap(first->val, last->val);
        }else if(first && middle){
            swap(first->val, middle->val);
        }
    }
};