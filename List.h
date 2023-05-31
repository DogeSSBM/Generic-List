#ifndef LIST_H
#define LIST_H

#define NEWLISTPRINT(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)          \
    void L_FUNPREFIX##Print(L_TYPE *list)                                   \
    {                                                                       \
        printf(L_PRINTSPEC, list->data);                                    \
    }                                                                       \


#define NEWLISTPRINTLN(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)        \
    void L_FUNPREFIX##Println(L_TYPE *list)                                 \
    {                                                                       \
        printf(L_PRINTSPEC"\n", list->data);                                \
    }                                                                       \

#define NEWLISTLISTPRINT(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)      \
    void L_FUNPREFIX##ListPrint(L_TYPE *list)                               \
    {                                                                       \
        while(list){                                                        \
            printf(L_PRINTSPEC, list->data);                                \
            list = list->next;                                              \
        }                                                                   \
    }                                                                       \


#define NEWLISTLISTPRINTLN(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)    \
    void L_FUNPREFIX##ListPrintln(L_TYPE *list)                             \
    {                                                                       \
        while(list){                                                        \
            printf(L_PRINTSPEC"\n", list->data);                            \
            list = list->next;                                              \
        }                                                                   \
    }                                                                       \

#define NEWLISTNEW(L_TYPE, L_DATATYPE, L_FUNPREFIX)                         \
L_TYPE* L_FUNPREFIX##New(L_DATATYPE data)                                   \
{                                                                           \
    L_TYPE *list = calloc(1, sizeof(L_TYPE));                               \
    list->data = data;                                                      \
    return list;                                                            \
}                                                                           \

#define NEWLISTAPPEND(L_TYPE, L_FUNPREFIX)                                  \
    L_TYPE* L_FUNPREFIX##Append(L_TYPE *head, L_TYPE *tail)                 \
    {                                                                       \
        if(!head)                                                           \
            return tail;                                                    \
        L_TYPE *cur = head;                                                 \
        while(cur->next){cur = cur->next;}                                  \
        cur->next = tail;                                                   \
        return head;                                                        \
    }                                                                       \

#define NEWLISTAPPENDNEW(L_TYPE, L_DATATYPE, L_FUNPREFIX)                   \
    L_TYPE* L_FUNPREFIX##AppendNew(L_TYPE *head, L_DATATYPE data)           \
    {                                                                       \
        return L_FUNPREFIX##Append(head, L_FUNPREFIX##New(data));           \
    }                                                                       \

#define NEWLISTPREPEND(L_TYPE, L_FUNPREFIX)                                 \
    L_TYPE* L_FUNPREFIX##Prepend(L_TYPE *oldhead, L_TYPE *newhead)           \
    {                                                                       \
        if(!newhead)                                                        \
            return oldhead;                                                 \
        if(!oldhead)                                                        \
            return newhead;                                                 \
        L_TYPE *cur = newhead;                                              \
        while(cur->next){cur = cur->next;}                                  \
        cur->next = oldhead;                                                \
        return newhead;                                                     \
    }                                                                       \

#define NEWLISTPREPENDNEW(L_TYPE, L_DATATYPE, L_FUNPREFIX)                  \
    L_TYPE* L_FUNPREFIX##PrependNew(L_TYPE *oldhead, L_DATATYPE data)       \
    {                                                                       \
        return L_FUNPREFIX##Prepend(oldhead, L_FUNPREFIX##New(data));       \
    }                                                                       \

#define NEWLISTLEN(L_TYPE, L_FUNPREFIX)                                     \
    st L_FUNPREFIX##Len(L_TYPE *list)                                       \
    {                                                                       \
        st len = 0;                                                         \
        while(list){                                                        \
            list = list->next;                                              \
            len++;                                                          \
        }                                                                   \
        return len;                                                         \
    }                                                                       \

#define NEWLISTTYPE(L_TYPE, L_DATATYPE, L_FUNPREFIX)                        \
    typedef struct L_TYPE{                                                  \
        L_DATATYPE data;                                                    \
        struct L_TYPE *next;                                                \
    }L_TYPE;                                                                \
    NEWLISTNEW(L_TYPE, L_DATATYPE, L_FUNPREFIX)                             \
    NEWLISTLEN(L_TYPE, L_FUNPREFIX)                                         \
    NEWLISTAPPEND(L_TYPE, L_FUNPREFIX)                                      \
    NEWLISTAPPENDNEW(L_TYPE, L_DATATYPE, L_FUNPREFIX)                       \
    NEWLISTPREPEND(L_TYPE, L_FUNPREFIX)                                     \
    NEWLISTPREPENDNEW(L_TYPE, L_DATATYPE, L_FUNPREFIX)                      \

#define NEWLISTTYPE_P(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)         \
    NEWLISTTYPE(L_TYPE, L_DATATYPE, L_FUNPREFIX)                            \
    NEWLISTPRINT(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)              \
    NEWLISTPRINTLN(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)            \
    NEWLISTLISTPRINT(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)          \
    NEWLISTLISTPRINTLN(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)        \

#endif /* end of include guard: LIST_H */
