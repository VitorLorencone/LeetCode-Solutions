/* 
Let n be the number of nodes in the list

Time Complexity: O(n)
Space Complexity: O(1)

A simple and easy two pointers solution.

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
    ListNode* middleNode(ListNode* head) {
        ListNode* p = head;
        ListNode* q = head;
        while(p->next != nullptr){
            if(p->next->next != nullptr){
                p = p->next->next;
            }else{
                p = p->next;
            }
            q = q->next;
        }
        return q;
    }
};

int main(){

    Solution sol = Solution();
    ListNode* p = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));

    cout << sol.middleNode(p)->val << endl;

    delete p->next;
    delete p;

}