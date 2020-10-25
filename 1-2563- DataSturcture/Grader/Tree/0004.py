# patternCount = 0
# def pantip(k, n, priceList, path):
#     global patternCount
#     if n>=len(priceList):
#         if k==0:
#             print(*path)
#             patternCount+=1
#         return

#     if k-priceList[n]>=0:
#         path.append(priceList[n])
#         pantip(k-priceList[n],n+1,priceList,path)

#         path.pop()
#         pantip(k,n+1,priceList,path)
#     else:
#         pantip(k,n+1,priceList,path)

#     return patternCount

# inp = input('Enter Input (Money, Product) : ').split('/')
# priceList = [int(i) for i in inp[1].split()]
# pattern = pantip(int(inp[0]), 0, priceList, [])
# print("Krisada can purchase Product: {0} with: {1} Baht | {2} Pattern".format(priceList, inp[0], pattern))

# For Hacktoberfest 2020!