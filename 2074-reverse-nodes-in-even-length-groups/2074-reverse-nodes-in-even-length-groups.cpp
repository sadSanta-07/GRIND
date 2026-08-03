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
    ListNode* reverse(ListNode* head, int n) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr && n > 0) {

            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;

            n--;
        }

        return prev;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {

        int gn = 1;

        ListNode* curr = head;
        ListNode* prevGroupTail = nullptr;

        while (curr != nullptr) {

            // find actual length of current group
            int len = 0;
            ListNode* temp = curr;

            while (temp != nullptr && len < gn) {
                temp = temp->next;
                len++;
            }

            if (len % 2 == 0) {

                ListNode* oldHead = curr;
                ListNode* nextGroup = temp;

                ListNode* newHead = reverse(curr, len);

                if (prevGroupTail != nullptr) {
                    prevGroupTail->next = newHead;
                }
                oldHead->next = nextGroup;
                prevGroupTail = oldHead;
                curr = nextGroup;

            } else {

                for (int i = 0; i < len; i++) {
                    prevGroupTail = curr;
                    curr = curr->next;
                }
            }
            gn++;
        }

        return head;
    }
};