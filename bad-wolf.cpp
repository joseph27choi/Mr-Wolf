#include <iostream>
#include <string>

// declarations
int main(void);

// definitions
class Node {
private:
    double x, y;
    Node *next;

public:
    // constructor, can just stamp to create no need for assignments
    Node(double x_param, double y_param, Node *next = nullptr) {
        this->x = x_param;
        this->y = y_param;
        this->next = nullptr;
    }

    // encapsulation functions
    double get_x_val() { return this->x; }
    double get_y_val() { return this->y; }

    void set_x_value(double x_param) { this->x = x_param; }
    void set_y_value(double y_param) { this->y = y_param; }

    Node *get_next_ptr() { return this->next; }
    void set_next_ptr(Node *node_param) { this->next = node_param; }
};

class LinkedList {
private:
    Node *head;
    Node *tail;
    int num;

public:
    // constructor
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->num = 0;
    }

    // destructor
    ~LinkedList();

    // encapsulation
    Node* get_head() {return this->head;}
    Node* get_tail() {return this->tail;}

    // adding node to the end
    void addNode(double, double);

    // printing node
    void printNode();

    // deleting node at a given index
    void deleteNode(Node*);

    // finding the number of nodes
    int getNum(void) {return this->num;}
    void setNum(int n) {this->num = n;}

    // time command
    int time(double);

    // game won boolean
    void over(void);
};

LinkedList::~LinkedList() {
    // traverse the link to print and destroy
    Node* p_enis = nullptr;
    Node* destroyer = nullptr;

    p_enis = this->head;
    destroyer = this->head;
    while (p_enis != nullptr) {
        p_enis = p_enis->get_next_ptr(); // p_enis is not a bottom box pointer
        delete destroyer;
        destroyer = nullptr;
        destroyer = p_enis;
    }
    
};

void LinkedList::addNode(double p, double q) {

    // add to the total number of lists
    int updated_num = this->getNum() + 1;
    this->setNum(updated_num);
    
    // to add node utilize both head and tail
    Node* p_attacher = nullptr;
    p_attacher = new Node(p, q);
    if (p_attacher == nullptr) {
        std::cout << "not enough memory" << std::endl;
        exit(1);
    }

    // coordinates must be in first quadrant
    if (p > 0 && q > 0) {
        // output success
        std::cout << "success" << std::endl;

        // Case 1: no list exists
        if (this->head == NULL) {
            this->head = p_attacher;
            this->tail = p_attacher;
            p_attacher = nullptr;
        }
        // Case 2: list exists
        else {
            this->tail->set_next_ptr(p_attacher);
            this->tail = p_attacher; // the final node always points to null
            p_attacher = nullptr;
        }
    }
    // numbers are not in first quadrant
    else {
        std::cout << "failure" << std::endl;
    }

};

void LinkedList::printNode(void) {
    // traverse the list 
    Node* p_enis = nullptr;
    p_enis = this->head;
    while (p_enis != NULL) {
        std::cout << p_enis->get_x_val() << " " << p_enis->get_y_val() << " " << std::endl;
        p_enis = p_enis->get_next_ptr();
    }
};

void LinkedList::deleteNode(Node* lagger) {
    // check if link exists in the first place
    if (this->getNum() > 0 && this->head != NULL) {
        // there is a node to delete
        // going to use the copy delete method
        Node* temp = lagger->get_next_ptr();
        lagger->set_x_value(temp->get_x_val());
        lagger->set_y_value(temp->get_y_val());
        lagger->set_next_ptr(temp->get_next_ptr());
        // can now safely delete the temp pointer
        delete temp;
        temp = nullptr;

        this->setNum(this->getNum() - 1);
    }
    else {
        // no links exist
        return;
    }

};

int LinkedList::time(double t_param) {
    // nothing happens if t_param is 0
    if (t_param == 0) {
        return this->getNum();
    }
    
    Node* rabbit = nullptr;
    Node* turtle = nullptr;
    turtle = this->head;
    rabbit = this->head;

    // return early if no link exists
    if (rabbit == nullptr) {
        return this->getNum();
    }
    // if valid, make the rabbit point ahead after adjustments
    else {
        rabbit = rabbit->get_next_ptr();
    }

    while (rabbit != NULL) {
        if (t_param > 0) {
            // update position only when t_param is positive
            double updated_x = turtle->get_x_val() + (t_param) * cos(atan2(turtle->get_y_val(), turtle->get_x_val()));
            turtle->set_x_value(updated_x);
            double updated_y = turtle->get_y_val() + (t_param) * sin(atan2(turtle->get_y_val(), turtle->get_x_val()));
            turtle->set_y_value(updated_y);
        } 
        else if (t_param < 0) {
            // check if they are within 1 unit of the wolf (origin) 
            if (turtle->get_x_val() / (cos(atan2(turtle->get_y_val(),turtle->get_x_val())))) {
                std::cout << "lol you got eaten at" << turtle->get_x_val() << ", " << turtle->get_y_val()<< std::endl;
                /*
                 delete the node lol
                */
                this->deleteNode(turtle);
            }
            else {
                std::cout << "you are safe" << std::endl;
            }
        }

        // preparing for final node situation, rabbit on the final node
        if (rabbit->get_next_ptr() == nullptr) {
            // update the rabbit's place
            if (t_param > 0) {
                // update position only when t_param is positive
                double updated_x = rabbit->get_x_val() + (t_param) * cos(atan2(rabbit->get_y_val(), rabbit->get_x_val()));
                rabbit->set_x_value(updated_x);
                double updated_y = rabbit->get_y_val() + (t_param) * sin(atan2(rabbit->get_y_val(), rabbit->get_x_val()));
                rabbit->set_y_value(updated_y);
            } 
            else if (t_param < 0) {
                // check if they are within 1 unit of the wolf (origin) 
                if (rabbit->get_x_val() / (cos(atan2(rabbit->get_y_val(),rabbit->get_x_val())))) {
                    std::cout << "lol you got eaten at" << rabbit->get_x_val() << ", " << rabbit->get_y_val()<< std::endl;
                    /*
                        going to be deleting the last node
                    */  
                    this->deleteNode(turtle);
                }
                else {
                    std::cout << "you are safe" << std::endl;
                }
            }
        }
        
        // update rabbit and turtle position
        std::cout << "turtle: " << turtle->get_x_val() << ", " << turtle->get_y_val() << std::endl;
        std::cout << "rabbit: " << rabbit->get_y_val() << ", " << rabbit->get_y_val() << std::endl;
        
        // update to the next pointer
        turtle = turtle->get_next_ptr();
        rabbit = rabbit->get_next_ptr();
    }


    return this->getNum();
};

void LinkedList::over() {
    if (this->getNum() >= 1) {
        std::cout << "the players win " << std::endl;
    }
    else {
        std::cout << "the wolf wins " << this->getNum() << std::endl;
    }
};

int main(void) {

    // initilize a new linked list
    LinkedList chain;

    chain.addNode(1,1);
    chain.addNode(2,2);
    chain.addNode(0.22,0.43);

    chain.printNode();

    std::cout << std::endl;

    chain.time(3);

    std::cout << std::endl;

    chain.printNode();

    chain.over();

    return 0;
}
