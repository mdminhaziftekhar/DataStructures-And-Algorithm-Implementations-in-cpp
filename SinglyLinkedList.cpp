#include <iostream>

using namespace std;

class Node{
    public:
        int key;
        int data;
        Node* next;

        Node(){
            key = 0;
            data = 0;
            next = NULL;
        }
        Node(int k, int d){
            key = k;
            data = d;
        }
};

class SinglyLinkedList{
    public:
        Node* head;

        SinglyLinkedList(){
            head = NULL;
        }

        SinglyLinkedList(Node* n){
            head = n;
        }
        //1.Checks if a key exits or not
        Node* nodeExists(int k){
            Node* temp = NULL;
            Node* ptr = head;

            while(ptr!=NULL){
                if(ptr->key == k){
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            return temp;
        }

        //2.Append a node to the list
        void appendNode(Node* n){
            if(nodeExists(n->key) != NULL){
                cout << "Node already exists with key value : "<< n->key << ". Append another node with different key" << endl;
            }
            else{
                if(head == NULL){
                    head = n;
                    cout << "Node appended succesfully ! " << endl;
                }
                else{
                    Node* ptr = head;

                    while(ptr->next != NULL){
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    cout << "Node appended succesfully !" << endl;
                }
            }
        }

        //3.Prepend node - attach a node at the start
        void prependNode(Node* n){
            if(nodeExists(n->key) != NULL){
                cout << "Node already exists with key : " << n->key << ". Append another node with different key " << endl;
            }
            else{
                n->next = head;
                head = n;
                cout << "Node Prepended succesfully !" << endl;
            }
        }

        //4.Insert a node after a particular node in the list
        void insertNodeAfter(int k, Node* n){
            Node* ptr = nodeExists(k);

            if(ptr == NULL){
                cout << "No Node Exists with key value " << k << endl;
            }
            else{
                if(nodeExists(n->key) != NULL){
                    cout << "Node already exists with key value " << n->key << ". Append another node with different key" << endl;
                }
                else{
                    n->next = ptr->next;
                    ptr->next = n;
                    cout << "Node inserted succesfully !" << endl;
                }
            }
        }

        //5. Delete Node by unique key
        void deleteNodebykey(int k){
            if(head == NULL){
                cout << "List already empty, can't delete " << endl;
            }
            else if(head != NULL){
                if(head->key == k){
                    head = head->next;
                    cout << "Node unlinked with key value : " << k << endl;
                }
                else{
                    Node* temp = NULL;
                    Node* prevptr = head;
                    Node* currentptr = head->next;

                    while(currentptr != NULL){
                        if(currentptr->key == k){
                            temp = currentptr;
                            currentptr = NULL;
                        }
                        else{
                            prevptr = prevptr->next;
                            currentptr = currentptr->next;
                        }
                    }
                    if(temp != NULL){
                        prevptr->next = temp->next;
                        cout << "Node unlinked with keys value " << k << endl;
                    }
                    else{
                        cout << "Node doesn't exists with key " << k << endl;
                    }
                }
            }
        }

        //6. Update node
        void updateNodebykey(int k, int d){
            Node* ptr = nodeExists(k);
            if(ptr != NULL){
                ptr->data = d;
                cout << "Node data updated" << endl;
            }
            else{
                cout << "Node doesn't exist with key " << k << ". Enter a valid key" << endl;
            }
        }

        //7. Printing
        void printList(){
            if(head == NULL){
                cout << "No nodes available in the singly linked list" << endl;
            }
            else{
                cout << endl << "Singly Linked List values : ";
                Node* temp = head;
                while(temp != NULL){
                    cout <<"(" << temp->key << " , " << temp->data << ")" << " --> ";
                    temp = temp->next;
                }
            }
        }
};

int main(){

    SinglyLinkedList s;

    int key1, k1, data1;

    int option;

    do{
        cout << "\nWhat operation to perform? : (Enter 0 to exit)" << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeBykey()" << endl;
        cout << "5. updateNodeBykey()" << endl;
        cout << "6. printList()" << endl;
        cout << "7. clearScreen()" << endl;

        cin >> option;

        Node *n1 = new Node(); //creates node in heap memory

        switch(option){
            case 0:
                break;
            case 1:
                cout << "Append Node operation\nEnter key & data of the node to be appended : " << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;
                s.appendNode(n1);

                break;
            case 2:
                cout << "Prepend Node operation\nEnter key & data of the node to be prepended : " << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;
                s.prependNode(n1);

                break;

            case 3:
                cout << "Insert node operation\nEnter key of node after which you want to insert : "<< endl;
                cin >> k1;
                cout <<"Enter the key & data : " << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;

                s.insertNodeAfter(k1, n1);
                break;

            case 4:
                cout << "Delete node by key operation\nEnter key : ";
                cin >> k1;
                s.deleteNodebykey(k1);
                break;

            case 5:
                cout << "Update node by key operation\nEnter key & data : " << endl;
                cin >> key1;
                cin >> data1;
                s.updateNodebykey(key1, data1);
                break;

            case 6:
                s.printList();
                break;

            case 7:
                system("cls");
                break;

            default:
                cout << "Enter a proper number " << endl;
        }

    }while(option!=0);

    return 0;
}
