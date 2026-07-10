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
    bool isPalindrome(ListNode* head) {
        ListNode* mid = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            mid = mid->next;
            fast = fast->next->next;
        }
        stack<int> st;
        while (mid != NULL) {
            st.push(mid->val);
            mid = mid->next;
        }

        while (!st.empty()) {
            if (head->val != st.top())
                return false;

            st.pop();
            head = head->next;
        }

        return true;
    }
};