//article : https://www.geeksforgeeks.org/dsa/function-to-check-if-a-singly-linked-list-is-palindrome/


// optimal solution:


// Function to reverse a linked list
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


// Function to check if two lists are identical
bool isIdentical(Node* n1, Node* n2) {

    for (; n1 && n2; n1 = n1->next, n2 = n2->next)
        if (n1->data != n2->data)
            return 0;

    return 1;
}


// Function to check whether the list is palindrome
bool isPalindrome(Node* head) {
    if (!head || !head->next)
        return true;

    Node* slow = head;
    Node* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list and reverse the second half
    Node* head2 = reverse(slow->next);
    slow->next = nullptr; // End the first half

    // Check if the two halves are identical
    bool ret = isIdentical(head, head2);

    // Restore the original list
    head2 = reverse(head2);
    slow->next = head2;

    return ret;
}



