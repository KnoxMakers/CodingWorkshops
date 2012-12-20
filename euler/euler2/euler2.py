FibNumA, FibNumB, EvenFibTotal = 0, 1, 0
print "The Fibonacci sequence values that do not exceed 4,000,000 are:"
print FibNumA
print FibNumB
while (FibNumB < 4000001):
        if (FibNumB % 2 == 0):
                EvenFibTotal = EvenFibTotal + FibNumB
        print FibNumB
        FibNumA, FibNumB = FibNumB, FibNumA + FibNumB
else:
        print "The sum of all even Fibonacci sequence numbers is", EvenFibTotal
