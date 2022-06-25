from collections import Counter

inp = []
with open('input.txt') as txt:
    for line in txt:
        inp.append(line.replace('\n', ''))
    inp = dict(Counter(inp))

with open('output.txt', 'w') as txt:
    txt.write('\n'.join([f'{key} {value}' for key, value in sorted(inp.items())]))