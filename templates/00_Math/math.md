# Math Cheat Sheet for DSA

Notation: `a | b` means a divides b. `v_p(n)` is the exponent of prime p in n. `d(n)` number of divisors, `sigma(n)` sum of divisors, `phi` Euler totient, `mu` Mobius. `[P]` is 1 if P true else 0. Companion to the bits sheet. Sieve and factorial/nCr code are kept in separate files, so only the logic around them is here.

---

## 0. Pitfalls (read once)

- Overflow: int64 max is about 9.22e18. Product of two numbers up to 1e10 already overflows. Use `__int128` or `1LL * a * b % m`.
- lcm: write `a / gcd(a,b) * b`, never `a * b / gcd`. Check against a limit before multiplying again (important in inc/exc).
- Negative mod: C++ `%` can be negative. Use `((a % m) + m) % m`.
- Division under mod: multiply by the modular inverse, and it only exists when gcd(den, m) = 1. If m is prime, den % m != 0 is enough.
- Floor division of negatives rounds toward zero in C++. For floor use `a / b - ((a % b != 0) && ((a < 0) != (b < 0)))`.
- ceil(a/b) for positive ints: `(a + b - 1) / b`.
- `sqrt()` on doubles is inexact. Fix up: `r = sqrtl(n); while (r*r > n) r--; while ((r+1)*(r+1) <= n) r++;`.
- `pow()` is a double function. Never use it for exact integer powers.
- Limits: 20! fits in int64 (2432902008176640000), 21! does not. Fibonacci F(92) = 7540113804746346429 is the last that fits in int64. 2^62 = 4.6e18.
- Common primes: 1e9+7, 998244353 = 119 \* 2^23 + 1 (NTT friendly, primitive root 3), 1e9+9.

---

## 1. GCD and LCM

- `gcd(a,b) = gcd(b, a % b)`, `gcd(a,0) = a`. O(log) steps (worst case consecutive Fibonacci). C++17 has `std::gcd`, `std::lcm`, GCC has `__gcd`.
- `gcd(a,b) * lcm(a,b) = a * b` (only for two numbers).
- `gcd(a,b) = gcd(a, b - a) = gcd(a, b + k*a)`. So `gcd(n, n+1) = 1`, `gcd(a, b) | (a - b)` and `| (a + b)`.
- `gcd(ka, kb) = k * gcd(a,b)`. If `gcd(a,b) = 1` then `gcd(a, bc) = gcd(a, c)`.
- Per prime: `v_p(gcd) = min(v_p(a), v_p(b))`, `v_p(lcm) = max(...)`. This min/max view makes most gcd/lcm proofs trivial.
- `gcd(a^m - 1, a^n - 1) = a^gcd(m,n) - 1`. `gcd(F_m, F_n) = F_gcd(m,n)`.
- gcd and lcm are associative, so gcd of a range can be kept in a sparse table or segment tree.
- Few distinct values: for a fixed right end, the gcd over all left ends takes at most about log2(V) distinct values (each change at least halves it). Same idea as AND/OR. Keep a list of `(gcd, count)` while sweeping: O(n log V) for counting subarrays with gcd = k or gcd > 1.
- If `g = gcd(whole array)`, divide everything by g and the problem often becomes gcd = 1.
- Prefix gcd and suffix gcd arrays give gcd of array with one element removed in O(1).
- Max possible gcd of a pair in an array: for each d from max down to 1, count multiples of d present (harmonic loop). First d with count >= 2 is the answer.

```cpp
ll extgcd(ll a, ll b, ll &x, ll &y) { // a*x + b*y = gcd
    if (!b) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);
    x = y1; y = x1 - (a / b) * y1;
    return g;
}
```

---

## 2. Modular arithmetic

- `(a+b)%m`, `(a-b)%m`, `(a*b)%m` can be done piecewise. Division cannot.
- Fast power: `pw(a, e, m)` in O(log e). Use `a %= m` first.
- Inverse of a mod m (gcd(a,m) = 1):
  - m prime: `a^(m-2) mod m` (Fermat).
  - general m: extgcd, `x mod m` where `a*x + m*y = 1`.
  - all inverses 1..n in O(n): `inv[1] = 1; inv[i] = (m - (m / i) * inv[m % i] % m) % m` (m prime).
- **Fermat**: p prime, p does not divide a: `a^(p-1) = 1 (mod p)`. So exponents can be reduced mod p-1.
- **Euler**: gcd(a,m) = 1: `a^phi(m) = 1 (mod m)`.
- **Generalized Euler (huge exponents)**: if `e >= log2(m)` then `a^e = a^((e mod phi(m)) + phi(m)) (mod m)`, no coprimality needed. For towers `a^b^c` use this recursively.
- **Wilson**: p prime iff `(p-1)! = -1 (mod p)`.
- **Chinese Remainder Theorem**: x = a1 (mod m1), x = a2 (mod m2) with coprime moduli has a unique solution mod m1\*m2. Non coprime: solvable iff `a1 = a2 (mod gcd(m1,m2))`, result modulo lcm. Merge pairwise with extgcd.
- **Few distinct values**: for a fixed right end, the gcd over all left ends takes at most
  floor(log2(V)) + 1 distinct values. As we extend left, gcd can only stay the same
  or become a proper divisor; every strict change g -> g' has g' <= g/2. So keep (gcd, count) groups while sweeping: O(n log V). Same idea as AND/OR. [https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/G](https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/G)
- **Euler's criterion**: p odd prime, `a^((p-1)/2)` is 1 if a is a quadratic residue, -1 if not.
- Fractions mod p: `p/q` becomes `p * q^(-1) mod M`. Used in probability / expected value answers.
- Order of a mod m divides phi(m). Primitive root exists iff m is 1, 2, 4, p^k or 2p^k.
- Cycle in `a^k mod m`: preperiod plus period, so for huge k simulate until repeat.
- Sum of geometric series mod m: `1 + r + ... + r^(n-1)` by divide and conquer (`S(2k) = S(k) * (1 + r^k)`), because `r - 1` may not be invertible.

```cpp
ll pw(ll a, ll e, ll m) {
    ll r = 1 % m; a %= m;
    for (; e > 0; e >>= 1, a = (__int128)a * a % m)
        if (e & 1) r = (__int128)r * a % m;
    return r;
}
```

---

## 3. Primes

### 3.1 Facts

- Infinitely many primes. Every prime > 3 is of the form `6k +- 1` (converse false).
- Smallest prime factor of a composite n is at most sqrt(n). So trial division up to sqrt(n) is enough, and after dividing out all small primes, a leftover > 1 is prime.
- A number n <= 1e18 has at most 15 distinct prime factors (product of first 15 primes is about 6.1e17). n <= 1e9 has at most 9. n <= 1e6 at most 7.
- Prime counting `pi(x)` is about `x / ln x`: pi(1e3) = 168, pi(1e4) = 1229, pi(1e5) = 9592, pi(1e6) = 78498, pi(1e7) = 664579, pi(1e8) = 5761455, pi(1e9) = 50847534.
- Bertrand: for n >= 1 there is a prime in (n, 2n\]. Prime gaps below 1e18 are under 1500, so searching the next prime is fast.
- Goldbach (every even > 2 is a sum of two primes) is verified up to 4e18. Every odd number > 5 is a sum of three primes (proved). Twin prime conjecture is open.
- Dirichlet: `a + k*d` has infinitely many primes if gcd(a,d) = 1.
- p | ab implies p | a or p | b. False for composites.
- Sum of reciprocals of primes up to n is about ln ln n. This is why sieve of Eratosthenes is O(n log log n).
- Perfect numbers (even): `2^(p-1) * (2^p - 1)` where `2^p - 1` is prime.
- Fermat's theorem on sums of two squares: n is a sum of two squares iff every prime = 3 mod 4 has an even exponent in n. Lagrange: every n is a sum of four squares. Legendre three squares: n is a sum of three squares unless n = 4^a (8b + 7).

### 3.2 Factorization toolbox

| n up to                      | Method                                          |
| ---------------------------- | ----------------------------------------------- |
| 1e7 (many queries)           | smallest prime factor sieve, factor in O(log n) |
| 1e12                         | trial division by primes up to 1e6, O(sqrt n)   |
| 1e18                         | Miller-Rabin to test, Pollard rho to split      |
| range \[L, R\], R up to 1e12 | segmented sieve with primes up to sqrt(R)       |

- Deterministic Miller-Rabin for 64-bit: bases `{2, 325, 9375, 28178, 450775, 9780504, 1795265022}`, or the first 12 primes `{2,3,5,7,11,13,17,19,23,29,31,37}` (valid below 3.3e24). Needs mulmod via `__int128`.
- Radical `rad(n)` is the product of distinct primes of n. Inc/exc and Mobius only need the distinct primes.

```cpp
bool isPrimeMR(ull n) {
    if (n < 2) return false;
    for (ull p : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if (n % p == 0) return n == p;
    }
    ull d = n - 1; int s = 0;
    while ((d & 1) == 0) d >>= 1, s++;
    for (ull a : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        ull x = pw(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (int i = 1; i < s && comp; i++) {
            x = (__int128)x * x % n;
            if (x == n - 1) comp = false;
        }
        if (comp) return false;
    }
    return true;
}
```

### 3.3 Legendre and factorial facts

- `v_p(n!) = floor(n/p) + floor(n/p^2) + floor(n/p^3) + ...`. Trailing zeros of n! = `v_5(n!)`.
- Exponent of p in `C(n,k)` = number of carries when adding k and n-k in base p (Kummer). So `C(n,k)` is odd iff `(k & n) == k`.
- Product of k consecutive integers is divisible by k!.
- `n!` mod p is 0 for n >= p. Combine with Lucas for nCr mod small prime p: `C(n,k) = product of C(n_i, k_i)` over base-p digits.

### 3.4 A prime between m and 2m, and the Jacobsthal bound

**Bertrand's postulate**: for every integer m >= 1 there is a prime p with `m < p <= 2m` (strictly inside, `m < p < 2m`, for m > 1). Consequences:

- The next prime after n is below 2n, so a sieve up to `2 * max` always contains a prime larger than every value. Handy when you need a modulus or a fresh prime bigger than n.
- Sharper: for n >= 25 there is a prime in `(n, 1.2n)` (Nagura). Primes have average gap about `ln n` (about 41 near 1e18), so scanning upward from n with a primality test finds one in a few dozen steps.
- For a pair `x < y` with `y >= 2x`, a prime in `(x, y)` exists, and it is coprime to both unless it divides one of them (it cannot divide x since it exceeds x, but it may divide y, so test it).

**Jacobsthal function** `h(n)`: the smallest k such that every k consecutive integers contain at least one number coprime to n. It depends on n only through its distinct primes, and the worst case is a primorial `2*3*5*...*p_k`:

| distinct primes k | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 11  | 12  | 13  | 14  | 15  |
| ----------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| max h             | 2   | 4   | 6   | 10  | 14  | 22  | 26  | 34  | 40  | 46  | 58  | 66  | 74  | 90  | 100 |

- Use: given `x < y`, to find `v` with `gcd(v, x) = 1` and `gcd(v, y) = 1`, scan candidates `v = L, L+1, L+2, ...` and test `gcd(v, x) == 1 && gcd(v, y) == 1`. A hit is guaranteed within `h(rad(x * y))` steps. If `x * y <= 1e18` then `x * y` has at most 15 distinct primes, so at most 100 steps. Typically it is under 10.
- Same bound for any number of constraints: a number coprime to a set of numbers with at most 15 distinct primes in total exists in every window of 100 consecutive integers.
- If you need `v` strictly between x and y, the window `(x, y)` must be at least `h` long (so `y - x >= 100` is always enough for products up to 1e18). Otherwise `v` may not exist for small gaps (x = 2, y = 3 has nothing strictly between), so brute force those.
- Also remember: `v = 1` is coprime to everything, and consecutive integers `n, n+1` are always coprime, so for a single x a neighbour `x + 1` or `x - 1` works immediately.
- Growth of `h` is slow: it is roughly bounded by `2^k` for k distinct primes but in practice about `k^2 * log k`, which is why brute scanning is safe.

```cpp
// find v >= L with gcd(v, x) == 1 and gcd(v, y) == 1
// terminates in at most h(rad(x*y)) <= 100 steps when x*y <= 1e18
ll findCoprimeToBoth(ll L, ll x, ll y) {
    for (ll v = L; ; v++)
        if (std::gcd(v, x) == 1 && std::gcd(v, y) == 1) return v;
}
```

---

## 4. Divisors

With `n = p1^e1 * p2^e2 * ... * pk^ek`:

- Count: `d(n) = (e1+1)(e2+1)...(ek+1)`.
- Sum: `sigma(n) = product of (p^(e+1) - 1) / (p - 1)`.
- Product of all divisors: `n^(d(n)/2)`.
- Divisor pairs: if `a | n` then `n/a | n`. So enumerate up to sqrt(n) and take both. Always check `i == n / i` to avoid double counting.
- `d(n)` is odd iff n is a perfect square. This is the classic locker/toggle problem.
- Divisors of n form a lattice; `d` and `sigma` are multiplicative: `f(ab) = f(a) f(b)` when gcd(a,b) = 1.
- Number of divisors of n that are perfect squares: `product of (floor(e/2) + 1)`.
- Number of ordered pairs (a, b) with `a*b = n`: `d(n)`. With `lcm(a,b) = n`: `product of (2e+1)`.
- Maximum d(n) (highly composite numbers):

| n up to | max d(n) | achieved at        |
| ------- | -------- | ------------------ |
| 1e3     | 32       | 840                |
| 1e6     | 240      | 720720             |
| 1e9     | 1344     | 735134400          |
| 1e12    | 6720     | 963761198400       |
| 1e18    | 103680   | 897612484786617600 |

Rule of thumb: `d(n) <= 2*sqrt(n)`, and in practice `d(n)` is around `n^(1/3)` at worst for contest ranges. So enumerating all divisors of one number is cheap, enumerating all subsets of its divisors is not.

- Sieve style counting: `sum over i<=n of d(i) = sum over k<=n of floor(n/k)`, about `n ln n`. Precompute divisor lists for all numbers up to N in O(N log N) by looping `for d: for m = d; m <= N; m += d`.
- Harmonic bound: any loop `for i in 1..n: for j = i; j <= n; j += i` is O(n log n). Use it for multiples/divisor counting problems.
- Sum of divisors over a range: `sum_{i<=n} sigma(i) = sum_{d<=n} d * floor(n/d)`.

### 4.1 floor(n / i) blocks

`floor(n/i)` takes at most `2*sqrt(n)` distinct values. Group indices with equal quotient:

```cpp
for (ll l = 1, r; l <= n; l = r + 1) {
    ll q = n / l;
    r = n / q;            // floor(n/i) == q for all i in [l, r]
    // use q * (r - l + 1), or prefix(r) - prefix(l-1) times q
}
```

- Identities: `floor(floor(n/a)/b) = floor(n/(ab))`. `ceil(n/k) = floor((n-1)/k) + 1`.
- Number of multiples of d in `[l, r]`: `r/d - (l-1)/d`.
- Number of integers in \[1,n\] whose smallest divisor structure... best handled by the block trick or by the sieve.
- Sum of `i * floor(n/i)` over i: use block trick with arithmetic series for `sum of i` over `[l, r]`.

---

## 5. Inclusion-Exclusion (the divisor flavour)

General form for sets `A1..Ak`:

`|A1 u ... u Ak| = sum over non-empty subsets S of (-1)^(|S|+1) * |intersection of Ai in S|`

For divisibility, `Ai = {x <= n : ai | x}` and the intersection of a subset is the multiples of `lcm(S)`, whose size is `floor(n / lcm(S))`.

### 5.1 Recipes

1. **Count x in \[1, n\] divisible by at least one of a1..ak**: iterate subsets, add `+- n / lcm`. 2^k subsets, k up to about 20. Prune when lcm exceeds n (term is 0, and so is every superset).
2. **Count x in \[1, n\] divisible by none (complement)**: `n - answer above`. Equivalent to counting numbers coprime to a set of primes.
3. **Count x in \[1, n\] coprime to m**: take distinct primes p1..pk of m, then `sum over subsets of (-1)^|S| * floor(n / prod(S))`. At most 9 primes for m <= 1e9 and 15 for m <= 1e18, so at most 2^15 subsets. Equals `sum over d | rad(m) of mu(d) * floor(n/d)`.
4. **Range \[L, R\]**: `f(R) - f(L-1)`.
5. **k-th number coprime to m**: binary search on x with the count function above. Or use periodicity: pattern repeats every m, and there are `phi(m)` coprimes per period.
6. **Exactly j of the conditions hold**: use the generalized formula `E_j = sum over t >= j of (-1)^(t-j) * C(t, j) * S_t` where `S_t` is the sum over all t-subsets of intersection sizes.
7. **Complement with forbidden positions**: derangements `D(n) = sum over i of (-1)^i * n!/i!`, recurrence `D(n) = (n-1)(D(n-1) + D(n-2))`, values 1, 0, 1, 2, 9, 44, 265, 1854.
8. **Surjections / each of k boxes non-empty**: `sum over i of (-1)^i * C(k,i) * (k-i)^n`.
9. **Bounded stars and bars**: solutions of `x1 + .. + xk = n` with `xi <= ci`: `sum over subsets S of (-1)^|S| * C(n - sum_{i in S}(ci + 1) + k - 1, k - 1)` (terms with negative top are 0).
10. **Count pairs (i, j) with gcd = 1** (or any gcd condition): see Mobius in section 6, which is inclusion-exclusion over divisors done smartly.

```cpp
// count x in [1, n] divisible by at least one of a[0..k-1]
ll n; vector<ll> a; ll res = 0;
void go(int i, ll l, int cnt) {
    if (i == (int)a.size()) {
        if (cnt) res += (cnt & 1 ? 1 : -1) * (n / l);
        return;
    }
    go(i + 1, l, cnt);                       // skip a[i]
    ll g = std::gcd(l, a[i]);
    ll nl = l / g * a[i];                    // safe lcm order
    if (nl <= n) go(i + 1, nl, cnt + 1);     // prune: beyond n contributes 0
}
// call go(0, 1, 0)

// count x in [1, n] coprime to m, using its distinct primes ps
ll coprimeCount(ll n, const vector<ll>& ps) {
    ll r = 0; int k = ps.size();
    for (int mask = 0; mask < (1 << k); mask++) {
        ll d = 1;
        for (int i = 0; i < k; i++) if (mask >> i & 1) d *= ps[i];
        r += (__builtin_popcount(mask) & 1 ? -1 : 1) * (n / d);
    }
    return r;
}
```

### 5.2 Exact-gcd counting (inc/exc done top-down)

For values up to M, to count pairs with `gcd = g` exactly: let `c(g)` be how many array elements are multiples of g. Then `all(g) = C(c(g), 2)` counts pairs whose gcd is a multiple of g, and

`exact(g) = all(g) - sum over k >= 2 of exact(k*g)`

Process g from M down to 1. O(M log M). Same pattern works for triples, quadruples, or the sum of gcds.

```cpp
// cnt[v] = frequency of v, values <= M
vector<ll> exact(M + 1);
for (int g = M; g >= 1; g--) {
    ll c = 0;
    for (int m = g; m <= M; m += g) c += cnt[m];
    exact[g] = c * (c - 1) / 2;
    for (int m = 2 * g; m <= M; m += g) exact[g] -= exact[m];
}
// exact[1] = number of coprime pairs
```

---

## 6. Euler phi and Mobius

### 6.1 Euler totient

- `phi(n) = n * product over distinct p | n of (1 - 1/p)`. Compute as `res = n; for each prime p: res -= res / p`.
- `phi(p^k) = p^k - p^(k-1)`. Multiplicative. `phi(n)` is even for n >= 3.
- `sum over d | n of phi(d) = n`.
- Sum of integers in \[1,n\] coprime to n (n > 1): `n * phi(n) / 2`. Count of them is `phi(n)`, and they pair up as `x, n - x`.
- `phi(n)` = number of generators of the cyclic group Z_n additive = number of fractions `k/n` in lowest terms for 1 <= k <= n.
- `sum_{i=1}^{n} gcd(i, n) = sum over d | n of d * phi(n/d)`.
- Number of reduced fractions with denominator <= n (Farey length): `1 + sum_{k=1}^n phi(k)`.
- Sieve for phi up to N: standard `phi[i] = i`, then for each prime p, `for m = p; m <= N; m += p: phi[m] -= phi[m] / p`.

### 6.2 Mobius

- `mu(1) = 1`, `mu(n) = 0` if some prime squared divides n, else `(-1)^(number of primes)`.
- Key property: `sum over d | n of mu(d) = [n == 1]`. So `[gcd(a,b) == 1] = sum over d | gcd(a,b) of mu(d)`.
- Coprime pairs in `[1,n]^2`: `sum over d of mu(d) * floor(n/d)^2`. Pairs with `gcd = g` exactly: same with `n/g`.
- Count of x in \[1, n\] coprime to m is `sum over d | m of mu(d) * floor(n/d)`, matching the inc/exc recipe (only squarefree d with primes of m survive).
- Mobius inversion: `F(n) = sum over d | n of f(d)` implies `f(n) = sum over d | n of mu(n/d) F(d)`. Often the same as exact-gcd counting from section 5.2.
- Number of squarefree numbers up to n: `sum over d <= sqrt(n) of mu(d) * floor(n / d^2)`.
- Dirichlet convolution `(f * g)(n) = sum over d | n of f(d) g(n/d)`. Identities: `1 * mu = e`, `phi * 1 = id`, `1 * 1 = d(n)`, `id * 1 = sigma`. Multiplicative functions can be sieved in linear time with smallest prime factor.

---

## 7. Combinatorics (math side)

- Pascal: `C(n,k) = C(n-1,k-1) + C(n-1,k)`. Symmetry: `C(n,k) = C(n,n-k)`. `k * C(n,k) = n * C(n-1,k-1)`.
- Row sum `2^n`. Alternating row sum 0. `sum of C(n,k)^2 = C(2n, n)`.
- Hockey stick: `sum_{i=r}^{n} C(i, r) = C(n+1, r+1)`.
- Vandermonde: `sum_i C(a, i) C(b, k-i) = C(a+b, k)`.
- Stars and bars: non-negative solutions of `x1 + ... + xk = n`: `C(n + k - 1, k - 1)`. Positive solutions: `C(n - 1, k - 1)`.
- Lattice paths from (0,0) to (a,b) with right/up steps: `C(a+b, a)`. Paths that never cross the diagonal: Catalan.
- Catalan `Cat(n) = C(2n, n) / (n+1)`: 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796. Counts balanced bracket strings, binary trees with n nodes, triangulations of an (n+2)-gon, Dyck paths. Recurrence `Cat(n+1) = sum of Cat(i) Cat(n-i)`.
- Multinomial: `n! / (k1! k2! ... km!)`.
- Circular arrangements of n distinct items: `(n-1)!`.
- Pigeonhole: n+1 items in n boxes forces a repeat. Among any n integers there is a non-empty subset (even a contiguous block) whose sum is divisible by n.
- Burnside: number of distinct objects under a group = average number of arrangements fixed by each group element.
- Linearity of expectation: `E[X+Y] = E[X] + E[Y]` always, even if dependent. Count expected value as sum over indicator variables. Coupon collector: `n * H_n` where `H_n = 1 + 1/2 + ... + 1/n`. Expected trials for success probability p: `1/p`.

---

## 8. Sums and series

- `1 + 2 + ... + n = n(n+1)/2`. `1^2 + ... + n^2 = n(n+1)(2n+1)/6`. `1^3 + ... + n^3 = (n(n+1)/2)^2`.
- Arithmetic series: `(first + last) * count / 2`.
- Geometric: `1 + r + ... + r^(n-1) = (r^n - 1) / (r - 1)`. `1 + 2 + 4 + ... + 2^(k-1) = 2^k - 1`.
- Sum of first n odd numbers = n^2. Sum of first n even = n(n+1).
- Division of x by `n(n+1)/2`: when taking mod, divide the even factor first or multiply by the inverse of 2.
- Fibonacci: `F(n+m) = F(n) F(m+1) + F(n-1) F(m)`. Fast doubling: `F(2k) = F(k) * (2 F(k+1) - F(k))`, `F(2k+1) = F(k)^2 + F(k+1)^2`. Sum `F(1) + ... + F(n) = F(n+2) - 1`. Cassini: `F(n+1) F(n-1) - F(n)^2 = (-1)^n`. Pisano period mod m is at most 6m.
- Zeckendorf: every positive integer is uniquely a sum of non-consecutive Fibonacci numbers.
- Harmonic: `H_n` is about `ln n + 0.5772`. Sums like `sum floor(n/i)` are about `n ln n`.
- Linear recurrences of order k: matrix exponentiation in `O(k^3 log n)`.
- Digit sums / digit counts: number of digits of n is `floor(log10 n) + 1`. Digit sum is congruent to n mod 9 (and mod 3). Alternating digit sum is congruent to n mod 11.
- `floor_sum(n, m, a, b) = sum over i in [0, n) of floor((a*i + b) / m)` is computable in O(log m) with a Euclid-like recursion (AtCoder Library). Use it when floors of linear functions are summed.

---

## 9. Theorems and facts worth remembering

- **Bezout**: `a*x + b*y = gcd(a,b)` has integer solutions. `a*x + b*y = c` is solvable iff `gcd(a,b) | c`. With one solution `(x0, y0)`, all solutions are `(x0 + t*b/g, y0 - t*a/g)`.
- **Frobenius / Chicken McNugget**: for coprime a, b, the largest amount not representable as `a*x + b*y` with `x, y >= 0` is `a*b - a - b`, and there are `(a-1)(b-1)/2` unrepresentable positive amounts.
- **Lifting the exponent (LTE)**: p odd prime, `p | x - y`, p divides neither x nor y: `v_p(x^n - y^n) = v_p(x - y) + v_p(n)`. For p = 2 and even n: `v_2(x^n - y^n) = v_2(x-y) + v_2(x+y) + v_2(n) - 1`.
- **Pythagorean triples**: `(m^2 - n^2, 2mn, m^2 + n^2)` for m > n > 0, coprime, opposite parity gives all primitive triples. Multiply by k for the rest.
- **Pick's theorem** (lattice polygon): `Area = I + B/2 - 1`. Lattice points on a segment from (0,0) to (dx, dy): `gcd(|dx|, |dy|) + 1`.
- **Triangle inequality**: a, b, c form a triangle iff the largest is strictly less than the sum of the other two.
- **AM-GM**: `(a + b)/2 >= sqrt(ab)`. Sum fixed implies product is maximised when values are equal. Product fixed implies sum is minimised when equal. Used for splitting n into parts: use 3s (then 2s) to maximise the product.
- **Cauchy-Schwarz / rearrangement**: pairing sorted with sorted maximises a sum of products; sorted with reverse-sorted minimises it.
- **Median minimises sum of absolute deviations** `sum |a_i - x|`. **Mean minimises sum of squares**.
- **Parity facts**: sum of n consecutive integers is divisible by n if n is odd. `n^2 mod 4` is 0 or 1. `n^2 mod 8` is 0, 1 or 4. A cube mod 9 is 0, 1 or 8. Perfect squares end in 0,1,4,5,6,9.
- **Sum of two numbers with given sum S and product P** are roots of `t^2 - S t + P = 0`. Discriminant must be a perfect square.
- **Divisibility by number of ones**: `(10^k - 1)/9` repunits; gcd of repunits `R_a, R_b` is `R_gcd(a,b)`.
- **Josephus (k = 2)**: `J(n) = 2 * (n - 2^floor(log2 n)) + 1`. Rotate the binary representation of n left by one.
- **Nim**: a position is losing iff the XOR of the pile sizes is 0. Generally use Sprague-Grundy: mex of reachable Grundy values, XOR across independent games. Subtraction games are periodic.
- **Matrix tree theorem**: spanning trees = any cofactor of the Laplacian.
- **Cayley**: number of labeled trees on n vertices is `n^(n-2)`.
- **Handshake**: sum of degrees = 2E. **Euler tour**: connected graph has Euler circuit iff all degrees are even.

---

## 10. Quick proofs and intuition

1. **Per prime independence**: gcd, lcm, divisibility, d, sigma all act on each prime exponent separately (min, max, compare, product over primes). Most number theory facts are a per-prime argument.
2. **Counting with divisibility**: the number of x <= n with `d | x` is `floor(n/d)`. Everything in inc/exc and Mobius is built from this single fact.
3. **Sqrt split**: in `floor(n/i)` or divisor enumeration, one of `i` and `n/i` is at most sqrt(n). Handle small i directly, large values by their quotient.
4. **Harmonic sums**: iterating multiples of every d costs `n/d`, total `n ln n`. Free to use for N up to 1e6-1e7.
5. **Complement is often easier**: counting numbers with property X is hard but counting those without is a clean inc/exc.
6. **Mod to equivalence classes**: if the condition depends on `x mod m` only, count per residue class (period m) and scale by n / m, plus a remainder.
7. **Few primes**: any n up to 1e18 has at most 15 distinct primes, so 2^15 subset enumeration over primes of one number is cheap.
8. **Pairing trick**: `x` and `n - x` both coprime to n, or `d` and `n/d` both divisors. Sums over symmetric structures simplify to half the size times a pair sum.

---

## 11. Classic problem patterns

| Problem                                                    | Idea                                                                 |
| ---------------------------------------------------------- | -------------------------------------------------------------------- |
| Count numbers in \[1,n\] divisible by any of given numbers | Inc/exc over subsets with lcm and pruning (5.1)                      |
| Count numbers in \[L,R\] coprime to m                      | Inc/exc over distinct primes of m, `f(R) - f(L-1)`                   |
| k-th number not divisible by any of given primes           | Binary search with the count function                                |
| Number of pairs with gcd = 1                               | Mobius or exact-gcd sieve from top down (5.2, 6.2)                   |
| Sum of gcd(i, j) over all pairs up to n                    | `sum of phi` or Mobius with floor blocks                             |
| Sum of gcd(i, n) for i = 1..n                              | \`sum over d                                                         |
| Max gcd of any pair in an array                            | Loop d downward counting multiples present                           |
| Count / list divisors of n                                 | Loop to sqrt(n), or from prime factorization recursion               |
| Divisors of all numbers up to N                            | Harmonic sieve, `for d: for m += d`                                  |
| Smallest number with exactly k divisors                    | Exponents sorted non-increasing on the first primes, DFS             |
| Count numbers <= n with exactly k divisors                 | Prime exponent DFS, sieve d(n) if n small                            |
| Which of n lamps are on after toggles                      | Perfect squares (d odd)                                              |
| Number of trailing zeros of n!                             | `v_5(n!)` by Legendre                                                |
| n!, nCr mod prime                                          | Factorials + inverse factorials, Lucas for small p                   |
| a^b mod m with huge b                                      | Reduce with phi (generalized Euler)                                  |
| Solve `ax + by = c` / reach a target with two step sizes   | extgcd, check \`g                                                    |
| Combine congruences                                        | CRT with extgcd, handle non-coprime via gcd check                    |
| Subarray gcd / lcm queries                                 | Sparse table, or list of `(value, count)` with at most log V entries |
| Number of distinct values of floor(n/i)                    | At most 2 sqrt(n), block loop (4.1)                                  |
| Count squarefree numbers                                   | Mobius with `d^2`                                                    |
| Minimum operations to make gcd > 1                         | Look at prime factors of nearby values                               |
| Probability / expected value answers                       | Linearity, then print `p * q^(-1) mod M`                             |
| Balanced brackets / non-crossing structures                | Catalan                                                              |
| Game with piles                                            | XOR of Grundy values                                                 |

---

## 12. Constants and limits

| Item                        | Value                                            |
| --------------------------- | ------------------------------------------------ |
| int32 max                   | 2147483647 (about 2.1e9)                         |
| int64 max                   | 9223372036854775807 (about 9.2e18)               |
| uint64 max                  | about 1.8e19                                     |
| 2^10, 2^20, 2^30, 2^40      | 1024, about 1e6, about 1e9, about 1e12           |
| 2^31 - 1                    | 2147483647 is prime                              |
| Prime near 1e9              | 1000000007, 1000000009, 998244353                |
| Operations per second (C++) | about 1e8 to 5e8 simple operations               |
| n <= 20                     | 2^n or n \* 2^n bitmask                          |
| n <= 1e5 to 1e6             | O(n log n), sieve fine                           |
| n <= 1e7                    | linear sieve, O(n)                               |
| n <= 1e12                   | O(sqrt n) per number, factorize by primes to 1e6 |
| n <= 1e18                   | Miller-Rabin + Pollard rho, or math formula      |

---

## 13.&#32;
