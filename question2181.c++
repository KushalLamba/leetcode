// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* mergeNodes(ListNode* head) {
//         ListNode* newhead = NULL;
//         ListNode* tail = NULL;
//         int sum = 0;
//         while (head != NULL) {
//             if (head->val == 0 && sum != 0) {
//                 if (newhead == NULL) {
//                     newhead = new ListNode(sum);
//                     tail = newhead;
//                 } else {
//                     tail->next = new ListNode(sum);
//                     tail = tail->next;
//                 }
//                 sum = 0;
//             }
//             sum += head->val;
//             head = head->next;
//         }
//         return newhead;
//     }
// };