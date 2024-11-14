class Solution {
public:
    int mod=1e9+7;
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        long long axor=0;
        long long bxor=0;
        for(ll i=49;i>=n;i--)
        {
            bool a_bit=((a>>i)&1);
            bool b_bit=((b>>i)&1);
            if(a_bit==true)
            {
                axor=axor^(1ll<<i);
            }
            if(b_bit==true)
            {
                bxor=bxor^(1ll<<i);
            }
        }
        for(ll i=n-1;i>=0;i--)
        {
            bool a_bit=((a>>i)&1);
            bool b_bit=((b>>i)&1);
            if(a_bit==b_bit)
            {
                axor=axor^(1ll<<i);
                bxor=bxor^(1ll<<i);
            }
            else
            {
                if(axor>bxor)
                {
                    bxor=(bxor^(1ll<<i));
                }
                else
                {
                    axor=(axor^(1ll<<i));
                }
            }
        }
        axor=axor%mod;
        bxor=bxor%mod;
        return (axor*bxor)%mod;
    }
};