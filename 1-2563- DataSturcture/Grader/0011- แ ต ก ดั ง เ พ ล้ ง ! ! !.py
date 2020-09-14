inp = input('Enter Input : ').split(',')

w, feq = [], []
for i in inp:
    i = i.split()
    while len(w) > 0 and int(i[0]) > w[-1]:
        print(feq.pop())
        w.pop()
    w.append(int(i[0]))
    feq.append(int(i[1]))