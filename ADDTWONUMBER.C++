/*                            ADD TWO NUMBER                                    */
// #include<bits/stdc++.h>
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
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* head = NULL;
//         ListNode* tail = NULL;
//         while(l1!=NULL && l2!=NULL)
//         {
//             int sum=(l1->val+l2->val)%10;
//             if(head==NULL)
//             {
//                 ListNode* newnode=new ListNode(sum);
//                 head=newnode;
//                 tail=newnode;
//             }
//             else
//             {
//                 ListNode* newnode=new ListNode(sum);
//                 tail->next=newnode;
//                 tail=tail->next;
//             }
//             int carry=(l1->val+l2->val)/10;
//             if(carry!=0)
//             {
//             if(l1->next==NULL && l2->next==NULL)
//             {
//                 ListNode* newnode=new ListNode(carry);
//                 tail->next=newnode;
//                 tail=tail->next;
//                 tail->next=NULL;
//                 return head;
//             }
//             else if(l1->next==NULL)
//             {
//                l2->next->val+=carry;
//             }
//             else
//             {
//                 l1->next->val+=carry;
//             }
//             }
//             l1=l1->next;
//             l2=l2->next;
//         }
//         while (l1 != NULL) {
//             if (l1->val < 10) {
//                 ListNode* newnode = new ListNode(l1->val);
//                 tail->next = newnode;
//                 tail = tail->next;
//             } else {
//                 if (l1->next != NULL) {
//                     l1->next->val += ((l1->val) / 10);
//                     ListNode* newnode = new ListNode((l1->val) % 10);
//                     tail->next = newnode;
//                     tail = tail->next;
//                 }
//                 if (l1->next == NULL) {
//                     ListNode* newnode = new ListNode((l1->val) % 10);
//                     ListNode* newnode1 = new ListNode((l1->val) / 10);
//                     tail->next = newnode;
//                     tail = tail->next;
//                     tail->next = newnode1;
//                     tail = tail->next;
//                 }
//             }
//             l1 = l1->next;
//         }
//         while (l2 != NULL) {
//             if (l2->val < 10) {
//                 ListNode* newnode = new ListNode(l2->val);
//                 tail->next = newnode;
//                 tail = tail->next;
//             } else {
//                 if (l2->next != NULL) {
//                     l2->next->val += ((l2->val) / 10);
//                     ListNode* newnode = new ListNode((l2->val) % 10);
//                     tail->next = newnode;
//                     tail = tail->next;
//                 }
//                 if (l2->next == NULL) {
//                     ListNode* newnode = new ListNode((l2->val) % 10);
//                     ListNode* newnode1 = new ListNode((l2->val) / 10);
//                     tail->next = newnode;
//                     tail = tail->next;
//                     tail->next = newnode1;
//                     tail = tail->next;
//                     tail->next=NULL;
//                     return head;
//                 }
//             }
//             l2 = l2->next;
//         }
//         tail->next = NULL;
//         return head;
//     }
// };