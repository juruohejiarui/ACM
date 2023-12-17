cnt = []

def calc(ls) :
    dic = {}
    for p in ls:
        dic[p[0]] = []
    for i in range(len(ls)):
        dic[ls[i][0]].append((ls[i][1], i))
    # print(dic)
    for p, pls in dic.items():
        pls.sort()
        for pos in pls:
            cnt[pos[1]] += 2
        cnt[pls[0][1]] -= 1
        cnt[pls[-1][1]] -= 1

if __name__ == "__main__":
    n, m = map(int, input().split(' '))
    vk, hk, d1k, d2k = [], [], [], []
    cnt = [0 for i in range(0, m)]
    ans = [0 for i in range(0, 9)]
    for i in range(0, m):
        px, py = map(int, input().split(' '))
        vk.append((py, px))
        hk.append((px, py))
        d1k.append((px + py, -px + py))
        d2k.append((-px + py, px + py))


    calc(vk); calc(hk); calc(d1k); calc(d2k)
    
    for i in range(0, m): ans[cnt[i]] += 1
    for i in range(0, 9): print(f"{ans[i]} ", end='')