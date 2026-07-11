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
//     bool isPalindrome(ListNode* head) {
//         ListNode* mid = head;
//         ListNode* fast = head;
//         while (fast != NULL && fast->next != NULL) {
//             mid = mid->next;
//             fast = fast->next->next;
//         }
//         stack<int> st;
//         while (mid != NULL) {
//             st.push(mid->val);
//             mid = mid->next;
//         }

//         while (!st.empty()) {
//             if (head->val != st.top())
//                 return false;

//             st.pop();
//             head = head->next;
//         }

//         return true;
//     }
// };

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reverse(slow);

        ListNode* first = head;

        while (second != nullptr) {
            if (first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};