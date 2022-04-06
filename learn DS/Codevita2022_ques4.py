def func(q,w,e):
    return q+(w*e)

def func2(x,y,k,j):
    if x>=y:
        k=0
        j=x-y
    else:
        j=0
        k=y-x
    return (k,j)
    
t1=int(input())
t2=int(input())
n=int(input())
v=list(map(int,input().split()))
v.sort()
# print(v)
c1=0
c2=0
k=0
j=t1*v[n-1]
a=[]
b=[]
a.append(v[n-1])
c1+=1
for i in range(n-2,-1,-1):
    x=func(j,t1,v[i])
    y=func(k,t2,v[i])
    if x>=y:
        b.append(v[i])
        c2+=1
        x=x-func(0,t1,v[i])
    else:
        a.append(v[i])
        c1+=1
        y=y-func(0,t2,v[i])
    k,j=func2(x,y,k,j)
for i in range(0,c1):
    print(a[i],end=" ")
print()
for i in range(0,c2):
    print(b[i],end=" ")
print()
        