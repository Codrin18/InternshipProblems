

def countMinTimeReversal(bracketExpr):

    l = len(bracketExpr)

    #The length of the expression must be an even number
    #to make it balanced

    if (l % 2 == 1):
        return -1

    stack = []
    n = 0
    for i in range(l):
        if (bracketExpr[i] =='' and len(stack)):

            if (stack[0] == ''):
                stack.pop(0)
            else:
                stack.insert(0,bracketExpr[i])

            #n += 1
        else:
            stack.insert(0,bracketExpr[i])
            n += 1

    #length of the reduced expression
    #red= (m+n)

    red = len(stack)

    #count opening brackets at The
    #end of stack
    nr = 0
    while(len(stack) and stack[0] == ''):
        stack.pop(0)
        nr += 1

    return (red // 2  + n // 2 + nr % 2)

n = int(input("Enter an integer: "))
expr = ""

for i in range(n):
    s = str(input("Enter a beacket: "))
    expr += s

print(countMinTimeReversal(expr.strip()))
