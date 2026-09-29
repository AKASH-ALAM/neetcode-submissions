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

 public class SortedList {
    public ListNode head;
    public SortedList(ListNode hd){
        head = hd;
    }
    public void Add(int val){
        ListNode newNode = new ListNode(val, null);
        if(head == null){
            head = newNode;
            return;
        }
        if(val <= head.val){
            newNode.next = head;
            head = newNode;
            return;
        }

        ListNode currentNode = head;

        while(currentNode.next != null && currentNode.next.val < val){
            currentNode = currentNode.next;
        }

        newNode.next = currentNode.next;
        currentNode.next = newNode;
    }
 }
 
public class Solution {
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        SortedList list = new SortedList(list1);

        while(list2 != null){
            list.Add(list2.val);
            list2 = list2.next;
        }
        return list.head;
    }
}