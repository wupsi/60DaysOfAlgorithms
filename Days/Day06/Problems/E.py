ans = []
with open('input.txt') as txt:
    for line in txt:
        if line[0] == '+': ans.append(int(line[1:]))
        if line[0] == '-':
            if int(line[1:]) in ans:
                ans.remove(int(line[1:]))
            else:
                ans.clear()
                ans.append('ERROR')
                break
if len(ans) == 0: ans.append("EMPTY")

with open('output.txt', 'w') as txt:
    txt.write(' '.join([str(i) for i in sorted(ans)]))