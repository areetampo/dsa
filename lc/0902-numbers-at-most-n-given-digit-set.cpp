class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        //eg: 243, [1,2,3,4,6,8] 
        // 1 digit nums -> all 6 taken
        // 2 digit nums -> all 6 taken for 1st and all 6 taken for 2nd digit
        int res = 0;
        for (int i = 1; i <= log10(n); i++) res += pow(digits.size(), i);
        //now numbers with length == n, start form the left
        cout << res << "\n";
        string num = to_string(n);
        //at i = num.len - 1, the combos of digits placed at last position
        //(= pow(total digits < num.len - 1, 0 cuz no more digits to right))
        //were determined but if digits a digit == num.len - 1 then
        //this funtion call was made and i at num.len which means that last
        //digit must also be placed
        //eg: 243, [1,2,3,4,6,8]
        //i = 0 -> less than 2 * pow(digits.len, leftover places) = 1 * pow(6,2)
        //= 36, 1_ _ (6 digits put at these 2 places), as digit 2 is in digits[]:
        //i = 1 -> less 4 * pow(digits.len, leftover places) = 3 * pow(6,1)
        //= 18, 21_, 22_, 23_ (6 digits put at 1 place for all 3),
        //as digit 4 is also in digits[]:
        //i = 3 -> less than 3 * pow(digits.len, leftover places) = 2 * pow(6, 0)
        //= 2, 241, 242 formed BUT 243 IS LEFT, IF 3 WAS NOT IN DIGITS[] THEN
        //THIS WOULD NOT BE A PROBLEM, BUT HERE NEXT FUNC CALL IS MADE AND 3
        //MUST BE PUT giving 243
        for (int i = 0; i < num.size(); i++) {
            char digit = num[i]; 
            int is_digit_in_digits = 0, cnt_less_than_digit = 0;
            for (auto& s : digits) {
                cnt_less_than_digit += s[0] < digit;
                is_digit_in_digits += s[0] == digit;
            }
            res += cnt_less_than_digit * pow(digits.size(), num.size() - 1 - i);
            res += i == num.size() - 1 && is_digit_in_digits;
            if (!is_digit_in_digits) break;
        }
        return res;
    }
};