#include <iostream>
#include <cstdlib>

using namespace std;

// linked list example
struct student {
    int id;
    float gpa;
    student *next;
};

class myList {
    private:
        student *head;
        student *tail;
    public:
        myList();
        bool isEmpty();
        void addatBeginning(int idNumber, float gpaNumber);
        void addAtEnd(int idNumber, float gpaNumber);
        void addAtMiddlePosition(int number, int idNumber, float gpaNumber);
        void deleteAtBeginning();
        void deleteAtEnd();
        void deleteAtMiddlePosition(int number);
        void removeAll();
        void print();
        void lastElement();
        int getSize();
};

int main () {
    myList coscClass;
    coscClass.addAtEnd(11,3.0);
    coscClass.addAtEnd(12,3.5);
    coscClass.addAtEnd(07,4.1);
    coscClass.addAtEnd(45, 3.5);
    coscClass.addAtEnd(3, 4.1);
    coscClass.deleteAtMiddlePosition(4);
    coscClass.print();
    return 0;
}

myList::myList() {
    head = NULL;
}

int myList::getSize() {
    student *current = new student;
    current = head;
    int size  = 0;
    while(current->next != nullptr) {
        current = current->next;
        size++;
    }
    return size;
}

bool myList::isEmpty() {
    return (head == NULL) ? true : false; 
}

void myList::addatBeginning(int idNumber, float gpaNumber) {
    student *temp = new student;
    temp->id = idNumber;
    temp->gpa = gpaNumber;
    temp->next = head;
    if (isEmpty()) {
        temp->next = nullptr;
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
    
}

void myList::addAtEnd(int idNumber, float gpaNumber) {
    student *newStudent = new student;
    student *lastStudent = head;
    newStudent->id = idNumber;
    newStudent->gpa = gpaNumber;
    if(isEmpty()) {
        addatBeginning(idNumber, gpaNumber);
    } else {
        newStudent->next = nullptr;
        while(lastStudent->next != nullptr) {
            lastStudent = lastStudent->next;
        }
        lastStudent->next = newStudent;
        newStudent->next = nullptr;
    }
}

void myList::addAtMiddlePosition(int position, int idNumber, float gpaNumber) {
    student *newStudent = new student;
    student *current = head;
    student *previous = new student;
    newStudent->id = idNumber;
    newStudent->gpa = gpaNumber;
    if (position == 0) {
        addatBeginning(idNumber, gpaNumber);
        return;
    }

    if(position == getSize() + 1) {
        addAtEnd(idNumber, gpaNumber);
        return;
    }
    if (position < 0 || position > getSize()) {
        std::cout << "Invalid posiiton" << std::endl;
    } else {
        while (position >= 0) {
            if(position == 0) {
                previous->next = newStudent;
                newStudent->next = current;
            } else {
                previous = current;
                current = current->next;
            }
            position--;
        }
    }
}

void myList::deleteAtBeginning() {
    student *deleted;
    deleted = head;
    if (head->next == nullptr) {
        head = nullptr;
        delete deleted;
        return;
    }
    if (!isEmpty()) {
        head = head->next;
        delete deleted;
    } else {
        cout << "List is empty! Please add elements to the linked List" << endl;
    }
   
}

void myList::deleteAtEnd() {
    student *current = new student;
    student *previous = new student;
    current = head;

    while(current->next != NULL) {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    delete current;
}

void myList::deleteAtMiddlePosition(int position) {
    student *previous = new student;
    student *current = head;
    if (position == 0) {
        deleteAtBeginning();
    } else if (position == getSize()) {
        deleteAtEnd();
    } else {
        if (position < 0 || position > getSize()) {
            std::cout << "Invalid Position" << endl;
        } else {
            while (position >= 0) {
                if (position == 0) {
                    previous->next = current->next;
                    delete current;
                } else {
                    previous = current;
                    current = current->next;
                }
                position--;
            }
        }
    }
}


void myList::print() {
    student *temp;
    temp = new student();
    temp = head;
    while(temp != NULL) {
        cout << "student id " << temp->id << " student gpa " << temp->gpa << endl;
        temp = temp->next;
    }
}

void myList::lastElement() {
    student *current;
    current = head;
    while (current != NULL) {
        current = current->next;
    }
    tail = current;
}