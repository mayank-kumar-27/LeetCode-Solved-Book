// Method -> 1
// int GCD(int a, int b) {
//     if (b == 0) {
//         return a;
//     }
//     return GCD(b, a % b);
// }

// int gcdOfOddEvenSums(int n) {
//     int odd = 0, even = 0;
//     for (int i = 1; i <= n; i++) {
//         even += i * 2;
//         odd += (i * 2 - 1);
//     }

//     return GCD(odd, even);
// }

// Method -> 2
// int GCD(int a, int b) {
//     if (b == 0) {
//         return a;
//     }
//     return GCD(b, a % b);
// }

// int gcdOfOddEvenSums(int n) {
//     int odd = n * n;
//     int even = n * (n + 1);

//     return GCD(odd, even);
// }

// Method -> 3 (Best Solution)
int gcdOfOddEvenSums(int n) { return n; }