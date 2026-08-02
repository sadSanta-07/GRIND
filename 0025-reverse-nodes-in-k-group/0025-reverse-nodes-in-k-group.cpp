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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        // check
        while (cnt < k) {
            if (temp == NULL) {
                return head;
            } else {
                temp = temp->next;
                cnt++;
            }
        }
        // recirecive call for rest
        ListNode* prevnode = reverseKGroup(temp, k);

        // reverse curr grp
        temp = head;
        cnt = 0;
        while (cnt < k) {
            ListNode* next = temp->next;
            temp->next = prevnode;
            prevnode = temp;
            temp = next;
            cnt++;
        }
        return prevnode;
    }
};