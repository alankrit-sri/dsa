class Solution {
public:
    int minFlips(int a, int b, int c) {
        int maxVal = max(a, b);
        maxVal = max(maxVal, c);
        int flips = 0;
        while(maxVal)
        {
            if(((c & 1) && !(a & 1) && !(b & 1)) || (!(c & 1) && (a & 1) && !(b & 1)) || (!(c & 1) && !(a & 1) && (b & 1)))
                ++flips;
            else if(!(c & 1) && (a & 1) && (b & 1))
                flips += 2;

            maxVal = maxVal >> 1;
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return flips;
    }
};
