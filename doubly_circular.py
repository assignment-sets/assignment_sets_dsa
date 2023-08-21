# doubly circular linked list

class node:
    def __init__(self,data):
        self.data = data
        self.prev = None
        self.next = None

class linked_list:
    def __init__(self):
        self.head = None

    def insert_node(self, data):
        new_node = node(data)   

        if self.head == None:
            self.head = new_node
            new_node.next = self.head
            new_node.prev = new_node.next
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = new_node
            new_node.prev = temp
            new_node.next = self.head
            self.head.prev = new_node

        print("Successfully inserted !")
    
    def display_node(self):
        if self.head == None:
            print("list is empty !")
        else : 
            temp = self.head
            print("The list items are : ")
            while(temp.next != self.head):
                print(f"{temp.data}")
                temp = temp.next
            print(f"{temp.data}")

    def delete_node(self):
        permit = 1

        if self.head == None:
            print("list is empty !")
            permit = 0

        elif self.head.prev == self.head.next:
            self.head = None

        else:
            self.head.prev.next = self.head.next
            self.head.next.prev = self.head.prev
            self.head = self.head.next

        if permit:
            print("successfully deleted !")
        
    
my_list = linked_list()

while True : 
    ch = int(input("Menu\n1.insert node\n2.delete node\n3.display node\n4.exit\nchoose one : "))

    if ch == 1:
        data = int(input("Enter integer data : "))
        my_list.insert_node(data)

    elif ch == 2:
        my_list.delete_node()

    elif ch == 3:
        my_list.display_node()

    elif ch == 4:
        break

    else:
        print("invalid input !")
        continue
