#include <iostream>

using namespace std;

class Node{
    public:
        int key;
        int data;
        Node* next;
        Node* previous;

        Node(){
            key = 0;
            data = 0;
            next = NULL;
            previous = NULL;
        }

        Node(int k, int d){
            key = k;

            data = d;
        }

};

class DoublyLinkedList{
    public:
        Node* head;

        DoublyLinkedList(){
            head = NULL;
        }

        DoublyLinkedList(Node* n){
            head = n;
        }

        //1.Check if Node exists using key value
        Node* nodeExists(int k){
            Node* temp = NULL;
            Node* ptr = head;

            while(ptr != NULL){
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
                cout << "Node already exists with key value : " << n->key << " . Append another node with different key" << endl;
            }
            else{
                if(head == NULL){
                    head = n;
                    cout << "Node appended as Head Node" << endl;
                }
                else{
                    Node* ptr = head;

                    while(ptr->next != NULL){
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    n->previous = ptr;
                    cout << "Node appended succesfully !" << endl;
                }
            }
        }

        //3. Prepend Node - attach a node at the start
        void prependNode(Node* n){
            if(nodeExists(n->key) != NULL){
                cout << "Node already exists with key value : " << n->key <<". Append another node with different key value" << endl;
            }
            else{
                if(head == NULL){
                    head = n;
                    cout << "Node prepended as a Head Node" << endl;
                }
                else{
                    head->previous = n;
                    n->next = head;
                    head = n;

                    cout << "Node prepended succesfully !" << endl;
                }
            }
        }

        //4.Insert Node after a particular Node in the list
        void insertNodeAfter(int k, Node* n){
            Node* ptr = nodeExists(k);
            if(ptr == NULL){
                cout << "Node node exists with the key value : " << k << ". Try again with different value "<< endl;
            }
            else{
                if(nodeExists(n->key) != NULL){
                    cout << "Node already exists with key value : " << n->key << ". Append another node with different value " << endl;
                }
                else{
                    Node* nextNode = ptr->next;

                    //Inserting at the end
                    if(nextNode == NULL){
                        ptr->next = n;
                        n->previous = ptr;
                        cout << "Node inserted at the end" << endl;
                    }
                    //inserting in between
                    else{
                        n->next = nextNode;
                        nextNode->previous = n;
                        n->previous = ptr;
                        ptr->next = n;

                        cout << "Node Inserted succesfully !" << endl;
                    }
                }
            }
        }

        //5.Delete node by Unique key, Basically De-Link not delete
        void deleteNodebykey(int k){
            Node* ptr = nodeExists(k);

            if(ptr == NULL){
                cout << "Node doesn't exist with key value : " << k << endl;
            }
            else{
                if(head->key == k){
                    head = head->next;
                    cout << "Node unlinked with the key value : " << k << endl;
                }
                else{
                    Node* nextNode = ptr->next;
                    Node* prevNode = ptr->previous;

                    //deleting at the end
                    if(nextNode == NULL){
                        prevNode->next = NULL;
                        cout << "Node deleted at the end " << endl;
                    }
                    //deleting in between
                    else{
                        prevNode->next = nextNode;
                        nextNode->previous = prevNode;

                        cout << "Node deleted succesfully !" << endl;
                    }
                }
            }
        }

        //6. Update Node
        void updateNodebykey(int k, int d){
            Node* ptr = nodeExists(k);

            if(ptr!=NULL){
                ptr->data = d;
                cout << "Node updated succesfully" << endl;
            }
            else{
                cout << "Node doesn't exists with key " << k << endl;
            }
        }

        //7.printing the list
        void printList(){
            if(head == NULL){
                cout << "No nodes in doubly linked list" << endl;
            }
            else{
                cout << endl << "Doubly linked list values : ";
                Node* temp = head;

                while(temp != NULL){
                    cout << "(" << temp->key << " , " << temp->data << ") <-->";

                    temp = temp->next;
                }

            }
        }

};

int main(){

    DoublyLinkedList obj;

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
                obj.appendNode(n1);

                break;
            case 2:
                cout << "Prepend Node operation\nEnter key & data of the node to be prepended : " << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;
                obj.prependNode(n1);

                break;

            case 3:
                cout << "Insert node operation\nEnter key of node after which you want to insert : "<< endl;
                cin >> k1;
                cout <<"Enter the key & data : " << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;

                obj.insertNodeAfter(k1, n1);
                break;

            case 4:
                cout << "Delete node by key operation\nEnter key : ";
                cin >> k1;
                obj.deleteNodebykey(k1);
                break;

            case 5:
                cout << "Update node by key operation\nEnter key & data : " << endl;
                cin >> key1;
                cin >> data1;
                obj.updateNodebykey(key1, data1);
                break;

            case 6:
                obj.printList();
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
