class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next != NULL && prev->next->next != NULL) {

            ListNode* curr = prev->next;
            ListNode* next = curr->next;

            // swap
            curr->next = next->next;
            next->next = curr;

            // previous part ko swapped pair se connect karo
            prev->next = next;

            // next pair par move
            prev = curr;
        }

        return dummy->next;
    }
};