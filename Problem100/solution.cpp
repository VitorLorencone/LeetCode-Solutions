/* 
Let n be the number of nodes in the tree and h be the height of the tree

Time Complexity: O(n)
Space Complexity: O(h)

A simple and easy recursive solution.

*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr){
            return true;
        }else if(p == nullptr || q == nullptr){
            return false;
        }
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(){

    Solution sol = Solution();
    TreeNode* p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    cout << sol.isSameTree(p, q) << endl;

    p = new TreeNode(1, new TreeNode(2), nullptr);
    q = new TreeNode(1, nullptr, new TreeNode(2));

    cout << sol.isSameTree(p, q) << endl;

    delete p->right;
    delete p->left;
    delete p;
    delete q->right;
    delete q->left;
    delete q;

}