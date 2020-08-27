class Email:
    def __init__(self):
        self.fname = ''
        self.lname = ''
        self.sa = True

    def E(self):
        if self.lname == '':
            return "'E' -> Email : Please Enter Your Lastname"
        else:
            return "'E' -> Email : " + str(self.fname).lower() + '.' \
        + str(self.lname).lower() + '@kmitl.ac.th'

    def A(self,s1,s2):
        self.fname = s1
        self.lname = s2

    def F(self, first):
        self.fname = first

    def L(self, last):
        self.lname = last

    def SA(self):
        if self.fname == '' and self.lname == '' and self.sa:
            return "'SA' -> Fullname : Please Enter Your Firstname & Lastname"
        elif self.lname == '' and self.sa:
            return "'SA' -> Fullname : Please Enter Your Lastname"
        elif self.sa:
            self.sa = False
            return "'SA' -> Fullname : " + str(self.fname).capitalize() + ' ' + str(self.lname).capitalize()

    def SF(self):
        return "'SF' -> Firstname : " + str(self.fname).capitalize()

    def SL(self):
        if self.lname == '':
            return "'SL' -> Lastname : Please Enter Your Lastname"
        return "'SL' -> Lastname : " + str(self.lname).capitalize()

    def X(self):
        return
        
"""
E -> print email
A -> input "fname lname"
F -> input "fname"
L -> input "lname"
SA -> print "fname lname"
SF -> print "fname"
SL -> print "lname"
X -> exit
A JoHn WicKS,E,F TONY,E,SF,SA,X
SA,F steve,SA,SF,E,L ROGERS,E,SL,X
A JOHN CENA, SA,E,K ing,SA,A TONY STARK,X
"""

print('*** Create Email < BY KMITL > ***')
txt = input('Enter Input : ').split(',')
mail = Email()

for i in txt:
    if i.startswith('E'):
        print(mail.E())

    elif i.startswith('A'):
        s = i.split(sep=' ')
        #print(s)
        mail.A(s[1], s[2])

    elif i.startswith('F'):
        f = i.split(sep=' ')
        #print(s)
        mail.F(f[1])

    elif i.startswith('L'):
        l = i.split(sep=' ')
        #print(s)
        mail.L(l[1])

    elif i.startswith('SA'):
        print(mail.SA())
        
    elif i.startswith('SF'):
        print(mail.SF())

    elif i.startswith('SL'):
        print(mail.SL())

    elif i.startswith('X'):
        break
    else:
        print("'" + i + "'" + ' is Invalid Input !!!')
        break
