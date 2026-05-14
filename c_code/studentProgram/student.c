#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

Student* create_student(const char* name, int id, float grade) {
    Student* s = malloc(sizeof(Student));
    
    s->id = id;
    s->grade = grade;

    strcpy(s->name, name);  // naive copy, no bounds checking
    // strcpy should be after setting id and grade to show vulnerability, if set before then id and grade overwrites overflown name and "fixes it"

    return s;
}

void delete_student(Student* s) {
    free(s);  //no nulling pointer after free
}

void print_student(Student* s) {
    printf("Student: %s | ID: %d | Grade: %.1f\n", s->name, s->id, s->grade);
    printf("  name address:  %p\n", (void*)s->name);
    printf("  id address:    %p\n", (void*)&s->id);
    printf("  grade address: %p\n", (void*)&s->grade);
}

