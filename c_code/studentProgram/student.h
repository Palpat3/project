#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define NAME_LENGTH 32

typedef struct {
    char name[NAME_LENGTH];
    int id;
    float grade;
} Student;

Student* create_student(const char* name, int id, float grade);
void delete_student(Student* s);
void print_student(Student* s);

#endif // STUDENT_H