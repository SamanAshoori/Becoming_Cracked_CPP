import time

# Start the timer
start_time = time.time()

fib_list = []
a, b = 0, 1

# Generate 200k Fibonacci numbers
for _ in range(200000):
    fib_list.append(a)
    a, b = b, a + b

end_time = time.time()

print(f"Generated {len(fib_list)} numbers in {end_time - start_time:.6f} seconds.")
# print(fib_list) # Uncomment this line if you want to see the actual numbers