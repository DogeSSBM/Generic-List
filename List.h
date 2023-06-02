#ifndef LIST_H
#define LIST_H

#define NEWLISTPRINT(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)                              \
    void L_FUNPREFIX##Print(L_TYPE *list)                                                       \
    {                                                                                           \
        if(list){printf(L_PRINTSPEC, list->data);}                                              \
    }

#define NEWLISTPRINTLN(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)                            \
    void L_FUNPREFIX##Println(L_TYPE *list)                                                     \
    {                                                                                           \
        if(list){printf(L_PRINTSPEC"\n", list->data);}                                          \
    }

#define NEWLISTLISTPRINT(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)                          \
    void L_FUNPREFIX##ListPrint(L_TYPE *list)                                                   \
    {                                                                                           \
        while(list){                                                                            \
            L_FUNPREFIX##Print(list);                                                           \
            list = list->next;                                                                  \
        }                                                                                       \
    }

#define NEWLISTLISTPRINTLN(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)                        \
    void L_FUNPREFIX##ListPrintln(L_TYPE *list)                                                 \
    {                                                                                           \
        while(list){                                                                            \
            L_FUNPREFIX##Println(list);                                                         \
            list = list->next;                                                                  \
        }                                                                                       \
    }

#define NEWLISTFREE(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                            \
    void L_FUNPREFIX##FreeList(L_TYPE *head)                                                    \
    {                                                                                           \
        if(head){                                                                               \
            L_TYPE *next = head->next;                                                          \
            free(head);                                                                         \
            head = next;                                                                        \
        }                                                                                       \
        return head;                                                                            \
    }

#define NEWLISTFREELIST(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                        \
    void L_FUNPREFIX##FreeList(L_TYPE *head)                                                    \
    {                                                                                           \
        while(head = L_FUNPREFIX##Free(head));                                                  \
    }

#define NEWLISTNEW(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                             \
    L_TYPE* L_FUNPREFIX##New(L_DATATYPE data)                                                   \
    {                                                                                           \
        L_TYPE *list = calloc(1, sizeof(L_TYPE));                                               \
        list->data = data;                                                                      \
        return list;                                                                            \
    }

#define NEWLISTAPPEND(L_TYPE, L_FUNPREFIX)                                                      \
    L_TYPE* L_FUNPREFIX##Append(L_TYPE *head, L_TYPE *tail)                                     \
    {                                                                                           \
        if(!head){return tail;}                                                                 \
        L_TYPE *cur = head;                                                                     \
        while(cur->next){cur = cur->next;}                                                      \
        cur->next = tail;                                                                       \
        return head;                                                                            \
    }

#define NEWLISTAPPENDNEW(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                       \
    L_TYPE* L_FUNPREFIX##AppendNew(L_TYPE *head, L_DATATYPE data)                               \
    {                                                                                           \
        return L_FUNPREFIX##Append(head, L_FUNPREFIX##New(data));                               \
    }

#define NEWLISTPREPEND(L_TYPE, L_FUNPREFIX)                                                     \
    L_TYPE* L_FUNPREFIX##Prepend(L_TYPE *oldhead, L_TYPE *newhead)                              \
    {                                                                                           \
        if(!newhead){return oldhead;}                                                           \
        if(!oldhead){return newhead;}                                                           \
        L_TYPE *cur = newhead;                                                                  \
        while(cur->next){cur = cur->next;}                                                      \
        cur->next = oldhead;                                                                    \
        return newhead;                                                                         \
    }

#define NEWLISTPREPENDNEW(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                      \
    L_TYPE* L_FUNPREFIX##PrependNew(L_TYPE *oldhead, L_DATATYPE data)                           \
    {                                                                                           \
        return L_FUNPREFIX##Prepend(oldhead, L_FUNPREFIX##New(data));                           \
    }

#define NEWLISTLEN(L_TYPE, L_FUNPREFIX)                                                         \
    st L_FUNPREFIX##Len(L_TYPE *list)                                                           \
    {                                                                                           \
        st len = 0;                                                                             \
        while(list){                                                                            \
            list = list->next;                                                                  \
            len++;                                                                              \
        }                                                                                       \
        return len;                                                                             \
    }

#define NEWLISTFINDLINKPARENT(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                  \
    L_TYPE* L_FUNPREFIX##FindLinkParent(L_TYPE *list, L_TYPE *find)                             \
    {                                                                                           \
        if(!list || !find){return NULL;}                                                        \
        while(list->next && list->next != find){list = list->next;}                             \
        return list->next ? list : NULL;                                                        \
    }

#define NEWLISTFINDDATAPARENT(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                  \
    L_TYPE* L_FUNPREFIX##FindDataParent(L_TYPE *list, L_DATATYPE find)                          \
    {                                                                                           \
        if(!list){return NULL;}                                                                 \
        while(list->next && list->next->data != find){list = list->next;}                       \
        return list->next ? list : NULL;                                                        \
    }

#define NEWLISTFINDDATA(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                        \
    L_TYPE* L_FUNPREFIX##FindData(L_TYPE *list, L_DATATYPE find)                                \
    {                                                                                           \
        while(list && list->data != find){list = list->next;}                                   \
        return list;                                                                            \
    }

#define NEWLISTINSERTAFTER(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                     \
    L_TYPE* L_FUNPREFIX##InsertAfter(L_TYPE *parent, L_TYPE *addition)                          \
    {                                                                                           \
        if(!parent){return addition;}                                                           \
        L_TYPE *next = parent->next;                                                            \
        parent->next = addition;                                                                \
        L_TYPE *cur = addition;                                                                 \
        while(cur->next){cur = cur->next;}                                                      \
        cur->next = next;                                                                       \
        return parent;                                                                          \
    }

#define NEWLISTTYPE(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                            \
    typedef struct L_TYPE{                                                                      \
        L_DATATYPE data;                                                                        \
        struct L_TYPE *next;                                                                    \
    }L_TYPE;                                                                                    \
    NEWLISTNEW(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                                 \
    NEWLISTLEN(L_TYPE, L_FUNPREFIX)                                                             \
    NEWLISTAPPEND(L_TYPE, L_FUNPREFIX)                                                          \
    NEWLISTAPPENDNEW(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                           \
    NEWLISTPREPEND(L_TYPE, L_FUNPREFIX)                                                         \
    NEWLISTPREPENDNEW(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                          \
    NEWLISTFINDLINKPARENT(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                      \
    NEWLISTFINDDATAPARENT(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                      \
    NEWLISTFINDDATA(L_TYPE, L_DATATYPE, L_FUNPREFIX)                                            \
    NEWLISTINSERTAFTER(L_TYPE, L_DATATYPE, L_FUNPREFIX)

#define NEWLISTTYPE_P(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)                             \
    NEWLISTPRINT(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)                                  \
    NEWLISTPRINTLN(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)                                \
    NEWLISTLISTPRINT(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)                              \
    NEWLISTLISTPRINTLN(L_TYPE, L_DATATYPE, L_FUNPREFIX, L_PRINTSPEC)

#endif /* end of include guard: LIST_H */
