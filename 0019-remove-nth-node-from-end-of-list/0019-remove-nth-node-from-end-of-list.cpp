// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {

//         int length = 0;
//         ListNode* temp = head;

//         while(temp != NULL) {
//             length++;
//             temp = temp->next;
//         }

//         // If head itself needs to be removed
//         if(n == length) {
//             return head->next;
//         }

//         temp = head;

//         for(int i = 1; i < length - n; i++) {
//             temp = temp->next;
//         }

//         temp->next = temp->next->next;

//         return head;
//     }
// };
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;

        return dummy->next;
    }
};