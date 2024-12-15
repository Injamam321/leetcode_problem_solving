// 100. Same Tree
// cpp Solution! problem-100

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, the trees are the same
        if (!p && !q) return true;
        
        // If one of the nodes is null but the other is not, the trees are different
        if (!p || !q) return false;
        
        // If the values of the nodes are different, the trees are different
        if (p->val != q->val) return false;
        
        // Recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
