int findTheLongestBalancedSubstring(char * s){
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int l = 0, x = 0, y = 0;
        if (s[i] == '0') {
            while (s[i+x] != '1' && s[i+x] != '\0')
            x++;
            while (s[x+i+y] != '0' && s[x+i+y] != '\0')
            y++;
        }
        int m = fmin(x, y);//get min value if 00111 then x=2,y=3 so 0011 correct subarray req 
        l = 2*m;
        if (len < l)//first store in l
        len = l;
    }
    return len;
}