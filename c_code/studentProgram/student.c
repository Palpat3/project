#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

Student* create_student(const char* name, int id, float grade) {
    Student* s = malloc(sizeof(Student));
    strcpy(s->name, name);  // naive copy, no bounds checking
    s->id = id;
    s->grade = grade;
    return s;
}

void delete_student(Student* s) {
    free(s);  //no nulling pointer after free
}

void print_student(Student* s) {
    printf("Student: %s | ID: %d | Grade: %.1f\n", s->name, s->id, s->grade);
}

