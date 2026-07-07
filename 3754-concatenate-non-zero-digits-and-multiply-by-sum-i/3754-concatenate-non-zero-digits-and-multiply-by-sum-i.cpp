class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long d = 0;
        while(n>0){
            int r = n%10;
            if(r>0){
                d = d*10+r;
            }
            sum+=r;
            n/=10;
        }
        long long di = 0;
        while(d>0){
            int r = d%10;
            di = di*10+r;
            d/=10;
        }
        return di*sum;
    }
};