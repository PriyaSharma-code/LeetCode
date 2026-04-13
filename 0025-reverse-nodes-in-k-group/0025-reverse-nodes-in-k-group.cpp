/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        if(left!=0){
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        }
        ListNode* current = prev->next;
        
        
        for (int i = 0; i < right - left; ++i) {
            ListNode* next_node = current->next;
            current->next = next_node->next;
            next_node->next = prev->next;
            prev->next = next_node;
        }
        
        return dummy.next;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) {
            return NULL;
        }
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        ListNode* next = nullptr;
        int count = 0;

        // Count the total number of nodes
        while (curr) {
            count++;
            curr = curr->next;
        }

        curr = head;

        // Reverse in groups of `k`
        while (count >= k) {
            for (int i = 1; i < k; ++i) {
                next = curr->next;
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            prev = curr;
            curr = curr->next;
            count -= k;
        }

        return dummy.next;
    }
};