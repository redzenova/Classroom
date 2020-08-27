print("*** Odd Even ***")
in_type , data , pos = input("Enter Input : ").split(",")

"""
    in_type : type of data [List(L) , String(S)]
    data : input data
    pos : positon of data to output [Odd , Even]
"""

if in_type == 'L':
    data = data.split()


def odd_even(arr, s):
    lst = []
    for i, ch in enumerate(arr):
        if s == 'Odd':
            if i % 2 == 0:
                lst.append(ch)
        else:
            if i % 2 == 1:
                lst.append(ch)
    if type(arr) == str:
        return ''.join(lst)
    return lst

print(odd_even(data, pos))
    # a b c d

    # for i, ch in enumerate([a, b, c])