#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct quque{
    struct quque *next;
    int data;
} quque;

int main(int argc, char *argv[]) 
{
    char str[7];
    
    quque *head = NULL;
    quque *tail = NULL;
    
    while(fgets(str, sizeof(str), stdin)){
        quque *p;
        int v;
        int n = atoi(str);
        switch(n){
        default:
            // キューに追加
            p = (quque *)malloc(sizeof(quque));
            p->next = NULL;
            p->data = n;
            if(head == NULL) head = p;
            if(tail){
                tail->next = p;
            }
            tail = p;
            break;
        case -1:
            // キューから取り出す
            if(head == tail) tail = NULL;// 要素が1つならtailはなくなる
            if(head != NULL) {
                printf("%d", head->data);
                p = head->next;
                free(head);
                head = p;
            }
            printf("\n");
            break;
        case 0:
            // キューを表示
            for(p = head;  p; p = p->next){
                if(p != head) printf(",");
                printf("%d", p->data);
            }
            printf("\n");
            break;
        }
    }

    return 0;
}
