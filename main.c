#include "Includes.h"

NEWLISTTYPE(Listi, int, listi)
NEWLISTTYPE_P(Listi, int, listi, "%i")
NEWLISTTYPE(Liststr, char*, liststr)
NEWLISTTYPE_P(Liststr, char*, liststr, "%s")

int main(void)
{
    printf("int list:\n");
    Listi *listi = listiNew(3);
    listi = listiPrependNew(listi, 1);
    listi = listiPrependNew(listi, 0);
    listiInsertAfter(listiFindData(listi, 1), listiNew(2));
    listiListPrintln(listi);
    printf("len: %zu\n", listiLen(listi));
    listiFreeList(listi);

    printf("str list:\n");
    Liststr *lists = liststrNew("abc");
    lists = liststrAppendNew(lists, "def");
    lists = liststrAppendNew(lists, "ghi");
    liststrListPrintln(lists);
    printf("len: %zu\n", liststrLen(lists));
    liststrFreeList(lists);

    return 0;
}
