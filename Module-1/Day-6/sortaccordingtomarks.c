#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void sortStudents(struct Student students[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (students[j].marks < students[j + 1].marks) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayStudents(const struct Student students[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
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

    printf("Before sorting:\n\n");
    displayStudents(students, size);

    sortStudents(students, size);

    printf("After sorting:\n\n");
    displayStudents(students, size);

    return 0;
}