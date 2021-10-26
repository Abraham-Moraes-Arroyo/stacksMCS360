#include <iostream>
using namespace std;
/* here we focus on getting the size of the stack
the amount of numbers that are in the stack
    
*/
struct StackNode {
    int n; // an integer, where we store the data
    StackNode *previous; // pointer to the previous node

};

class Stack{
    private:
    StackNode *top; //private member variable is just 
    // a poitner to the first node

    public:
    Stack(){ // the constructor
        top =NULL; // set the top pointer to NULL value
    }
    // this function prepends a new value at the beginning of 
    // the list
    void push(int value){
        StackNode *new_node= new StackNode(); // create a new Node
        new_node -> n= value; // setting its vale
        new_node-> previous= top; // make the new node pointer point to the previous node
        top= new_node;
    }
    // showing the stack's values and the memory of those values
    void show(){
        StackNode *new_node= new StackNode();
        new_node =top;
        while (new_node != NULL){
            // showing the current nodes' data (the address)
            // and the address of the previous node
            // NOTE: every node carries the address of the previous node
            cout << "->"<< "[ " << new_node->n<< " | "<< new_node<<  " | "<< new_node-> previous << " ]";
            new_node = new_node-> previous;
        }
        cout << endl;
    }
/*
    -------------------------------------------------
        Here we are going to get the top value of the stack
    -------------------------------------------------
*/
    int top_element(){
        int r; //value to be returned
        StackNode *new_node=top;
        // retruns some special integer (like -1) to avoid 
        // segmentation fault, if the stack is empty
        if (top==NULL)
            return -1;
        r= new_node-> n;
        return r;
    }
/*
    -------------------------------------------------
        Here we are going to get the size of stack
    -------------------------------------------------
*/
    int size(){
        StackNode *curr= new StackNode();
        // we start at the top and loop until we reach
        // the bottom ndoe, incrementing the counter as we go
        curr= top;
        if (top==NULL)
            return 0; // return value 0 if the stack is empty 
                      // to avoid segmentation fault
        int cnt = 1; // linked 
        while(curr-> previous !=NULL){
            curr= curr-> previous;
            cnt ++;
        }
        return cnt;
    }

};

int main(){
    Stack S; // creating the empty stack
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.show();
    cout << "The top element of the stack"<< endl;
    cout << S.top_element() << endl;
    cout <<"The size of the stack"<< endl;
    cout << S.size()<< endl;

    return 0; 

}
