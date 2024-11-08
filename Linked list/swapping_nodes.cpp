/* 
ListNode* swapNodes(ListNode* head, int x, int y) {
    if (x == y || head == NULL) return head;  // No need to swap if x and y are the same

    ListNode *prevX = NULL, *prevY = NULL;
    ListNode *nodeX = head, *nodeY = head;

    // Find nodeX and its previous node
    while (nodeX != NULL && nodeX->val != x) {
        prevX = nodeX;
        nodeX = nodeX->next;
    }

    // Find nodeY and its previous node
    while (nodeY != NULL && nodeY->val != y) {
        prevY = nodeY;
        nodeY = nodeY->next;
    }

    // If either x or y is not present, return the list as is
    if (nodeX == NULL || nodeY == NULL) return head;

    // Special case: if nodeX and nodeY are adjacent
    if (nodeX->next == nodeY) {
        if (prevX != NULL) {
            prevX->next = nodeY;   // Update prevX's next to nodeY
        } else {  // If nodeX was the head
            head = nodeY;
        }

        // Swap nodeX and nodeY
        nodeX->next = nodeY->next;
        nodeY->next = nodeX;

    } else if (nodeY->next == nodeX) { // Adjacent but in reverse order (y before x)
        if (prevY != NULL) {
            prevY->next = nodeX;   // Update prevY's next to nodeX
        } else {  // If nodeY was the head
            head = nodeX;
        }

        // Swap nodeY and nodeX
        nodeY->next = nodeX->next;
        nodeX->next = nodeY;
    } else {
        // General case (non-adjacent nodes)
        if (prevX != NULL) {
            prevX->next = nodeY;
        } else {
            head = nodeY;
        }

        if (prevY != NULL) {
            prevY->next = nodeX;
        } else {
            head = nodeX;
        }

        // Swap next pointers
        ListNode* temp = nodeX->next;
        nodeX->next = nodeY->next;
        nodeY->next = temp;
    }

    return head;
}
*/