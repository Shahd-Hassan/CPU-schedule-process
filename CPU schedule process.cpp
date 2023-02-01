#include <iostream>
#include <string.h>
using namespace std;
class CPUProcess {
private://private members of class CPUPROCESS.
    int process_id;
    string process_name;
    double time_needed;

public:
    CPUProcess() {//empty constructor
        process_id = 0;
        process_name = "  ";
        time_needed = 0;
    }
    CPUProcess(int pid, string pn, double tn) {//parameterized constructor that sets the values to the its attributes.
        process_id = pid;
        process_name = pn;
        time_needed = tn;

    }
    //setter and getter functions to access the private members
    void setprocess_id(int pid) {//set the process id 
        process_id = pid;
    }

    int getprocess_id() {//get the process id
        return process_id;
    }

    void setprocess_name(string pn) {//set process name
        process_name = pn;
    }

    string getprocess_name() {//get process name
        return process_name;
    }

    void settime_needed(double tn) {//set process time
        time_needed = tn;
    }

    double gettime_needed() {//get process time
        return time_needed;
    }


    void printProcessInfo() {//Method to print the process information
        cout << "The Process ID Is: " << getprocess_id() << endl;
        cout << "The Process Name Is: " << getprocess_name() << endl;
        cout << "The Time Needed to Complete The Process: " << gettime_needed() << endl;
        cout << endl;

    }//function print proces info 
};//End of class CPUPROCESS//


template <class T>
class ProcessNode {
public:
    T data;//data where the object will be stored in.
    ProcessNode<T>* next;//pointer to access nodes.

    ProcessNode(T pid) {//constructor that takes the data and sets the data variable, and set the next to NULL
        data = pid;
        next = NULL;

    }

};//end of class PROCESSNODES

template <class T>
class StackLL {
    ProcessNode<T>* top;
public:
    StackLL() {
        top = NULL;
    }
    bool pushProcess(T process) {//To add objects removed from the queue into the stack[LIFO].
        ProcessNode<T>* newNode = new ProcessNode<T>(process);
        if (top == NULL) {//The Stack is empty
            cout << "Node pushed Successfully!" << endl;
            cout << endl;
            top = newNode;

            return true;
        }

    }//function pushprocess
//////////////////////////////////////////////////////////////////////////   	

    CPUProcess lateProcess() {//To get the latest process which is at the top of the stack.
        ProcessNode<T>* pointer = top;
        T Process;
        if (top == NULL) {
            cout << "The Stack is Empty! " << endl;
            return Process;
        }
        int counter = 0;

        while (pointer != NULL) {
            pointer = pointer->next;
            counter++;

        }
        Process = top->data;
        cout << "The Number Of Processes Is: " << counter << endl;
        cout << endl;
        cout << "The Top Process Is -------> " << endl;
        cout << endl;
        return Process;

    }//function lateprocess
////////////////////////////////////////////////////////////////////////////////////////////// 	

//    	bool emptystack(){//To check if stack is empty.
//    	if(top==NULL){//Stack is empty
//    	cout<<"The Stack Is Empty!"<<endl;
//		return true;	
//		}	
//		}//function emptystack



    void stackOfProcesses() {//To Print the stack contents.
        ProcessNode<T>* temp = top;
        while (temp != NULL) {
            cout << "The Elements of the stack is : " << endl;
            cout << endl;
            temp->data.printProcessInfo();
            temp = temp->next;
        }
        cout << endl;
    }//function stack process
//////////////////////////////////////////////////////////////////////////////////////

};//End of stack class



template <class T>
class QueueLL {
    ProcessNode<T>* head;
    ProcessNode<T>* front;
    ProcessNode<T>* rear;
    ProcessNode<T>* temp;
    double capacity = 3;//default value
public:
    QueueLL() {//constructor to set them all to NULL

        head = front = NULL;
        rear = NULL;
    }
    //Time complexity of the execute function:
    //T(n)=9+8n+2n+3
    //T(n)=10n+9+3
    //T(n)=10n+12
    //
    //O(n)//
    //

    bool execute(T pid) {//To add objects to the linked list of the queue[FIFO].
        ProcessNode<T>* newNode = new ProcessNode<T>(pid);//1
        ProcessNode<T>* temp1 = front;//1
        ProcessNode<T>* temp = front;//1
        if (front == NULL) {//chech if queue is empty//1
            cout << "Empty Queue!...Elements are being added!" << endl;//1                       //9
            cout << endl;//1
            front = rear = newNode;//if empty then front and rear are pointing to one newnode //2
            front->next = NULL;//Queue contains only one node	//1

            return false;//1
        }


        while (temp != NULL) {//Queue is not empty //more than one node//8n
            if (temp->data.getprocess_id() == newNode->data.getprocess_id()) {
                cout << "This Process Already Exists! Cannot Add." << endl;
                cout << endl;
                cout << "The Elements of the queue is : " << endl;//7n                          8n
                cout << endl;
                return false;
            }
            temp = temp->next;
        }

        while (temp1->next != NULL) {//Queue contains more than one node//2n
            temp1 = temp1->next;//Adding from rear

        }                                                                           // 2n
        temp1->next = newNode;//1
        return true;//1
        //2


    }//function execute
    ///////////////////////////////////////////////////////////////////////////////////////////



    CPUProcess runProcess() {

        ProcessNode<T>* del = front;
        ProcessNode<T>* del2 = front;
        T value;
        if (front == NULL) {//chech if queue is empty
            cout << "Empty Queue!" << endl;
            return value;
        }
        //more than one node
        else {
            //check if the time needed is less than or equal the capacity(3)
            if (del->data.gettime_needed() <= capacity) {
                value = del->data;
                front = front->next;

                del2->data = del->data;
                delete del;
                cout << "Process Execution is Completed!" << endl;
                return value;
            }
            else {
                cout << "Process Execution STOPPED SUDDENLY!" << endl;
                return value;

            }
        }
    }//function runprocess

///////////////////////////////////////////////////////////////////////////////////////////////////



    void cpuSchedule() {//To print all processes in the queue
        ProcessNode<T>* temp = front;

        while (temp != NULL) {
            temp->data.printProcessInfo();
            temp = temp->next;
        }
    }//function cpuschedule

//////////////////////////////////////////////////////////////////////////////////////////	

//    	bool emptyqueue(){//To check if queue is empty.
//    	if(rear==NULL){
//    		cout<<"The Queue Is Empty!"<<endl;
//    		return true;
//		}	
//		}//function empty queue



    bool killProcess(StackLL<CPUProcess>* sll) {//Remove objects from the queue
        // You need to create an object of type StackLL so that you can
        // call the pushProcess(T process) method here.

        ProcessNode<T>* del = front;
        //ProcessNode<T>* ptr=NULL;

        if (front == NULL) {//chech if queue is empty
            cout << "Empty Queue!" << endl;
        }
        else {
            T value = del->data;
            //points to the first node	
             //check if the front of the queue is the process that is targeted
            if (front->data.gettime_needed() > capacity) {//check if the time needed is greater than the capacity(3)
                // ptr=del;
                front = front->next;
                delete del;
                cout << "///////////////////////////////////////////////////////////////////" << endl;
                cout << endl;
                cout << "Process is Killed!" << endl;
                sll->pushProcess(value);
            }
            else {
                return false;
            }



        }

    }//function killprocess
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    


};//End of queue class

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// 
//
//
class BTNode {
public: 
int value;
BTNode * left;
BTNode * right;
BTNode(int data){
	value=data;
	left=NULL;
	right=NULL;
}
};

class binaryt{
	public:
		
	BTNode*  root;
	binaryt	(){
		root=NULL;
	}


BTNode* insert(int el){//to insert in binary tree
	BTNode* p=root,*prev=0;
	while(p!=NULL){//place for inserting new node
		prev=p;
		if(el< p->value)
		p=p->left;
		else p=p->right;
	}
	if(root==NULL)
	root=new BTNode(el);
	else if(el<prev->value)
	prev->left = new BTNode(el);
	else prev->right = new BTNode(el);
	return prev;
}


void inordertraversal(BTNode* prev){
	if(prev==NULL) return;
	inordertraversal(prev->left);
	cout<<prev->value<<endl;
	inordertraversal(prev->right);
}
};

int main() {

    CPUProcess p1(1, "p1", 10);
    CPUProcess p2(2, "p2", 4);
    CPUProcess p3(3, "p3", 1);
    CPUProcess p4(4, "p4", 5);
    CPUProcess p5(5, "p5", 15);
    QueueLL<CPUProcess> qll;
    qll.execute(p1);
    qll.execute(p2);
    qll.execute(p3);
    qll.execute(p4);
    qll.execute(p5);

    qll.cpuSchedule();

    qll.runProcess().printProcessInfo();
    StackLL<CPUProcess> sll;
    qll.killProcess(&sll);


    sll.stackOfProcesses();
    cout << "/////////////////////////////////////////////////////////////" << endl;
    sll.lateProcess().printProcessInfo();

    //The Binary tee part//
    //
       binaryt b1;
       b1.insert(45);
       b1.insert(15);
       b1.insert(79);
       b1.insert(90);
       b1.insert(10);
       b1.insert(55);
       b1.insert(12);
       b1.insert(20);
       b1.insert(50);
       
       cout<<"The Content Of The Tree Is: "<<endl;
       cout<<endl;
       b1.inordertraversal(b1.root);


    return 0;
}

