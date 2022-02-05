#too lazy to write it in c
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
        
class Solution:        
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        list1 = []
        for i in range(0, len(lists)):
            temp = lists[i]
            while temp:
                list1.append(temp.val)
                temp = temp.next
        
        if not list1:
            return None
        
        list1.sort()
        newList = ListNode(val=list1[0])
        temp = newList
        for i in range(1, len(list1)):
            temp.next = ListNode(val=list1[i])
            temp = temp.next
        
        
        return newList
      
     
