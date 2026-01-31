
class Solution {
    public ListNode deleteDuplicates(ListNode head) {

        if(head == null || head.next == null){
            return head;
        }

        ListNode temp = new ListNode(0);
        ListNode p = head;
        ListNode ans = temp;

        while( p != null){
            if(p.next != null && p.val == p.next.val){
                while(p.next != null && p.val == p.next.val){
                    p = p.next;
                }
                p = p.next;
            }
            else{
                temp.next = p;
                temp = temp.next;
                p = p.next;
                temp.next = null; // 🔥 VERY IMPORTANT
            }
            
        }

        return ans.next;
    }
}