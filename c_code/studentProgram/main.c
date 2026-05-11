#include <stdio.h>
#include <limits.h>
#include "student.h"

int main() {
    printf("=== Student Program ===\n\n");
    printf("Creating students...\n");
    Student* s1 = create_student("Alice", 1, 4.0);
    Student* s2 = create_student("Bob", 2, 4.5);
    print_student(s1);
    print_student(s2);

    printf("Adding student with long name...\n");
    Student* s3 = create_student("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 3, 5.0); //36 characters, exceeds NAME_LENGTH
    print_student(s3);  // This will cause a buffer overflow

    printf("Student id wraparound test...\n");
    int id = INT_MAX;  
    Student* s4 = create_student("Charlie", id, 3.5);
    print_student(s4); 
    Student* s5 = create_student("Dave", id + 1, 3.0);  // This will cause integer overflow
    print_student(s5);

    printf("Deleting student s1...\n");
    delete_student(s1);
    print_student(s1);  // This will cause undefined behavior

    printf("deleting student s1 again (defesive cleanup)...\n");
    delete_student(s1);  // This will cause double free
    printf("If this is printed, it indicates a double free error went undetected.\n");

    

    return 0;
}