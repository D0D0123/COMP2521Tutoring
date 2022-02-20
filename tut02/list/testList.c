#include "List.h"

int main() {
    List l = newList();
    for (int i = 0; i < 5; i++) {
        listInsert(l, i);
    }
    printList(l);

    printf("sum of list l: %d\n", listSum(l));

    printf("number of odds in list l: %d\n", listCountOdds(l));

    printf("is list l sorted?: %d\n", listIsSorted(l));
   
    listDelete(l, 0);
    printList(l);
    listDelete(l, 3);
    printList(l);

    freeList(l);
}