N=11**6;h=[0]*N;input()
for x in input().split():h[int(x)]+=1
print(max(i*(sum(h[i::i])>1)for i in range(1,N)))
