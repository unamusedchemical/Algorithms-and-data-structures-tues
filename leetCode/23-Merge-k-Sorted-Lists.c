//c implementation
 struct ListNode {
     int val;
     struct ListNode *next;
 };



struct ListNode *mergeLists(struct ListNode *a, struct ListNode *b) {
    
    
    struct ListNode *result = malloc(sizeof(struct ListNode));
    result->next = NULL;
    struct ListNode *temp = result;
    
    while(a || b) {
        if(a && b) {
            if(a->val > b->val) {
                temp->next = b;
                b = b->next;
            } else if(a->val < b->val) {
                temp->next = a;
                a = a->next;
            } else if(a->val == b->val) {
                temp->next = a;
                a = a->next;
                temp->next->next = b;
                b = b->next;
                temp = temp->next;
            }
            
            temp = temp->next;
        } else {
            temp->next = a != NULL ? a : b; 
            break;
        } 
    }
    temp = result->next;
    free(result);
    return temp;   
}

struct ListNode* mergeKLists(struct ListNode **lists, int listsSize){
    struct ListNode *merged;
    
    if(listsSize == 0) {
        return NULL;
    } else {
        merged = lists[0];
        for(int i = 1; i < listsSize; ++i) {
            merged = mergeLists(merged, lists[i]);
        }
    }

    return merged;
}
