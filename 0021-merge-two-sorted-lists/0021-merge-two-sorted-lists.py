# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # check whether list is None
        if not list1:
            return list2
        if not list2:
            return list1
        
        # now list1 and list2 are not None
        p1, p2 = list1, list2
        dummy_node = ListNode('dummy')
        p = dummy_node
        while p1 and p2:
            if p1.val < p2.val:
                p.next = p1
                p1 = p1.next
            else:
                p.next = p2
                p2 = p2.next
            p = p.next
        
        if p1:
            p.next = p1
        
        if p2:
            p.next = p2

        
        return dummy_node.next
            


            
        