#include "Includes.h"

NEWLISTTYPE_P(Listi, int, listi, "%i")
NEWLISTTYPE_P(Liststr, char*, liststr, "%s")

int main(void)
{
    printf("int list:\n");
    Listi *listi = listiNew(123);
    listi = listiAppend(listi, listiNew(456));
    listi = listiAppend(listi, listiNew(789));
    listiListPrintln(listi);
    printf("len: %zu\n", listiLen(listi));

    printf("str list:\n");
    Liststr *lists = liststrNew("abc");
    lists = liststrAppend(lists, liststrNew("def"));
    lists = liststrAppend(lists, liststrNew("ghi"));
    liststrListPrintln(lists);
    printf("len: %zu\n", liststrLen(lists));

    return 0;
}
