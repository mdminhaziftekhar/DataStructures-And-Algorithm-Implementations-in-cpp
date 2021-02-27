#include <iostream>

class stack{
    
    private:
        int top;
        int arr[5];
    
    public:
        stack(){
            top = -1;
            for(int i = 0; i < 5; i++){
                arr[i] = 0;
            }
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
        }
        bool isFull(){
            if(top == 4){
                return true;
            }
            else{
                return false;
            }
        }
        void push(int val){
            if(isFull()){
                std::cout<< "Stack Overflow" << std::endl;
            }
            else{
                top++;
                arr[top] = val;
            }
        }
        int pop(){
            if(isEmpty()){
                std::cout << "Stack Underflow" << std::endl;
                return 0;
            }
            else{
                int popvalue = arr[top];
                arr[top] = 0;
                top--;
                return popvalue;
            }
        }
        int count(){
            return top+1;
        }
        int peek(int pos){
            if(isEmpty()){
                std::cout << "Stack Underflow" << std::endl;
                return 0;
            }
            else{
                return arr[pos];
            }
        }
        void change(int pos, int val){
            arr[pos] = val;
            std::cout << "Value changed at location " << pos << std::endl;
        }
        void display(){
            std::cout << "All values in the stack are : " << std::endl;
            for(int i = 4; i >= 0; i--){
                std::cout << arr[i] << std::endl;
            }
        }
};

int main(){
    stack s1;

    int option, position, value;

    do{
        std::cout << "Select an option number. Enter 0 to exit." << std::endl;
        std::cout << "1.Push() \n2.Pop() \n3.isEmpty() \n4.isFull() \n5.peek() \n6.count() \n7.change() \n8.display() \n9.clear screen\n\n";

        std::cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            std::cout << "Enter an item to push in : ";
            std::cin >> value;
            s1.push(value);
            break;
        case 2:
            std::cout << "Pop() called. Popped value is " << s1.pop() << std::endl;
            break;
        case 3:
            if(s1.isEmpty()){
                std::cout << "The stack is empty" << std::endl;
                break;
            }
            else{
                std::cout << "No, the stack is not empty" << std::endl;
                break;
            }
        case 4:
            if(s1.isFull()){
                std::cout << "The stack is full." << std::endl;
                break;
            }
            else{
                std::cout << "The stack is not full." << std::endl;
                break;
            }
        case 5:
            std::cout << "Enter the position to peek : ";
            std::cin >> position;
            std::cout << "Peek function called in position " << position << " Value is " << s1.peek(position) << std::endl;
            break;
        case 6:
            std::cout << "There are " << s1.count() << " elements is the stack" << std::endl;
            break;
        case 7:
            std::cout << "Enter the postion : ";
            std::cin >> position;
            std::cout << "Enter the value : ";
            std::cin >> value;
            s1.change(position, value);
            break;
        case 8:
            s1.display();
            break;
        case 9:
            system("cls");
            break;
        
        default:
            std::cout << "Enter proper number."<<std::endl;
            break;
        }


    }while(option != 0);


    return 0;
}
