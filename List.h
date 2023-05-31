#ifndef LIST_H
#define LIST_H

#define NEWLISTNEW(L_TYPE, L_DATATYPE, L_FUNPREFIX)             \
L_TYPE* L_FUNPREFIX##New(L_DATATYPE data)                       \
{                                                               \
    L_TYPE *list = calloc(1, sizeof(L_TYPE));                   \
    list->data = data;                                          \
    return list;                                                \
}                                                               \

#define NEWLISTAPPEND(L_TYPE, L_FUNPREFIX)                      \
    L_TYPE* L_FUNPREFIX##Append(L_TYPE *head, L_TYPE *tail)     \
    {                                                           \
        if(!head)                                               \
            return tail;                                        \
        L_TYPE *cur = head;                                     \
        while(cur->next){cur = cur->next;}                      \
        cur->next = tail;                                       \
        return head;                                            \
    }                                                           \

#define NEWLISTLEN(L_TYPE, L_FUNPREFIX)                         \
    st L_FUNPREFIX##Len(L_TYPE *list)                           \
    {                                                           \
        st len = 0;                                             \
        while(list){                                            \
            list = list->next;                                  \
            len++;                                              \
        }                                                       \
        return len;                                             \
    }                                                           \

#define NEWLISTTYPE(L_TYPE, L_DATATYPE, L_FUNPREFIX)            \
    typedef struct L_TYPE{                                      \
        L_DATATYPE data;                                        \
        struct L_TYPE *next;                                    \
    }L_TYPE;                                                    \
    NEWLISTNEW(L_TYPE, L_DATATYPE, L_FUNPREFIX)                 \
    NEWLISTAPPEND(L_TYPE, L_FUNPREFIX)                          \
    NEWLISTLEN(L_TYPE, L_FUNPREFIX)                             \

#endif /* end of include guard: LIST_H */
