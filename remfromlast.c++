/*                     Remove nth node frm the end question number 19 leetcode   */
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
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if (head == NULL) {
//             return NULL;
//         }

//         ListNode* dummy = new ListNode(0);
//         dummy->next = head;

//         ListNode* slow = dummy;
//         ListNode* fast = dummy;

//         // Move the fast pointer n steps ahead
//         for (int i = 0; i <= n; i++) {
//             fast = fast->next;
//         }

//         // Move both pointers until the fast pointer reaches the end
//         while (fast != NULL) {
//             fast = fast->next;
//             slow = slow->next;
//         }

//         // Remove the nth node
//         ListNode* toDelete = slow->next;
//         slow->next = slow->next->next;
//         delete toDelete;

//         return dummy->next;
//     }
// };
// phela ak dummy element banaya jisaki corner pa dikat na aaya jesa ki
// agar aka hi element ho ya fir last or phela first ko utna step aaga 
// aga kar do