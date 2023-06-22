#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};
void parseString(const char* inputString, struct Student students[], int size) {
    char temp[20];
    int rollno;
    float marks;
    for (int i = 0; i < size; ++i) {
        if (sscanf(inputString, "%d %s %f", &rollno, temp, &marks) == 3) {
            students[i].rollno = rollno;
            strncpy(students[i].name, temp, sizeof(students[i].name));
            students[i].marks = marks;
            inputString = strchr(inputString, '\0');
            if (inputString != NULL)
                ++inputString;
        } else {
            fprintf(stderr, "Error parsing input string. Insufficient data.\n");
            return;
        }
    }
}

int main() {
    const int size = 1; 
    struct Student students[size];

    const char* inputString = "1001 Aron 100.00";
    parseString(inputString, students, size);
    for (int i = 0; i < size; ++i) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    return 0;
}