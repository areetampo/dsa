// Prime sieves — pick whichever variant fits: sieve() for primality checks
// only; sieve_primes() when you also need the list of primes; sieve_spf()
// for fast repeated factorization via factorize()/factorize_exp().
//
// Complexity: all three sieves are O(n log log n); factorize/factorize_exp
// are O(log x) each after sieve_spf().
//
// Usage:
//   sieve(1000000);              // then: is_prime[17] -> true
//   sieve_primes(1000000);       // then: primes -> [2, 3, 5, 7, ...]
//   sieve_spf(1000000);          // then: factorize(60) -> [2, 3, 5]   (distinct primes)
//                                //       factorize_exp(60) -> [{2,2},{3,1},{5,1}]
//
// NOTE: MAXN is guarded with #ifndef so this can be safely pasted alongside
// combinatorics.cpp (which also defines MAXN) without a duplicate-definition
// error — whichever file gets pasted first "wins" and sets the shared value.
#ifndef MAXN
#define MAXN 2000005
#endif

// 1. Basic sieve — is_prime[i] = true if i is prime
//    Use when: just need primality checks up to n
vector<bool> is_prime;
void sieve(i64 n = MAXN) {
  is_prime.assign(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (i64 i = 2; i * i <= n; i++)
    if (is_prime[i])
      fo(j, i * i, n + 1, i)
      is_prime[j] = false;
}

// 2. Sieve with primes list — also collects all primes
//    Use when: you need to iterate over primes or count them
vi primes;
void sieve_primes(i64 n = MAXN) {
  is_prime.assign(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  fo(i, 2, n + 1) {
    if (is_prime[i]) {
      primes.pb(i);
      fo(j, i * i, n + 1, i)
        is_prime[j] = false;
    }
  }
}

// 3. Smallest-prime-factor sieve — spf[i] = smallest prime factor of i
//    Use when: need fast factorization of many numbers
//    Factorize x: while (x > 1) { factor = spf[x]; x /= spf[x]; }
vi spf;
void sieve_spf(i64 n = MAXN) {
  spf.resize(n + 1);
  iota(all(spf), 0); // spf[i] = i initially
  for (i64 i = 2; i * i <= n; i++)
    if (spf[i] == i) // i is prime
      fo(j, i * i, n + 1, i)
      if (spf[j] == j) spf[j] = i;
}
// Get distinct prime factors of x using spf (after sieve_spf)
vi factorize(i64 x) {
  vi factors;
  while (x > 1) {
    i64 p = spf[x];
    factors.pb(p);
    while (x % p == 0)
      x /= p;
  }
  // for (int j = 0; primes[j] * primes[j] <= x; j++) {
  //   int p = primes[j];
  //   if (x % p) continue;
  //   factors.pb(p);
  //   while (x % p == 0) x /= p;
  // }
  // if (x > 1) factors.pb(x);
  return factors;
}
// Get distinct prime factors with exponents
vector<pii> factorize_exp(i64 x) {
  vector<pii> factors;
  while (x > 1) {
    i64 p = spf[x], cnt = 0;
    while (x % p == 0) { x /= p; cnt++; }
    factors.pb({ p, cnt });
  }
  return factors;
}

/*
    ------------------------------------------------------------
    PRIME FACTORIZATION FOR 64-BIT INTEGERS
    ------------------------------------------------------------

    Finds the complete prime factorization of numbers up to 1e18.

    Uses:
        - Miller-Rabin primality test
        - Pollard Rho factorization

    Why not SPF?
        SPF works when we can precompute up to N.
        For values up to 1e18, an SPF array of size 1e18
        is impossible.

    Why not trial division?
        sqrt(1e18) = 1e9, which can be too slow.

    Idea:
        Miller-Rabin quickly checks whether a number is prime.

        If the number is composite, Pollard Rho finds a
        non-trivial factor.

        We recursively factor both pieces until everything
        is prime.

    Complexity:
        Pollard Rho has a randomized expected running time of
        roughly O(n^(1/4)) for finding a factor.

        Miller-Rabin is very fast for 64-bit integers.

        In practice, this is suitable for numbers <= 1e18
        and is much faster than trial division.

    Usage:

        using i64 = long long;

        i64 n = 360;

        vector<i64> factors = prime_factorization::factor(n);

        // factors = {2, 2, 2, 3, 3, 5}

        for (i64 p : factors)
            cout << p << ' ';

    If you want distinct prime factors only:

        vector<i64> factors = prime_factorization::factor(n);

        factors.erase(
            unique(factors.begin(), factors.end()),
            factors.end()
        );

        // {2, 3, 5}

    ------------------------------------------------------------
*/

namespace prime_factorization {

  using u64 = uint64_t;
  using u128 = __uint128_t;


  /*
      ------------------------------------------------------------
      MODULAR MULTIPLICATION
      ------------------------------------------------------------

      Computes:

          (a * b) % mod

      Normally a*b can overflow even unsigned long long.

      __uint128_t gives us enough room for the multiplication
      when a,b are 64-bit integers.
  */
  static u64 mul_mod(u64 a, u64 b, u64 mod) {
    return (u128)a * b % mod;
  }


  /*
      ------------------------------------------------------------
      MODULAR EXPONENTIATION
      ------------------------------------------------------------

      Computes:

          a^e % mod

      in O(log e).
  */
  static u64 pow_mod(u64 a, u64 e, u64 mod) {
    u64 res = 1;

    while (e) {
      if (e & 1)
        res = mul_mod(res, a, mod);

      a = mul_mod(a, a, mod);
      e >>= 1;
    }

    return res;
  }


  /*
      ------------------------------------------------------------
      MILLER-RABIN PRIMALITY TEST
      ------------------------------------------------------------

      Returns true iff n is prime.

      The bases below make Miller-Rabin deterministic for
      all unsigned 64-bit integers.
  */
  static bool is_prime(u64 n) {
    if (n < 2)
      return false;

  // Small primes first.
    for (u64 p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL,
      13ULL, 17ULL, 19ULL, 23ULL, 29ULL,
      31ULL, 37ULL}) {

      if (n % p == 0)
        return n == p;
    }

    /*
        Write:

            n - 1 = d * 2^s

        where d is odd.
    */
    u64 d = n - 1;
    int s = 0;

    while ((d & 1) == 0) {
      d >>= 1;
      ++s;
    }

    /*
        These bases are deterministic for 64-bit integers.
    */
    for (u64 a : {
      2ULL,
        325ULL,
        9375ULL,
        28178ULL,
        450775ULL,
        9780504ULL,
        1795265022ULL
    }) {

      if (a % n == 0)
        continue;

      u64 x = pow_mod(a % n, d, n);

      if (x == 1 || x == n - 1)
        continue;

      bool composite = true;

      for (int r = 1; r < s; ++r) {
        x = mul_mod(x, x, n);

        if (x == n - 1) {
          composite = false;
          break;
        }
      }

      if (composite)
        return false;
    }

    return true;
  }


  /*
      ------------------------------------------------------------
      POLLARD RHO
      ------------------------------------------------------------

      Finds some non-trivial divisor of n.

      We generate:

          f(x) = x^2 + c (mod n)

      and use two values moving at different speeds.

      If x and y become equal modulo some hidden prime factor p,
      then:

          p | (x - y)

      and therefore:

          gcd(|x-y|, n)

      can reveal p.
  */
  static u64 pollard_rho(u64 n) {

    if (n % 2 == 0)
      return 2;

    if (n % 3 == 0)
      return 3;

    static mt19937_64 rng(
      chrono::steady_clock::now().time_since_epoch().count()
    );

    while (true) {

        // Random starting point and polynomial constant.
      u64 c = uniform_int_distribution<u64>(1, n - 1)(rng);
      u64 x = uniform_int_distribution<u64>(0, n - 1)(rng);
      u64 y = x;

      u64 d = 1;

      auto f = [&] (u64 v) -> u64 {
        return (mul_mod(v, v, n) + c) % n;
      };

      /*
          Floyd's cycle detection:

              x = f(x)
              y = f(f(y))

          y moves twice as fast as x.
      */
      while (d == 1) {

        x = f(x);
        y = f(f(y));

        u64 diff = x > y ? x - y : y - x;

        d = gcd(diff, n);
      }

      /*
          d == n means this attempt failed.

          Start again with different random values.
      */
      if (d != n)
        return d;
    }
  }


  /*
      ------------------------------------------------------------
      RECURSIVE FACTORIZATION
      ------------------------------------------------------------

      If n is prime:
          put n into the answer.

      Otherwise:
          find a divisor d
          factor d
          factor n/d
  */
  static void factor_rec(u64 n, vector<u64>& factors) {

    if (n == 1)
      return;

    if (is_prime(n)) {
      factors.push_back(n);
      return;
    }

    u64 d = pollard_rho(n);

    factor_rec(d, factors);
    factor_rec(n / d, factors);
  }


  /*
      ------------------------------------------------------------
      MAIN FUNCTION
      ------------------------------------------------------------

      Returns ALL prime factors, including repetitions.

      Example:

          factor(360)

          -> {2, 2, 2, 3, 3, 5}
  */
  vector<long long> factor(long long n) {

    if (n <= 1)
      return {};

    vector<u64> factors;

    factor_rec((u64)n, factors);

    sort(factors.begin(), factors.end());

    vector<long long> ans;

    for (u64 x : factors)
      ans.push_back((long long)x);

    return ans;
  }


  /*
      ------------------------------------------------------------
      DISTINCT PRIME FACTORS
      ------------------------------------------------------------

      Example:

          distinct(360)

          -> {2, 3, 5}
  */
  vector<long long> distinct(long long n) {

    vector<long long> factors = factor(n);

    factors.erase(
      unique(factors.begin(), factors.end()),
      factors.end()
    );

    return factors;
  }


  /*
      ------------------------------------------------------------
      PRIME FACTORIZATION WITH EXPONENTS
      ------------------------------------------------------------

      Example:

          factor_count(360)

          -> {{2,3}, {3,2}, {5,1}}

          meaning:

              360 = 2^3 * 3^2 * 5
  */
  vector<pair<long long, int>> factor_count(long long n) {

    vector<long long> factors = factor(n);

    vector<pair<long long, int>> ans;

    for (long long p : factors) {

      if (ans.empty() || ans.back().first != p)
        ans.push_back({ p, 1 });
      else
        ++ans.back().second;
    }

    return ans;
  }

} // namespace prime_factorization


/*
    ------------------------------------------------------------
    USAGE EXAMPLE
    ------------------------------------------------------------

    int main() {

        long long n = 360;

        vector<long long> factors =
            prime_factorization::factor(n);

        // Output:
        // 2 2 2 3 3 5

        for (long long p : factors)
            cout << p << ' ';

        cout << '\n';


        // Distinct prime factors:
        vector<long long> d =
            prime_factorization::distinct(n);

        // Output:
        // 2 3 5

        for (long long p : d)
            cout << p << ' ';

        cout << '\n';


        // Prime factorization with powers:
        auto cnt =
            prime_factorization::factor_count(n);

        // Output:
        // 2^3 3^2 5^1

        for (auto [p, e] : cnt)
            cout << p << '^' << e << ' ';

        cout << '\n';
    }

    ------------------------------------------------------------
*/
