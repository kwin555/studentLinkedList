//
//  main.cpp
//  ClassroomExampleAug28
//
//  Created by Kevin Nguyen on 8/28/18.
//  Copyright © 2018 Kevin Nguyen. All rights reserved.
//

#include <iostream>

using namespace std;

struct student {
    int id;
    float gpa;
    student *next;
    
};

float randomFloat(double min, double max);
int main(int argc, const char * argv[]) {
    // insert code here...
    // new int is flexiable allows you create new datastructure
    
    // a {0} - > b{0}
    // have to use pointer to connect nodes
    //new allocates memory and assigns an address
    
//    student mac;
//    mac.id = 123;
//    mac.gpa = 4.0;
//    mac.next = 0;
//    mac.next = new student;// creates an emepty allocation with a memory addresss
//
//    student *currentStudent; // creating a new student to hold the memory address
//    currentStudent = mac.next; // assigning the memory address to current student
//
//    // assing fields to the current student
//    currentStudent->id =333;
//    currentStudent->gpa = 2.7;
//    currentStudent->next = nullptr;
//
//    currentStudent->next = new student;
//    currentStudent = currentStudent->next;// setting up the link to the next student
//    //generating the next student in the link
//
//    currentStudent->id = 444;
//    currentStudent->gpa  =1.9;
//    currentStudent->next = 0;
//    std::cout << "Hello, World!\n";
    
    student *mac = new student;
    student *head = mac;
    mac->id = 0;
    for (int i = 0; i < 100; i++) {
        mac->id = i * 5 + 45;
        mac->gpa = 4.0;
        mac->next = new student;
        mac = mac->next;
    }
    mac->next = 0;
    mac = head;// sets structure back to the beginning node
    
    for (int i =0; i < 100; i++) {
        cout << mac->id << endl;
        mac++;
    }
    return 0;
}


