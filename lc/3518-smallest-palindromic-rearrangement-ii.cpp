class Solution {
public:
    static const int mod = 1e9 + 7;
    static const int MAX = 1e4 + 1;
    long long fact[MAX], inv_fact[MAX];
    long long m(long long a, long long b) { return (a % mod) * (b % mod) % mod; }
    long long pow(long long a, long long e) {
        long long res = 1; a %= mod;
        while (e > 0) {
            if (e & 1) res = m(res, a);
            a = m(a, a);
            e >>= 1;
        }
        return res;
    }
    long long inv(long long a) { return pow(a, mod - 2); }
    void pre() {
        fact[0] = 1;
        for(int i = 1; i < MAX; i++) fact[i] = fact[i - 1] * i % mod;
        inv_fact[MAX - 1] = inv(fact[MAX - 1]);
        for(int i = MAX - 2; i >= 0; i--) inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    }
    void str(int* cnt, int idx) { // print str
        for (int i = idx; i < 26; i++) cout << string(cnt[i], i + 97);
        cout << " ";
    }
    string smallestPalindrome(string s, int k) {
        if (s.size() == 1) return s; // edge case
        pre();

        int cnt[26] = {0};
        for (char& c : s) cnt[c - 97]++;
        char odd_char = '.';
        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) odd_char = i + 97;
            cnt[i] /= 2;
        }

        string res;
        // how many chars needed after lexo order
        int idx = -1, chars = 0;
        long long d_inv = 1; // inverse of prod(fact[cnt[i]]) accumulated so far
        for (int i = 25; i >= 0; i--) {
            if (cnt[i] == 0) continue;
            auto x = m(m(fact[chars + cnt[i]], d_inv), inv_fact[cnt[i]]);
            if (x >= k) { idx = i; break; }
            chars += cnt[i];
            d_inv = m(d_inv, inv_fact[cnt[i]]);
        }
        if (idx == -1) return res;

        // str(cnt, 0);
        // cout << "idx:" << char(idx + 97) << " after:" << chars << "\n";
        // cnt of idx char
        int c = 0;
        for (; c <= cnt[idx]; c++) {
            auto x = m(fact[chars + c], m(d_inv, inv_fact[c]));
            if (x >= k) break;
        }

        // initial order of res
        for (int i = 0; i < idx; i++) res.append(string(cnt[i], i + 97));
        res.append(string(cnt[idx] - c, idx + 97));
        // cout << "idx:" << char(idx + 97) << " cnt[idx]:" << cnt[idx] << " c:" << c << "\n";
        // cout << res << "\n";

        // build lexo order
        cnt[idx] = c, chars += c, d_inv = m(d_inv, inv_fact[c]);
        while (k > 1) {
            long long combos = 0;
            for (int i = idx; i < 26; i++) {
                if (cnt[i] == 0) continue;
                // fix first char of new order
                auto x = 
                    m(fact[chars - 1], m(d_inv, cnt[i]));
                if (combos + x >= k) {
                    res += i + 97;
                    k -= combos;
                    chars--;
                    d_inv = m(d_inv, cnt[i]);
                    cnt[i]--;
                    break;
                }
                combos += x;
            }
            // str(cnt, idx);
            // cout << "k:" << k << " res:" << res << "\n";
        }

        // remaining chars in normar order
        for (int i = idx; i < 26; i++) res.append(cnt[i], i + 97);

        // palindrome res
        if (odd_char != '.') res += odd_char;
        res.append(res.rbegin() + (odd_char != '.'), res.rend());
        return res;
    }
};