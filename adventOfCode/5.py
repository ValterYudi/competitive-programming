import sys
from queue import Queue
from collections import defaultdict
from itertools import permutations

def get_ints(line):
    #se x não for vazio, retorna x convertido para int
    return [int(x) for x in line if x]
def intersec(tuple1, tuple2):
    return (max(tuple1[0], tuple2[0]), min(tuple1[1], tuple2[1]))
lines = [line.strip().split(" ") for line in sys.stdin.readlines()]
seeds = get_ints(lines[0][1:])
seeds_range = [(seeds[i], seeds[i]+seeds[i+1]) for i in range(0, len(seeds), 2)]
print(seeds_range)
print(intersec(seeds_range[0],seeds_range[1]))
#for line in lines[2:]:
    #print(line)
lines = lines[2:]
#print(mapped_seeds)
aux_seeds_range = seeds_range.copy()
ans = set()
for s in seeds_range:
    tuplas = {s}
    stop = False
    for numer
        for line in lines:
            if "map:" in line or line == "":
                stop = False
                continue
            if stop:
                continue
            convert_seeds = get_ints(line.split(" "))
            origin  = (convert_seeds[1], convert_seeds[1]+convert_seeds[2])
            destination = (convert_seeds[0], convert_seeds[0]+convert_seeds[2])
            inter = intersec(origin, destination)
            if inter[0] <= inter[1]:
                if
                num = inter
                stop = True

        #check >= 0 and check < mapa[2]:
            #num = (check+mapa[0])
            #print("Para o seed: ", s, "\no mapa: ", mapa, "deu: ", num)
    ans.add(num)
print(min(ans))