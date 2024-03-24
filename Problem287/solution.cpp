/* 
Let n be the size of the linked list *head*

Time Complexity: O(n)
Space Complexity: O(1)

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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode* middle = head;
        ListNode* p = head;
        ListNode* prev = NULL;

        while(middle != nullptr && middle->next != nullptr){
            middle = middle->next->next;
            ListNode* temp = p->next;
            p->next = prev;
            prev = p;
            p = temp;
        }

        if(middle){
            p = p->next;
        }

        while(prev && p){
            if(prev->val != p->val){
                return false;
            }
            prev = prev->next;
            p = p->next;
        }

        return true;
    }
};

int main(){
    Solution sol = Solution();
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(1)))));
    cout << sol.isPalindrome(head);
}