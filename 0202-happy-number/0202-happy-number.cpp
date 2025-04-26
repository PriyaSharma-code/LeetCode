class Solution {
public:
    int digitSquare(int n){
        int sum = 0 , temp;
        while(n){
            temp = n %10;
            sum+=temp*temp;
            n /=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow,fast;
        slow=fast = n;
        do{
            slow =digitSquare(slow);
            fast = digitSquare(fast);
            fast = digitSquare(fast);
            if(fast==1)return 1;
        }while(slow!=fast);
        return 0;
    }
};