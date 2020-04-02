#ifndef DLIST_H
#define DLIST_H

struct _Double_ListNode;
typedef struct _Double_ListNode double_listnode_t;

typedef struct _Double_ListNode* double_listnode_p;

typedef void (*DListDataPrintFunc)(void* data);
typedef void (*DListDataVisitFunc)(void* ctx, void* data);

#endif

#ifdef _cplusplus
extern "C" {
#endif

#ifdef _plusplus
}
#endif
