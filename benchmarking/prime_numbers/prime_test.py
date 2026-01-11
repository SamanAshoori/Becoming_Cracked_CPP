#Import time to for 1 second
import time
nums_checked = 0
start_time = time.perf_counter()
end_time = start_time + 1

#Creating as many prime numbers as I can in one second
def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def print_primes():
    while time.perf_counter() < end_time:
        for num in range(1,1000000):
            if is_prime(num):
                print(num)
                nums_checked +=1
    print(f"Python Iterations: {nums_checked}")

# Example usage

print_primes()

#TO DO: LOOP 3 TIMES AND GET AVERAGE PRIMES CREATED IN 1 SECOND