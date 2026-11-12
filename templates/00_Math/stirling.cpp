/*
    Stirling Numbers of the Second Kind
    ------------------------------------

    S(n, k) = number of ways to partition n DISTINCT objects
              into k NON-EMPTY UNLABELED groups.

    Recurrence:
        S(n, k) = S(n - 1, k - 1) + k * S(n - 1, k)

    Why?
        Add the n-th object.

        1. Put it into its own new group:
               S(n - 1, k - 1)

        2. Put it into one of the existing k groups:
               k * S(n - 1, k)

    ---------------------------------------------------------------
    Common competitive-programming interpretation
    ---------------------------------------------------------------

    If we have n positions and want to fill them using EXACTLY k
    DISTINCT VALUES, with every value used at least once, then:

        ways = k! * S(n, k)

    because:
        - S(n, k) partitions the n positions into k non-empty groups.
        - The k groups can then be assigned to the k distinct values
          in k! ways.

    Example:
        n = 4, k = 3

        S(4, 3) = 6

        Number of sequences using values {1,2,3}, all at least once:
            3! * S(4,3)
          = 6 * 6
          = 36

    ---------------------------------------------------------------
    Complexity
    ---------------------------------------------------------------

    Precompute up to N:
        Time  : O(N^2)
        Space : O(N^2) if the full table is stored.

    If only one S(n,k) is required, use stirling_number() below:
        Time  : O(n * k)
        Space : O(k)

    For n <= 1000, the full O(N^2) table is small enough:
        1001 * 1001 * 8 bytes ~= 8 MB.

    ---------------------------------------------------------------
    Usage
    ---------------------------------------------------------------

        precomp_stirling(1000);

        i64 x = stirling_number(4, 3);
        // x = 6

        i64 ways = surjections(4, 3);
        // ways = 36

    ---------------------------------------------------------------
    Notes
    ---------------------------------------------------------------

    - Results are modulo `mod` from the common shorthand template.
    - S(n, 0) = 0 for n > 0
    - S(0, 0) = 1
    - S(n, k) = 0 when k > n
    - This file assumes the common shorthand template is already
      included, so it uses `i64`, `vi`, `mod`, `fo`, `fr`, etc.
*/


// ================================================================
// Full Stirling table
// ================================================================

// stirling[n][k] = S(n, k)
vvi stirling;


// Precompute all S(n,k) for 0 <= n <= nmax.
//
// Complexity:
//     Time  : O(nmax^2)
//     Space : O(nmax^2)
//
// Useful when you have many queries asking for different (n, k).
void precomp_stirling(int nmax) {
  stirling.assign(nmax + 1, vi(nmax + 1, 0));

  // S(0,0) = 1
  stirling[0][0] = 1;

  fo(n, 1, nmax + 1) {
    fo(k, 1, n + 1) {
      stirling[n][k] =
        (stirling[n - 1][k - 1] +
          k * stirling[n - 1][k]) % mod;
    }
  }
}


// Return S(n,k), assuming precomp_stirling(nmax) was called.
//
// Complexity:
//     Time  : O(1)
//     Space : O(1)
i64 stirling_number(i32 n, i32 k) {
  if (k < 0 || k > n || n < 0) return 0;
  return stirling[n][k];
}


// ================================================================
// Number of ways to use EXACTLY k distinct values
// ================================================================

// Number of sequences of length n formed from k DISTINCT LABELED
// values, where every one of the k values appears at least once.
//
// Formula:
//     k! * S(n,k)
//
// Example:
//     n = 4, k = 3
//
//     1123
//     1213
//     1231
//     ...
//
//     Answer = 3! * S(4,3) = 36
//
// Requires factorials up to k.
// If your common combinatorics template already has fact[], use
// that instead. This implementation computes k! locally so that
// this template stays self-contained.
//
// Complexity:
//     After precomputation:
//         Time  : O(k)
//         Space : O(1)
//
// If used many times, prefer maintaining factorials in your
// combinatorics template and replace the loop by fact[k].
i64 surjections(i32 n, i32 k) {
  if (k < 0 || k > n || n < 0) return 0;

  i64 fact = 1;
  fo(i, 1, k + 1)
    fact = fact * i % mod;

  return fact * stirling[n][k] % mod;
}


// ================================================================
// Memory-efficient version for ONE query
// ================================================================

// Returns S(n,k) without storing the complete n x k table.
//
// Complexity:
//     Time  : O(n * k)
//     Space : O(k)
//
// Useful when:
//     - you only need one (n,k), or
//     - you do not want the O(n^2) table in memory.
//
// The loop over k goes backwards so dp[j-1] still represents
// the previous row when calculating dp[j].
i64 stirling_number_one(i32 n, i32 k) {
  if (k < 0 || k > n || n < 0) return 0;

  vi dp(k + 1);
  dp[0] = 1;  // S(0,0)

  fo(i, 1, n + 1) {
    fr(j, min(i, k), 1) {
      dp[j] = (dp[j - 1] + j * dp[j]) % mod;
    }

    // S(i,0) = 0 for i > 0.
    dp[0] = 0;
  }

  return dp[k];
}


// ================================================================
// Memory-efficient count of sequences using exactly k values
// ================================================================

// Returns:
//
//     k! * S(n,k)
//
// directly, using O(k) memory.
//
// Complexity:
//     Time  : O(n * k)
//     Space : O(k)
//
// Example:
//     count_surjections_one(4, 3) = 36
i64 count_surjections_one(i32 n, i32 k) {
  if (k < 0 || k > n || n < 0) return 0;

  i64 ways = stirling_number_one(n, k);

  i64 fact = 1;
  fo(i, 1, k + 1)
    fact = fact * i % mod;

  return ways * fact % mod;
}


/*
    ---------------------------------------------------------------
    Quick reference
    ---------------------------------------------------------------

    Want S(n,k)?
        precomp_stirling(N);
        stirling_number(n,k);

    Want exactly k DISTINCT LABELED values in n positions,
    with every value appearing at least once?
        precomp_stirling(N);
        surjections(n,k);

    Only one query and want O(k) memory?
        stirling_number_one(n,k);
        count_surjections_one(n,k);

    Identities:
        S(0,0) = 1
        S(n,0) = 0                 for n > 0
        S(n,n) = 1
        S(n,k) = 0                 for k > n

    Relation to inclusion-exclusion:

        k! * S(n,k)
          = sum_{i=0}^k (-1)^i * C(k,i) * (k-i)^n

    The left side is usually easier to compute with the DP above
    when n <= 1000.
*/
