max_size = 11

left_end = right_end = -1
queue = [None] * max_size
mean = max_size//2

def enqueue(data):

    global left_end, right_end, mean

    if (left_end < 0 and right_end == max_size - 1):
        print('Overflow !')
        return

    elif(left_end == -1 and right_end == -1):
        left_end = right_end = mean
        queue[mean] = data

    else:
        ch = int(input('1.insert at right\n2.insert at left\nchoose an option : '))

        if(ch == 1):
            if(right_end == max_size - 1):
                print('Overflow !')
                return
            right_end += 1
            queue[right_end] = data

        elif(ch == 2):
            if(left_end <= 0):
                print('Overflow !')
                return
            left_end -= 1
            queue[left_end] = data

        else:
            print('Invalid input !')
            return

def dequeue():

    global left_end, right_end, mean

    if(left_end == -1 and right_end == -1):
        print('Underfow !')
        return
    
    ch = int(input('1.delete at right\n2.delete at left\nchoose an option : '))

    if ch == 1 : 
        if(right_end < mean):
            print('Underflow !')
            return
        right_end -= 1

    elif ch == 2:
        if(left_end > mean):
            print('Underflow !')
            return
        left_end += 1

    else:
        print('Invalid input !')
        return

def display():

    if(left_end == -1 and right_end == -1):
        print('Underfow !')
        return
    print("The current dequeue is : ")
    for i in range (left_end, (right_end+1)):
        print(f"{queue[i]}", end=' ')
    print()


enqueue(2)
enqueue(512)
enqueue(22)
display()
dequeue()
dequeue()
display()
