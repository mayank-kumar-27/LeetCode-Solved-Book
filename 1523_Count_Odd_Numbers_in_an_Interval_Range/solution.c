// int countOdds(int low, int high) {
//     int count = 0, i = low % 2 == 1 ? low : low + 1;
//     while (i <= high) i += 2, count++;
//     return count;
// }

int countOdds(int low, int high) { return (high + 1) / 2 - (low / 2); }