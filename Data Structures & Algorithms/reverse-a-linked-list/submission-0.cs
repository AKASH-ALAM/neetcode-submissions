/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

public class MyList {
    public ListNode head;
    public void AddFirst(int val){
        ListNode newNode = new ListNode(val, null);
        newNode.next = head;
        head = newNode;
    }
}
 
public class Solution {
    public ListNode ReverseList(ListNode head) {
        MyList list = new MyList();

        ListNode currentNode = head;
        while(currentNode != null){
            list.AddFirst(currentNode.val);
            currentNode = currentNode.next;
        }
        return list.head;
    }
}
