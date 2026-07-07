//brute force : using extra space
class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int>temp;
        long long sum =0;
        while(n>0){
            int rem=n%10;
            if(rem!=0){
                sum+=rem;
                temp.push_back(rem);
            }
            n/=10;
            
        }
        long long x=0;
            int y=1;
        for(int i =0; i<temp.size(); i++){
            x+=y*temp[i];
            y*=10;
        }
        x*=sum;
        return x;
    }
};

//optimised: without using extra space

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long num = 0;
        long long place = 1;

        while (n > 0) {
            int rem = n % 10;

            if (rem != 0) {
                sum += rem;
                num += rem * place;
                place *= 10;
            }

            n /= 10;
        }

        return sum * num;
    }
};