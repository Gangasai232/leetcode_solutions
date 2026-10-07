class Solution {
public:
    int getSum(int a, int b) {

        while (b != 0) {

            // Carry
            unsigned int carry = (unsigned int)(a & b) << 1;

            // Sum without carry
            a = a ^ b;

            // Add carry in next iteration
            b = carry;
        }

        return a;
    }
};