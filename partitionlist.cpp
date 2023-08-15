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
    ListNode *partition(ListNode *head, int x) {
        
        ListNode *smaller = new ListNode(0);
        ListNode *larger = new ListNode(0);
        ListNode *h1 = smaller;
        ListNode *h2 = larger;
        while(head)
        {
            if(head->val < x)
            {
                smaller->next = head;
                smaller = smaller->next;
            } else {
                larger->next = head;
                larger = larger->next;
            }
            head = head->next;
        }
        larger->next = NULL;
        smaller->next = h2->next;;
        return h1->next;
    }
};