import re

ans, mx = [], 0
with open('input.txt') as txt:
    for line in txt:
        act = line[0]
        num = int(re.findall(r'(\d+)', line)[0])
        s = re.findall(r'\d+ (.+)', line)
        if num > mx + 1:
            ans.clear()
            ans.append(['ERROR'])
            break
        if mx < num: mx = num

        if act == '+':
            ans.insert(num - 1, s)
        
        elif act == '*':
            if(num > len(ans)):
                ans.clear()
                ans.append(['ERROR'])
                break
            else:
                ans[num - 1] = s

        elif act == '-':
            if(num > len(ans)):
                ans.clear()
                ans.append(['ERROR'])
                break
            else:
                ans.pop(num - 1)

        print(ans)

if len(ans) == 0: ans.append(['EMPTY'])

with open('output.txt', 'w') as txt:
    txt.write('\n'.join([i[0] for i in ans]))

# +1 I am a pupil.
#  I am a pupil.

# +2 He is a pupil.
# I am a pupil.
# He is a pupil.

# +2 She is a pupil.
# I am a pupil.
# She is a pupil.
# He is a pupil.

# +3 This is a pupil.
# I am a pupil.
# She is a pupil.
# This is a pupil.
# He is a pupil.

# *2 Bob went home.
# I am a pupil.
# Bob went home.
# This is a pupil.
# He is a pupil.

# -3
# I am a pupil.
# Bob went home.
# He is a pupil.
