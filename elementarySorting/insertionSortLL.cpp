// Insertion Sort function for Linked List
Node* insertionSortLinkedList(Node* head) {
    // Dummy node to act as the new sorted list's head
    Node* sortedHead = new Node(0);

   Node* insertionSort(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    Node* sorted = NULL;  // Start with empty sorted list

    Node* current = head;
    while (current != NULL) {
        Node* next = current->next; // Save next node

        // Insert current node into sorted list
        if (sorted == NULL || current->data < sorted->data) {
            // Insert at the beginning
            current->next = sorted;
            sorted = current;
        } else {
            // Find position to insert
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }

            current->next = temp->next;
            temp->next = current;
        }

        current = next; // Move to next node in original list
    }

    return sorted;
}
