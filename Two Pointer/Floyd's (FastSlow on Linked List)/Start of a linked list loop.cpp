
// gfg link: https://www.geeksforgeeks.org/dsa/find-first-node-of-loop-in-a-linked-list/#expected-approach-using-floyds-loop-detection-algorithm-on-time-and-o1-space

int cycleStart(Node* head) {
  
    // Initialize two pointers, slow and fast
    Node* slow = head;
    Node* fast = head;
    
    // Traverse the list
    while (fast != nullptr && fast->next != nullptr) {
      
      	// Move slow pointer by one step
        slow = slow->next;          
      
      	// Move fast pointer by two steps
        fast = fast->next->next;    

        // Detect loop
        if (slow == fast) {
          
            // Move slow to head, keep fast at meeting point
            slow = head;
            
            // Move both one step at a time until they meet
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            
            // Return the meeting node, which
          	// is the start of the loop
            return slow->data;
        }
    }
    
    // No loop found
    return -1;
}