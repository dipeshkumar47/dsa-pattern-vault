
// article: https://www.geeksforgeeks.org/dsa/detect-loop-in-a-linked-list/




bool detectLoop(Node* head) {
  
    ListNode *slow = head, *fast = head;

    // Loop that runs while fast and slow pointer are not
    // nullptr and not equal
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // If fast and slow pointer points to the same node,
        // then the cycle is detected
        if (slow == fast) {
            return true;
        }
    }
    return false;
}







