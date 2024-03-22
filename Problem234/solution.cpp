/* 
Let n be the size of the linked list *head*

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = nullptr;
        ListNode* p = head;

        while(p != nullptr){
            ans = new ListNode(p->val, ans);
            p = p->next;
        }

        return ans;
    }
};

int main(){
    Solution sol = Solution();
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* ans = sol.reverseList(head);
    ListNode* p = ans;

    while(p != nullptr){
        cout << p->val << " ";
        p = p->next;
    }
}