class node:
    def __init__(self,data=None,next=None):
        self.data = data
        self.next = next

class linkedList:
    def __init__(self):
        self.head = None
    
    def insertAtBegining(self,data):
        nodeAtStart = node(data, self.head)
        self.head = nodeAtStart

    def insertAtEnd(self,data):
        if self.head is None:
            self.head = node(data,None)
            return
        
        lisEnd = self.head        
        while lisEnd.next:
            lisEnd = lisEnd.next
        lisEnd.next = node(data,None)
            
    def print(self):
        if self.head is None:
            print("Linked list is empty\n")
            return
    
        itr = self.head
        llstr = ''

        while itr:
            llstr += str(itr.data) + '-->'
            itr = itr.next

        print(llstr)

if __name__ == '__main__':
    ll = linkedList()
    ll.insertAtEnd(6)
    ll.insertAtBegining(5)
    ll.insertAtBegining(89)
    ll.insertAtEnd(67)
    ll.print()