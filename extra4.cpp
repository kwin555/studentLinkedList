#include <iostream>
#include <cstdlib>

using namespace std;

struct student {
    int id;
    float gpa;
    student *next;
};

float randomFloat(float min, float max);
int randomInt(int min, int max);

int main() {
    //creating scholar pointer that points to a empty memory allocation of type student
    student *scholar = new student;
    // *head stores the beginning of the first student in line
    student *head = scholar;
    //creating 100 students
    for(int i = 0; i < 100; i++) {
        //generating a random student id for a student
        scholar->id = randomFloat(100000,999999);
        //generating a random gpa for a student 
        scholar->gpa = randomFloat(1, 4);
        //storing the memory address of a blank student in *next student pointer
        scholar->next = new student;
        //directing the arrow to point to the new, blank student object
        scholar = scholar->next;
    }
    //loop through 100 times
    // setting the last student in line to nullptr 
    scholar->next = nullptr;
    //setting the memory location back to the beginning student
    scholar = head;
    for (int i = 0; i < 100; i++) {
        cout << "The scholar has an id of " << scholar->id 
        << ".\n And a GPA of " << scholar->gpa <<"." <<endl;
        scholar = scholar->next; //go the next scholar in line!!!!!!!
    }
    //currently at the last scholar 
    return 0;
}

//functions to generate random floats and ints 
float randomFloat(float min, float max) {
    float number = (static_cast<float> (rand()) / RAND_MAX);
    return min + number * (max - min);
}

int randomInt(int min, int max) {
    int number = (rand() / RAND_MAX);
    return min + number * (max - min);
}
