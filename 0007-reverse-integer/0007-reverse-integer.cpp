class Solution {
public:
    int reverse(int x) {
        long d = 0;
        while(x!=0){
            int rem = x%10;
            d= d*10+rem;
            x/=10;
        }
        if (d > INT_MAX || d < INT_MIN) {
            return 0;
        }
        return int(d);
    }
};