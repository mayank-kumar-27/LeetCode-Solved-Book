// int minOperations(int n) {
//     int middle = n / 2;
//     int equal_to = (middle * 2) + 1;
//     int operation = 0;

//     for (int i = 0; i < n; i++) {
//         operation = operation + (abs(equal_to - ((2 * i) + 1)));
//     }
//     return operation / 2;
// }


int minOperations(int n) { return n * n / 4; }