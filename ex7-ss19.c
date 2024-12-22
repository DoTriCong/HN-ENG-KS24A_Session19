#include <stdio.h>
#include <string.h>
typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;
void deleteStudentById(int id, Student students[], int *currentLength) {
    int index = -1;
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Khong tim thay sinh vien voi ID = %d\n", id);
        return;
    }
    for (int i = index; i < *currentLength - 1; i++) {
        students[i] = students[i + 1];
    }
    (*currentLength)--;
    printf("Da xoa sinh vien co ID = %d\n", id);
}

void printStudents(Student students[], int length) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < length; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}
int main() {
    Student students[5] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Tran Thi B", 21, "0987654321"},
        {3, "Le Van C", 22, "0912345678"},
        {4, "Pham Thi D", 23, "0908765432"},
        {5, "Hoang Van E", 24, "0888888888"}
    };
    int currentLength = 5;
    printStudents(students, currentLength);
    int idToDelete;
    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &idToDelete);
    deleteStudentById(idToDelete, students, &currentLength);
    printStudents(students, currentLength);
    return 0;
}

