class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(); // Dummy node to start the list
        ListNode* temp = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Update carry for next iteration
            carry = sum / 10;
            sum = sum % 10;

            // Create a new node for the current digit and move temp forward
            temp->next = new ListNode(sum);
            temp = temp->next;
        }

        // Return the head of the new list, which starts after the dummy node
        ListNode* head = dummy->next;
        
        // Free the dummy node
        delete dummy;

        return head;
    }
};
