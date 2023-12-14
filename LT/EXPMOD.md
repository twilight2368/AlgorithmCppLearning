# Description
Given two positive integers a and b. Compute a^b mod (10^9 + 7)

# Input

One line contains two integers a and b (1 <= a,b <= 18446744073709551614)

# Output

The value a^b mod (10^9+7)

# Example

## Input
```
2  3
```
## Output
```
8
```

# Hint I guess
The idea is based on below properties.  

- Property 1:  
(m * n) % p has a very interesting property:   
(m * n) % p =((m % p) * (n % p)) % p  

- Property 2:   
if b is even:   
(a ^ b) % c = ((a ^ b/2) * (a ^ b/2))%c   
if b is odd:   
(a ^ b) % c = (a * (a ^( b-1))%c  

- Property 3:   
If we have to return the mod of a negative number x whose absolute value is less than y:   
then (x + y) % y will do the trick  

Note:   

Also as the product of (a ^ b/2) * (a ^ b/2) and a * (a ^( b-1) may cause overflow, hence we must be careful about those scenarios   