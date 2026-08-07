class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;
        while (curr != nullptr) {
            while (!st.empty() && st.top()->val < curr->val)
                st.pop();
            st.push(curr);
            curr = curr->next;
        }
        ListNode* next = nullptr;
        while (!st.empty()) {
            st.top()->next = next;
            next = st.top();
            st.pop();
        }
        return next;
    }
};