void selectionSort(Node* head) {
   
    for (Node* i = head; i != nullptr; i = i->next) {
        Node* minNode = i;  

       
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (j->data < minNode->data) {
                minNode = j;  
            }
        }

       
        if (minNode != i) {
            int temp = i->data;
            i->data = minNode->data;
            minNode->data = temp;
        }
    }
}
