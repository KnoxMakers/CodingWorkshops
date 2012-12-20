a=1
b=1
c=0
sum=0
while b < 4000000:
    temp=b
    b=a+b
    a=temp
    if b%2==0:
        sum+=b
print sum
