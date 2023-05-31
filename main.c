#include "Includes.h"

NEWLISTTYPE(Listi, int, listi)
NEWLISTTYPE(Liststr, char*, liststr)

int main(void)
{
    printf("int list:\n");
    Listi *listi = listiNew(123);
    listi = listiAppend(listi, listiNew(456));
    listi = listiAppend(listi, listiNew(789));
    int i = 0;
    Listi *curi = listi;
    while(curi){
        printf("%i: %i\n", i, curi->data);
        curi = curi->next;
        i++;
    }
    printf("len: %zu\n", listiLen(listi));

    printf("str list:\n");
    Liststr *lists = liststrNew("abc");
    lists = liststrAppend(lists, liststrNew("def"));
    lists = liststrAppend(lists, liststrNew("ghi"));
    int j = 0;
    Liststr *curs = lists;
    while(curs){
        printf("%i: %s\n", j, curs->data);
        curs = curs->next;
        j++;
    }
    printf("len: %zu\n", liststrLen(lists));

    return 0;
}
