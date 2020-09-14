print("*** Reading E-Book ***")

text, hl = input("Text , Highlight : ").split(",")
for x in range(len(text)):
    if(text[x]==hl):
        print("["+ text[x] + "]", end='')
    else:
        print(text[x], end='')
