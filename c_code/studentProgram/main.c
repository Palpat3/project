#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "student.h"

// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA 34 characters
// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA 64 characters
int main() {
    printf("=== Student Program ===\n\n");
    printf("Creating students...\n");
    Student* s1 = create_student("Alice", 1, 4.0);
    Student* s2 = create_student("Bob", 2, 4.5);
    print_student(s1);
    print_student(s2);

    printf("Adding student with long name...\n");
    Student* s3 = create_student("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 3, 5.0); // 34 characters, exceeds NAME_LENGTH
    //Too long name will cause integer overflow to crash, overflow corruption happens in heap metadata invisibly
    //Id should be corrupted af 32 character but it is possible that windows heap allocator places heap metadata in between name and id
    //small overflow just overwrites id and grade but bigger overflow corrupts outside struct which can fuck up heap metadata and crash next coming instructions.
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