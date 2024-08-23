/* Daily Question: 592. Fraction Addition and Subtraction
 * by Tyler Edwards | August 22nd, 2024 
 * Code Credit: StefanPochmann
 * Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.
 * The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. 
 * So in this case, 2 should be converted to 2/1. */

class Solution {
public:
    string fractionAddition(string expression) {
        istringstream in(expression);
        int A = 0, B = 1, a, b;
        char _;
        while (in >> a >> _ >> b) {
            A = A * b + a * B;
            B *= b;
            int g = abs(__gcd(A, B));
            A /= g;
            B /= g;
        }
        return to_string(A) + '/' + to_string(B);
    }
};

