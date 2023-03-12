'''
rotation with fixed-point rationals
'''

from math import sin, cos, degrees, radians

unity = 1<<32


def fp3232_cos(n, angle):
    assert(0 <= angle <= 90)
    return n * F[angle] >> 32


def fp3232_sin(n, angle):
    assert(0 <= angle <= 90)
    return n * F[90 - angle] >> 32


def float_to_fp3232(n):
    return round(unity * n)


def fp3232_to_float(n):
    return n / unity



D = list(range(91))
R = list(map(radians, D))
C = list(map(cos, R))
F = list(map(float_to_fp3232, C))

##for f in F:
##    print(f'0x{f:016x}')

print('''\
/*
This is Sine function from angle (one quadrant, 90°) divided into
2-to-the-16th discrete values: 0 = 0, 0x10000 = 90°
to the sine in 0.32 format: 0x1_0000_0000 = 1, 0xffff_ffff = 0.99999....

e.g. sine_table[0x10000] = 0x1_0000_0000 = 1

if you have degrees (from 0 to 90) in some variable (u8)n:

    u64 sin_n = sine_table[n * 0x10000 / 90];  // sin_n is 0.32 format

If you have some sine value from the table, you might use it with
e.g. a coordinate in 16.16 format, like so:


    u32 x = ...;  // 123.4 in 16.16 format

    u32 new_x = x * sin_n >> 32  // multiply by sine then adjust for scale factor

*/
u64 sine_table[0x10001] = {''')

for n in range(0x10001):
    x = float_to_fp3232(sin(radians(90 * n / (0x10000))))
    print(f'0x{x:x},', end=' ' if ((n + 1) % 8) else '\n')

print('};')

