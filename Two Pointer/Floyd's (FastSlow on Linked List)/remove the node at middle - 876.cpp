// article: https://www.geeksforgeeks.org/dsa/delete-middle-of-linked-list/#expected-approach-onepass-traversal-with-slow-and-fast-pointers-on-time-and-o1-space

// que : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/


// leetcode working solution
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if (head == nullptr)
            return nullptr;

        if (head->next == nullptr)    // After deleting the middle node, what should remain? ans: null
            return nullptr; 

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        // delete slow             // it will throw error in the leetcode

        return head;
    }
};