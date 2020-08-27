def sum(lst):
    if (len(lst)) < 3:
        return 'Array Input Length Must More Than 2'
    ans =[]
    for i in range(len(lst)):
        for j in range(i+1, len(lst)):
            for k in range(j+1, len(lst)):
                if lst[i] + lst[j] + lst[k] == 0 and [lst[i], lst[j], lst[k]] not in ans:
                    ans.append([lst[i], lst[j], lst[k]])
    return ans
    
txt = list(map(int, input('Enter Your List : ').split()))
print(sum(txt))
