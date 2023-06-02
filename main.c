#include "Includes.h"

NEWLISTTYPE(Listi, int, listi)
NEWLISTTYPE_P(Listi, int, listi, "%i")
NEWLISTTYPE(Liststr, char*, liststr)
NEWLISTTYPE_P(Liststr, char*, liststr, "%s")
NEWLISTTYPE(Listdeep, char*, listdeep)
NEWLISTTYPE_P(Listdeep, char*, listdeep, "%s")
NEWLISTTYPE_F(Listdeep, char*, listdeep)

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

    char *strs[4] = {0};
    for(uint i = 0; i < 4; i++){
        strs[i] = calloc(8, sizeof(char));
        memcpy(strs[i], "deep: ", 6);
        strs[i][6] = '0' + i;
    }

    printf("deep list:\n");
    Listdeep *listdeep = listdeepNew(strs[3]);
    listdeep = listdeepPrependNew(listdeep, strs[1]);
    listdeep = listdeepPrependNew(listdeep, strs[0]);
    listdeepInsertAfter(listdeepFindData(listdeep, strs[1]), listdeepNew(strs[2]));
    listdeepListPrintln(listdeep);
    printf("len: %zu\n", listdeepLen(listdeep));
    listdeepFreeDeepList(listdeep);

    return 0;
}
