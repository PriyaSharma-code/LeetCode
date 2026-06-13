class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        sort( nums.begin(), nums.end( ) );
        nums.erase(unique( nums.begin( ), nums.end( ) ), nums.end( ) );
        const int size = static_cast<int>( nums.size( ) );
        int l = 0;
        int r = size - 1;
        int result = nums.back( ) ^ nums.front( );
        long long upper = 1;
        while( upper <= nums.back( ) )
            upper <<= 1;
        --upper;
        while( l + 1 < r )
        {
            int a = nums[l];
            int b = nums[l + 1];
            int c = nums[r - 1];
            int d = nums[r];
            result = max( result, a ^ b );
            result = max( result, a ^ c );
            result = max( result, b ^ d );
            result = max( result, c ^ d );
            if( static_cast<long long>( a ) + d < upper )
                ++l;
            else
                --r;
        }
        return result;
    }
};