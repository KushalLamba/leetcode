// #include <climits>

// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         if (dividend == INT_MIN && divisor == -1) {
//             return INT_MAX;  // Handle overflow case
//         }

//         int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
//         long long ldividend = labs(dividend);
//         long long ldivisor = labs(divisor);

//         long long result = 0;
//         while (ldividend >= ldivisor) {
//             long long temp = ldivisor, multiple = 1;
//             while (ldividend >= (temp << 1)) {
//                 temp <<= 1;
//                 multiple <<= 1;
//             }
//             ldividend -= temp;
//             result += multiple;
//         }

//         result *= sign;

//         // Check for overflow before returning the result
//         if (result > INT_MAX) {
//             return INT_MAX;
//         } else if (result < INT_MIN) {
//             return INT_MIN;
//         }

//         return static_cast<int>(result);
//     }
// };
