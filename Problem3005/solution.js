/* 
Let n be the number of nodes in the list

Time Complexity: O(n)
Space Complexity: O(1)

A simple and easy two pointers solution.
*/

function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var middleNode = function(head) {
    let p = head;
    let q = head;
    while(p.next != null){
        if(p.next.next != null){
            p = p.next.next;
        }else{
            p = p.next;
        }
        q = q.next;
    }
    return q;
};

let p = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, null))))))
console.log(middleNode(p))