import sympy

x = sympy.symbols('x')
zeropoly = x - x
onepoly = zeropoly + 1

def lagrangepoly(yseq, xseq=None):
    """Build a Lagrange polynomial from a sequence of `y` values.
    If no sequence of `x`s is given, use x = 1, 2, ..."""
    if xseq is None:
        xseq = list(range(1, len(yseq) + 1))
    assert len(yseq) == len(xseq)

    result = zeropoly
    for j, (xj, yj) in enumerate(zip(xseq, yseq)):
        # Build the j'th base polynomial
        polyj = onepoly
        for m, xm in enumerate(xseq):
            if m != j:
                polyj *= (x - xm) / (xj - xm)
        # Add in the j'th polynomial
        result += yj * polyj
    return sympy.expand(result)


n = sympy.symbols('n')
U_n = 1-n+n**2-n**3+n**4-n**5+n**6-n**7+n**8-n**9+n**10

arr = [U_n.subs(n, i) for i in range(1, 100)]

ans = 0
for i in range(0, 20):
    tmp = lagrangepoly(arr[0: i+1])
    v = tmp.subs(x, i+2)
    if v == arr[i+1]:
        print(ans)
        exit()
    ans += v
print("NOT FOUND")
