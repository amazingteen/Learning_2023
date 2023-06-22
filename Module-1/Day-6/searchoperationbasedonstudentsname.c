#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchStudentsByName(const struct Student students[], int size, const char* name) {
    int found = 0;
    for (int i = 0; i < size; ++i) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Student with name '%s' not found.\n", name);
    }
}

int main() {
    const int size = 5; 
    struct Student students[size] = {
        {1001, "Alex", 95.0},
        {1002, "Bob", 86.5},
        {1003, "Charles", 97.3},
        {1004, "David", 89.7},
        {1005, "Elsie", 93.2}
    };

    const char* searchName = "Elsie";
    searchStudentsByName(students, size, searchName);

    return 0;
}