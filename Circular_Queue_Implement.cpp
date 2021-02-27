  
#include "iostream"

class Queue{
    private:
        int front;
        int rear;
        int arr[5];
        int itemcount;
    public:
        Queue(){
            itemcount = 0;
            front = -1;
            rear = -1;
            for(int i = 0; i < 5; i++){
                arr[i] = 0;
            }
        }
        bool isEmpty(){
            if(front == -1 && rear == -1){
                return true;
            }
            else{
                return false;
            }
        }
        bool isFull(){
            if((rear+1) % 5 == front){
                return true;
            }
            else{
                return false;
            }
        }
        void enqueue(int val){
            if(isFull()){
                std::cout << "Queue is full." << std::endl;
                return;
            }
            else if(isEmpty()){
                front = rear = 0;
                itemcount++;
            }
            else{
                rear = (rear+1) % 5;
                itemcount++;
            }
            arr[rear] = val;
            std::cout << "Value enqueued" << std::endl;
        }
        int dequeue(){
            int x = 0;
            if(isEmpty()){
                std::cout << "Queue is empty." << std::endl;
                return 0;
            }
            else if(front == rear){
                x = arr[front];
                arr[front] = 0;
                front = rear = -1;
                itemcount--;
                return x;
            }
            else{
                x = arr[front];
                arr[front] = 0;
                front = (front + 1) % 5;
                itemcount--;
                return x;
            }
        }
        int count(){
            return itemcount;
        }
        void display(){
            std::cout << "All the values in the queue are : " << std::endl;
            for(int i = 0; i < 5; i++){
                std::cout << arr[i] << std::endl;
            }
        }

};

int main(){
    Queue q1;
    int option, value; 

    do{
        std::cout << "What operation do you want to execute? Press 0 to exit : " << std::endl;
        std::cout<< "1. Enqueue : " << std::endl;
        std::cout<< "2. Dequeue : " << std::endl;
        std::cout<< "3. isEmpty : " << std::endl;
        std::cout<< "4. isFull : " << std::endl;
        std::cout<< "5. Count : " << std::endl;
        std::cout<< "6. Display : " << std::endl;
        std::cout<< "7. Clear screen : " << std::endl << std::endl;

        std::cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            
            std::cout << "Enter value to enqueue : ";
            std::cin >> value;
            q1.enqueue(value);
            break;

        case 2:
            if(q1.dequeue()){
                std::cout << "Dequeued element " << q1.dequeue() << std::endl;
            }
            break;
        case 3:
            if(q1.isEmpty()){
                std::cout << "The Queue is empty" << std::endl;
            }
            else{
                std::cout << "The Queue is not empty" << std::endl;
            }
            break;
        case 4:
            if(q1.isFull()){
                std::cout << "The Queue is full" << std::endl;
            }
            else{
                std::cout << "The Queue is not full" << std::endl;
            }
            
            break;
        case 5:

            std::cout << "The Queue has " << q1.count() << " elements." << std::endl;
            
            break;
        case 6:
            std::cout << "Display function called." << std::endl;
            q1.display();
            break;
        
        case 7:
            system("cls");
            break;
        
        default:
            std::cout << "Enter valid number" << std::endl;
            break;
        }
    
    }while(option != 0);
}
