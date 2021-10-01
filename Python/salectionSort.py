from array import *
from random import randint

def display(arr,n):
    for i in range(0,n):
        print(a[i], end =" ")
        
def select(arr,n):
    for i in range(0, n-1):
        min=i
        for j in range(i+1,n):
            if a[j]<a[min]:
                min=j
                
        if (i!=min):
            temp=a[i]
            a[i]=a[min]
            a[min]=temp
        
        
a=array("i",[])
i=0
#inserting 10 randomly generated numbers
while(i<10):
    a.insert(i,randint(0,20))
    i+=1
    
print("Array before Sorting")
display(a,10)
select(a,10)

print("\n Array after sorting")
display(a,10)

'''
OUTPUT
print("Array before Sorting")
display(a,10)
select(a,10)

print("\n Array after sorting)
display(a,10)
'''
