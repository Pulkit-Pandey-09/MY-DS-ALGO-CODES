class Solution {
public:
    #define ll long long
    ll mod = 1000000007;
    ll rev(int num)
    {
        if(num < 10) return num;
        int rev = 0;
        while(num)
        {
            int dig = num%10;
            rev = rev * 10 + dig;
            num = num/10;
        }
        return rev;
    }
    int countNicePairs(vector<int>& nums) 
    {
        unordered_map<ll, ll> lookup;
        ll  ans = 0;
        for(auto num : nums)
        {
            ll rev_num = rev(num);
            ll diff = num - rev_num;
            lookup[diff]++;
        }
        for(auto see : lookup)
        {
            ans += (see.second*(see.second-1))/2;
        }
        return ans%mod;
    }
};

/*
[13,10,35,24,76]


*/