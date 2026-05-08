#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char name[10];
    int score;
    struct Student* next;
};


int main() {
    struct Student* head = NULL;

    while (1) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "add") == 0) {
            char input_name[10];
            int input_score;
            scanf("%s %d", input_name, &input_score);

            //malloc을 사용해 새로 추가되는 struct를 위한 공간 할당
            struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
            strcpy(newNode->name, input_name);
            newNode->score = input_score;
            newNode->next = NULL;
            
            if (head == NULL) {
                head = newNode;
            }
            else {
                struct Student* ptr = head;
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = newNode;
            }

        }
        else if (strcmp(op, "delete")==0) {
            char name[10];
            scanf("%s", name);

            // 걸어나가면서 이름 확인
            struct Student* curr = head;
            struct Student* prev = NULL;

            while (strcmp(curr->name , name) != 0) {
                prev = curr;
                curr = curr->next;
            }

            if (prev == NULL) {
                head = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            free(curr);
            // 제거한 학생의 메모리 free
        }
        else if (strcmp(op, "print") == 0) {
            struct Student* ptr = head;
            while (ptr->name != NULL) {
                printf("%s %d\n", ptr->name, ptr->score);
                ptr = ptr->next;
            }
            // next로 걸어나가며 출력
            
        }
        else if (strcmp(op, "quit") == 0) {
            struct Student* temp;
            while (head != NULL) {
                temp = head;
                head = head->next;
                free(temp);
            }
            //전체 free
            break; //while문 탈출
        }
    }

    return 0;
}
