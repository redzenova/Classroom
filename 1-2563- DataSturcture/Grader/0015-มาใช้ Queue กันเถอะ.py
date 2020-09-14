class Queue:

    def __init__(self):
        self.queue = []

    def __str__(self):
        return  ', '.join(str(data) for data in self.queue) if self.size() != 0 else 'Empty'
    
    def enQueue(self, item):
        self.queue.append(item)
    
    def deQueue(self):
        return self.queue.pop(0) if self.size() != 0 else 'Empty'

    def size(self):
        return len(self.queue)
    

lst = input('Enter Input : ').split(',')
Q = Queue()
DQ = Queue()

for i in lst:
    i = i.split()
    if i[0] == 'D':
        item = Q.deQueue()
        if item != 'Empty':
            DQ.enQueue(item)
            print(item, '<- ', end = '')
    else:
        Q.enQueue(int(i[1]))
    print(Q)
print(DQ,':',Q)


# ให้น้องๆเขียนโปรแกรมโดยรับ input 2 แบบ โดยใช้ Queue ในการแก้ปัญหา
# E  <value>  ให้นำ value ไปใส่ใน Queue และทำการแสดงผล ข้อมูลปัจจุบันของ Queue
# D                 ให้ทำการ Dequeue ตัวที่อยู่หน้าสุดของ Queue ออก หลังจากนั้นแสดงตัวเลขที่เอาออกมา และ แสดงผลข้อมูล
#                     ปัจจุบันของ Queue
# ***และเมื่อจบการทำงานให้แสดงผลข้อมูลปัจจุบันของ Queue พร้อมกับข้อมูลที่ถูก Dequeue ทั้งหมดตามลำดับ
# ***ถ้าหากไม่มีข้อมูลใน Queue แล้วให้แสดงคำว่า  Empty