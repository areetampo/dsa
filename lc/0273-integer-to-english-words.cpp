class Solution {
public:
    string under_20[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string thousands[4] = {"", "Thousand", "Million", "Billion"};
    string help(int val) {
        if (val == 0) return "";
        if (val < 20) return under_20[val] + " ";
        if (val < 100) return tens[val / 10] + " " + help(val % 10);
        return under_20[val / 100] + " Hundred " + help(val % 100);
    }
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res = "";
        int thousand_cnt = 0;
        while (num) {
            if (num % 1000) res = help(num % 1000) + thousands[thousand_cnt] + " " + res;
            num /= 1000;
            thousand_cnt++;
        }
        int last_idx = 0;
        for (int i = 0; i < res.length(); i++) {
            if (res[i] != ' ') last_idx = i;
        }
        return res.substr(0, last_idx + 1);
    }
};