import sys

def fibo(n: int):
    if n < 2:
        return n

    return fibo(n - 1) + fibo(n - 2)

if __name__ == "__main__":
    first_arg = int(sys.argv[1])
    fibo_is = fibo(first_arg)
    print(f'Fibonacci is: {fibo_is}')
