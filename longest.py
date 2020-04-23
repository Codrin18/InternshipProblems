
def index(A,l,r,key):

    while (r - l > 1):

        m = l + (r - l)//2
        if (A[m] >= key):
            r = m
        else:
            l = m
    return r

def LongestIncreasingSubsequenceLength(A, size):

    # Add boundary case,
    # when array size is one

    tailTable = [0 for i in range(size + 1)]
    len = 0 # always points empty slot

    tailTable[0] = A[0]
    len = 1
    for i in range(1, size):

        if (A[i] < tailTable[0]):

            # new smallest value
            tailTable[0] = A[i]

        elif (A[i] > tailTable[len-1]):

            # A[i] wants to extend
            # largest subsequence
            tailTable[len] = A[i]
            len+= 1

        else:
            # A[i] wants to be current
            # end candidate of an existing
            # subsequence. It will replace
            # ceil value in tailTable
            tailTable[index(tailTable, -1, len-1, A[i])] = A[i]


    return len

n = int(input("Enter the initial size of the array: "))
A = []

for i in range(n):
    a = int(input("Enter the elements of the array: "))
    A.append(a)

A = A * 3 # We concatanate the array n times
n = n * n

print(LongestIncreasingSubsequenceLength(A,n)) # Print the lkength of the longest increasing sequence
