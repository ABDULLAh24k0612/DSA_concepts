void bubblesort(){
        Node*temp;
        Node*last=NULL;
        bool swapped=false;
        do{
            temp=head;
            swapped=false;
            while(temp->next!=last){
                if(temp->data>temp->next->data){
                    int t2=temp->data;
                    temp->data=temp->next->data;
                    temp->next->data=t2;
                    swapped=true;
                }
                temp=temp->next;
            }
            last=temp;
        }while (swapped);
        
        
    }
