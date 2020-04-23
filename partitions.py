
from operator import ixor

def printArray(p,u,n):
    if (n > 1):
        res = p[0]
        for i in range(1,n):
            res = res ^ p[i]
        if (res == u):
            for i in range(0, n):
                print(p[i], end = " ")
            print()
            return True


def printAllUniqueParts(u,v):

    if ( u == 0 and v == 0):
        print(0)
        return


    p = [0] * v     # An array to store a partition
    k = 0         # Index of last element in a partition
    p[k] = v     # Initialize first partition
                 # as number itself

    # This loop first prints current partition,
    # then generates next partition.The loop
    # stops when the current partition has all 1s
    while True:

            # print current partition
            OK = printArray(p,u, k + 1)

            if (OK == True): #If ok is True then we stop the loop because we already found the minimum length array
                return

            # Generate next partition

            # Find the rightmost non-one value in p[].
            # Also, update the rem_val so that we know
            # how much value can be accommodated
            rem_val = 0
            while k >= 0 and p[k] == 1:
                rem_val += p[k]
                k -= 1

            # if k < 0, all the values are 1 so
            # there are no more partitions
            #If there are no more partitions we print -1 because it is impossible to have such an array
            if k < 0:
                print(-1)
                return

            # Decrease the p[k] found above
            # and adjust the rem_val
            p[k] -= 1
            rem_val += 1

            # If rem_val is more, then the sorted
            # order is violated. Divide rem_val in
            # different values of size p[k] and copy
            # these values at different positions after p[k]
            while rem_val > p[k]:
                p[k + 1] = p[k]
                rem_val = rem_val - p[k]
                k += 1

            # Copy rem_val to next position
            # and increment position
            p[k + 1] = rem_val
            k += 1

u = int(input("Enter u: "))
v = int(input("Enter v: "))

printAllUniqueParts(u,v)
