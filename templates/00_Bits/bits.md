# Bit Manipulation Cheat Sheet (basic -> advanced)

Notation: `&` AND, `|` OR, `^` XOR, `~` NOT, `<<` `>>` shifts. Bits are numbered from 0 (LSB).
Assume non-negative integers unless stated.

---

## 0. Pitfalls (read once)

- Precedence: `==` binds tighter than `&`, `^`, `|`. Always write `(x & 1) == 0`.
- C++/Java: use `1LL << k` (or `1ULL`) for k >= 31. `1 << 31` overflows int.
- Python ints are unbounded: `~x == -x - 1`, negatives act like infinite 1s on the left. Mask with `& ((1<<k)-1)` to simulate fixed width.
- Right shift of negatives: arithmetic (sign-extending) in most languages; floor division by 2^k.
- Shifting by >= word width is undefined in C/C++.
- C++ builtins: `__builtin_popcountll(x)`, `__builtin_ctzll(x)` (undefined for 0), `__builtin_clzll(x)` (undefined for 0). Highest set bit index = `63 - __builtin_clzll(x)`. Python: `x.bit_count()`, `x.bit_length()`.

---

## 1. Basic operations

| Goal                               | Expression                           |
| ---------------------------------- | ------------------------------------ |
| Check bit i                        | `(x >> i) & 1`                       |
| Set bit i                          | `x \| (1 << i)`                      |
| Clear bit i                        | `x & ~(1 << i)`                      |
| Toggle bit i                       | `x ^ (1 << i)`                       |
| Set bit i to v (0/1)               | `(x & ~(1<<i)) \| (v << i)`          |
| Is odd                             | `x & 1`                              |
| x \* 2^k                           | `x << k`                             |
| floor(x / 2^k)                     | `x >> k`                             |
| x mod 2^k                          | `x & ((1 << k) - 1)`                 |
| Mask of k ones                     | `(1 << k) - 1`                       |
| Keep low k bits / clear low k bits | `x & ((1<<k)-1)` / `x & ~((1<<k)-1)` |
| Negation                           | `-x == ~x + 1`                       |
| NOT                                | `~x == -x - 1`                       |
| Swap without temp                  | `a ^= b; b ^= a; a ^= b;`            |

---

## 2. Boolean algebra laws

- Commutative, associative: `& | ^` all.
- Distributive: `a & (b | c) = (a&b) | (a&c)`, `a & (b ^ c) = (a&b) ^ (a&c)`, `a | (b & c) = (a|b) & (a|c)`.
- De Morgan: `~(a & b) = ~a | ~b`, `~(a | b) = ~a & ~b`.
- Identities: `x&x = x`, `x|x = x`, `x^x = 0`, `x&0 = 0`, `x|0 = x`, `x^0 = x`, `x&~0 = x`, `x|~0 = ~0`, `x^~0 = ~x`.
- Absorption: `a & (a | b) = a`, `a | (a & b) = a`.
- `a ^ b = (a | b) & ~(a & b) = (a & ~b) | (~a & b)`.
- Subset test: `a` is a submask of `b` iff `a & b == a` iff `a | b == b`.
- Ordering: `a & b <= min(a, b) <= max(a, b) <= a | b`.

---

## 3. Lowest set bit / trailing bits tricks (x != 0 unless noted)

| Goal                                        | Expression                             |
| ------------------------------------------- | -------------------------------------- |
| Isolate lowest set bit                      | `x & -x`                               |
| Clear lowest set bit                        | `x & (x - 1)`                          |
| Mask of lowest set bit and everything below | `x ^ (x - 1)`                          |
| Set all trailing zeros to 1                 | `x \| (x - 1)`                         |
| Clear trailing ones                         | `x & (x + 1)`                          |
| Set lowest zero bit                         | `x \| (x + 1)`                         |
| Isolate lowest zero bit                     | `~x & (x + 1)`                         |
| Index of lowest set bit                     | `ctz(x)`                               |
| Power of two test (x > 0)                   | `x & (x - 1) == 0`                     |
| Power of two minus one test                 | `x & (x + 1) == 0`                     |
| Is x a power of 4                           | power of two and `x & 0x55555555 != 0` |

Why `x & (x-1)` works: subtracting 1 flips the lowest set bit to 0 and all trailing zeros to 1; AND removes exactly that bit.

Popcount (Kernighan): `while x: x &= x-1; c += 1` runs once per set bit.

Highest set bit:

- Index: `bit_length(x) - 1`.
- Round up to next power of two (32-bit): `x--; x |= x>>1; x |= x>>2; x |= x>>4; x |= x>>8; x |= x>>16; x++`.
- Largest power of two <= x: `1 << (bit_length(x) - 1)`.

---

## 4. XOR properties

- `x ^ x = 0`, `x ^ 0 = x`, commutative, associative -> XOR of a multiset cancels pairs.
- `a ^ b = c  <=>  a ^ c = b  <=>  b ^ c = a`. (Self-inverse: XOR is its own undo.)
- XOR is addition mod 2 per bit (no carries).
- Parity of popcount: `popcount(x ^ y) % 2 == (popcount(x) + popcount(y)) % 2`.
- Hamming distance(x, y) = `popcount(x ^ y)`.
- `x ^ y == 0  <=>  x == y`.
- `x ^ y` has its highest set bit at the highest position where x and y differ. So if `x < y`, the top bit of `x ^ y` is a bit that is 0 in x and 1 in y.
- Prefix XOR: `P[i] = a[0]^...^a[i-1]`, then `xor(a[l..r]) = P[r+1] ^ P[l]`.
- Subarray XOR equal to k: count pairs with `P[j] ^ P[i] = k` using a hashmap.
- If `x ^ y = s` then `x ^ s = y`; flipping a set of bits is XOR with that mask.
- XOR with `1` toggles parity: `x ^ 1` swaps 2k <-> 2k+1.
- Negation via XOR: `-x = (x ^ ~0) + 1`.

### 4.1 XOR of 0..n (the period-4 pattern)

```txt
f(n) = 0 ^ 1 ^ 2 ^ ... ^ n
n % 4 == 0  ->  n
n % 4 == 1  ->  1
n % 4 == 2  ->  n + 1
n % 4 == 3  ->  0
```

Range: `xor(l..r) = f(r) ^ f(l-1)`.

Reason: any aligned block `4k, 4k+1, 4k+2, 4k+3` XORs to 0 (the high bits appear 4 times and the low two bits give 0^1^2^3 = 0).

### 4.2 XOR of an aligned block

- For any `k >= 2`, XOR of the aligned block `m*2^k ... m*2^k + 2^k - 1` is 0 (every bit position appears an even number of times; the low bits are all balanced, the high prefix bits repeat 2^k times, which is even).
- Special case, the "new set bit" range `[2^a, 2^(a+1) - 1]`:
  - `a = 0`: `1`
  - `a = 1`: `2 ^ 3 = 1`
  - `a >= 2`: `0`
- Related: XOR of `0 .. 2^a - 1` is 0 for a >= 2, 1 for a = 1 (0^1), 0 for a = 0.
- Count of numbers in `[0, n]` with bit i set:

```txt
full  = (n + 1) // 2^(i+1)
count = full * 2^i + max(0, (n + 1) % 2^(i+1) - 2^i)
```

This is the engine behind "sum over all i in [0,n] of something per bit".

### 4.3 Gray code

- `g(i) = i ^ (i >> 1)`; consecutive values differ in exactly one bit.
- Inverse: `i = g; while (g >>= 1) i ^= g;` (prefix XOR of bits from top).

---

## 5. Arithmetic identities (AND / OR / XOR vs +, -)

Let `s = x + y`. Each bit position: the pair (x_i, y_i) is (0,0), (0,1), (1,0), (1,1).

| Identity                                                          | Notes                                     |
| ----------------------------------------------------------------- | ----------------------------------------- |
| `x + y = (x ^ y) + 2*(x & y)`                                     | XOR = sum without carry, AND<<1 = carries |
| `x + y = (x \| y) + (x & y)`                                      | per bit: OR + AND = x_i + y_i             |
| `x + y = 2*(x \| y) - (x ^ y)`                                    | combine the two above                     |
| `x \| y = (x ^ y) + (x & y)`                                      | XOR and AND are disjoint bit sets         |
| `x ^ y = (x \| y) - (x & y)`                                      |                                           |
| `x & y = (x + y - (x ^ y)) / 2`                                   | recover AND from sum and xor              |
| `x - y = (x ^ y) - 2*(~x & y)`                                    |                                           |
| `x ^ y = x + y  <=>  x & y = 0  <=>  x \| y = x + y`              | no carries                                |
| `x ^ y <= x + y`                                                  | equality iff `x & y = 0`                  |
| `x ^ y >= \|x - y\|`                                              | follows from the subtraction identity     |
| `popcount(x) + popcount(y) = popcount(x\|y) + popcount(x&y)`      |                                           |
| `popcount(x ^ y) = popcount(x) + popcount(y) - 2*popcount(x & y)` |                                           |

Existence of a pair with given sum and xor: there exist non-negative x, y with `x + y = S` and `x ^ y = X` iff
`S >= X`, `(S - X)` is even, and `((S - X)/2) & X == 0`. Then `x & y = (S - X)/2`. (Classic: min/max pair problems, "find a and b given a+b and a^b".)

Overflow-safe average (floor): `(x & y) + ((x ^ y) >> 1)`.
Ceil average: `(x | y) - ((x ^ y) >> 1)`.

---

## 6. Inequalities and the "spread" lemma

Let `a = x | y` and `b = x & y`. Then:

- `a + b = x + y` (same sum).
- `a >= max(x, y)` and `b <= min(x, y)`, so `(a, b)` is a more spread-out pair with the same sum as `(x, y)`.

Consequences (same sum, more spread):

- `a*b <= x*y` (product shrinks)
- `a^2 + b^2 >= x^2 + y^2` (sum of squares grows)

Algebraic check: `x^2 + y^2 = s^2 - 2xy` and `a^2 + b^2 = s^2 - 2ab`, so `x^2 + y^2 <= a^2 + b^2  <=>  ab <= xy`.

Generalisation: for any convex function f, `f(x) + f(y) <= f(x|y) + f(x&y)`. Useful for greedy proofs: "replace a pair (x, y) with (x|y, x&y) never decreases sum of squares." This is the basis of the problem where you may repeatedly do `x -> x&y, y -> x|y` and maximise the sum of squares (the total popcount per bit is conserved, so the best result packs each bit's ones into as few numbers as possible).

Other useful bounds:

- `x ^ y <= x | y`, `x & y <= x ^ y`? No: not always. Do not assume.
- `x | y < 2^k` iff both x, y < 2^k.
- If `x < 2^k`, then `x ^ y` and `x | y` differ from y only in the low k bits.
- `max over y of (x ^ y)` for y in [0, 2^k - 1] is `x ^ (2^k - 1)` when `x < 2^k`.

---

## 7. Per-bit counting (sums over pairs / subarrays)

Treat each bit independently. Let `c1` = number of elements with bit i set, `c0 = n - c1`.

- Sum over all unordered pairs of `a_p ^ a_q`: `sum_i 2^i * c1 * c0`.
- Sum over all unordered pairs of `a_p & a_q`: `sum_i 2^i * C(c1, 2)`.
- Sum over all unordered pairs of `a_p | a_q`: `sum_i 2^i * (C(n,2) - C(c0, 2))`.
- Number of subarrays with bit i set in the OR: `total - (subarrays made only of elements with bit i = 0)`.
- Number of subarrays with AND having bit i set: subarrays fully inside runs of elements with bit i = 1, i.e. `sum run*(run+1)/2`.
- XOR of all pairwise XORs, XOR of all subarray XORs, etc: parity arguments per bit (a bit is in the answer iff it occurs an odd number of times).
- XOR of all subarray XORs: element `a[i]` is included in `(i+1)*(n-i)` subarrays, so it contributes iff that count is odd.

---

## 8. Monotonic behaviour of AND / OR (subarrays)

- Extending a subarray to the right: AND can only decrease (clears bits), OR can only increase (sets bits).
- A fixed right end has at most `~log2(maxValue)` (<= 32 or 64) distinct AND values and at most as many distinct OR values over all left ends. So you can keep a small list of `(value, count)` pairs while sweeping: O(n log V) for "count subarrays with AND/OR = k / >= k / <= k".
- Bitwise AND of a range `[l, r]` of integers = common binary prefix of l and r, followed by zeros: `while l != r: l >>= 1; r >>= 1; shift++; return l << shift`.
- Bitwise OR of a range `[l, r]` = common prefix of l and r followed by ones (the first differing bit and all below become 1).
- XOR can NOT be handled with monotonicity. Use prefix XOR instead.
- `AND(a1..an) <= min`, `OR(a1..an) >= max`.
- Gcd/AND/OR share the same "few distinct values per right endpoint" structure.

---

## 9. Masks and subsets

- All subsets of `{0..n-1}`: `for mask in 0 .. (1<<n) - 1`.
- Check element i in mask: `mask >> i & 1`.
- Enumerate submasks of `m` (including m, excluding 0 at the end of loop): `for (s = m; s; s = (s-1) & m)`, then handle `s = 0` separately. Total over all masks: `3^n`.
- Enumerate supersets of `m` in n bits: `for (s = m; s < (1<<n); s = (s+1) | m)`.
- Complement within n bits: `full ^ mask` where `full = (1<<n)-1`.
- Next permutation with the same popcount (Gosper's hack):

```txt
c = x & -x
r = x + c
x = (((r ^ x) >> 2) / c) | r
```

Iterates all k-element subsets in increasing order.

- Sum over subsets (SOS DP / zeta transform):

```txt
for i in range(n):
    for mask in range(1 << n):
        if mask >> i & 1:
            f[mask] += f[mask ^ (1 << i)]
```

Gives `F[mask] = sum of f[sub] for sub subset of mask` in O(n 2^n). Superset sums: iterate with the bit unset and add `f[mask | 1<<i]`.

- Subset-sum Mobius inverse: same loop with `-=`.
- XOR convolution: Fast Walsh-Hadamard transform. AND/OR convolution: SOS (zeta) transforms.
- Bitmask DP (TSP, assignment, partition problems): state = set of used items, transition = add one item (`mask | 1<<j`).
- Number of submasks of m = `2^popcount(m)`.

---

## 10. Sign / branchless tricks

- Absolute value (32-bit): `m = x >> 31; abs = (x ^ m) - m`.
- Sign: `(x >> 31) | (-x >>> 31)` gives -1, 0, 1.
- Are x and y of opposite signs: `(x ^ y) < 0`.
- Min: `y ^ ((x ^ y) & -(x < y))`. Max: `x ^ ((x ^ y) & -(x < y))`.
- Conditional set/clear: `x = (x & ~m) | (-f & m)` sets bits of m if f = 1 else clears them.
- Conditional negate: `(x ^ -f) + f`.
- Swap bits i and j of x: `if ((x>>i ^ x>>j) & 1) x ^= (1<<i) | (1<<j)`.
- Reverse bits of a word: swap halves, then quarters, ... (log steps); or use lookup table.
- Parity of a word: `x ^= x >> 32; x ^= x >> 16; x ^= x >> 8; x ^= x >> 4; x ^= x >> 2; x ^= x >> 1; return x & 1`.
- SWAR popcount (32-bit):

```txt
x = x - ((x >> 1) & 0x55555555)
x = (x & 0x33333333) + ((x >> 2) & 0x33333333)
x = (x + (x >> 4)) & 0x0F0F0F0F
return (x * 0x01010101) >> 24
```

- Rotate left by k (w-bit): `(x << k) | (x >> (w - k))`.
- Interleave bits (Morton order) via magic masks; useful for 2D -> 1D keys.

---

## 11. Classic problem patterns

| Problem                                             | Idea                                                                                 |
| --------------------------------------------------- | ------------------------------------------------------------------------------------ |
| Single number (all others twice)                    | XOR everything                                                                       |
| Two singles                                         | XOR all = `a ^ b`; take lowest set bit `d` of it, split array by `d`, XOR each group |
| Single number (others three times)                  | Count bit i mod 3 per bit, or two-state machine `ones, twos`                         |
| Missing number in `0..n`                            | `XOR(0..n) ^ XOR(array)` (use `f(n)` from 4.1) or sum                                |
| Find duplicate and missing                          | XOR + split by a differing bit                                                       |
| Max XOR of two numbers                              | Binary trie from MSB, or greedy build answer bit by bit with a set of prefixes       |
| Max XOR with a query value / range queries          | Persistent trie or offline trie                                                      |
| Min XOR pair                                        | Sort; the minimum is attained by an adjacent pair                                    |
| Number of pairs with `a^b = k`                      | Hashmap of seen values, look up `a ^ k`                                              |
| Subarray XOR = k                                    | Prefix XOR + hashmap                                                                 |
| Longest subarray with AND > 0                       | Per bit, longest run with that bit set; take max                                     |
| Range AND of `[l, r]`                               | Common prefix                                                                        |
| Sum of Hamming distances                            | Per-bit `c1 * c0`                                                                    |
| Count set bits for 0..n                             | `dp[i] = dp[i >> 1] + (i & 1)` or `dp[i] = dp[i & (i-1)] + 1`                        |
| Power set generation                                | Iterate masks 0..2^n - 1                                                             |
| Gray code sequence                                  | `i ^ (i >> 1)`                                                                       |
| Reverse bits / swap nibbles / pack flags            | Shifts and masks                                                                     |
| Bitset DP (knapsack feasibility)                    | `dp \|= dp << w`                                                                     |
| Maximise sum of squares with `(x,y) -> (x&y, x\|y)` | Spread lemma (Section 6): pack bits greedily                                         |
| Make all equal with XOR operations                  | Think in terms of per-bit parity and total XOR                                       |
| Nim and game theory                                 | Position is losing iff XOR of pile sizes is 0                                        |

---

## 12. Quick proofs / intuition to remember

1. **Per-bit independence**: AND, OR, XOR act on each bit separately. Many "advanced" results are just a per-bit argument followed by summing `2^i * (count for bit i)`.
2. **Carry decomposition**: `x + y = (x ^ y) + 2(x & y)`. Repeat until the carry is 0 gives the adder loop.
3. **Conservation**: `(x|y) + (x&y) = x + y`, `popcount` is also conserved by `(x, y) -> (x|y, x&y)`. Only the distribution changes.
4. **Parity cancellation**: XOR over a multiset keeps bits that appear an odd number of times.
5. **Aligned blocks**: a block of size `2^k` starting at a multiple of `2^k` has all low k bits balanced, so XOR depends only on k and the (even) repetition of the prefix.
6. **Lowest set bit**: `x - 1` flips the lowest set bit and everything below it; so `x & (x-1)` clears it, `x ^ (x-1)` masks it, `x | (x-1)` fills below it.
7. **Highest differing bit decides order**: compare two numbers by looking at the top bit of `x ^ y`.

---

## 13. Personal additions

(Add new identities and problem notes here as you find them.)

-
-
