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
//  class ListNode{
//     public:
//         int val;
//         ListNode* next;

//         ListNode(int val){
//             this -> val = val;
//             this -> next = NULL;
//         }
//  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp != NULL){
            ListNode* front = temp -> next;
            temp -> next = prev;
            prev= temp;
            temp = front;
        }
        return prev;

    }
};