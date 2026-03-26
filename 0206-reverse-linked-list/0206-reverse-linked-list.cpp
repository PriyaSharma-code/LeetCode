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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* node = nullptr;
        ListNode* cur = head;

        while(cur != nullptr){
            ListNode* next = nullptr;
            next = cur->next;
            cur->next = node;
            node = cur;
            cur = next;
        }
        return node;
    }
};