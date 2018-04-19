island_map = [[0,1,0,0],
              [1,1,1,0],
              [0,1,0,0],
              [1,1,0,0]]
i = 0
ret = 0
for r in island_map:
    print 'row:', r
    j = 0
    for c in r:
        print 'col:', c
        if c == 0:
            j += 1
            continue
        ## edge
        if i == 0 or i == len(island_map) - 1:
            ret += 1
        if j == 0 or j == len(r) - 1:
            ret += 1
        if i > 0 and i < len(island_map) - 1:
            print j
            if not island_map[i - 1][j] or not island_map[i + 1][j]:
                ret += 1
        if j > 0 and j < len(r) - 1:
            if not island_map[i][j - 1] or not island_map[i][j + 1]:
                ret += 1
        j += 1
    i += 1

print ret
