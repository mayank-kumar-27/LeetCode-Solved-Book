// char* truncateSentence(char* s, int k) {
//     int i = 0, spaceCount = 0;

//     while (s[i] != '\0' && spaceCount < k) {
//         if (s[i] == ' ') {
//             spaceCount++;
//         }
//         i++;
//     }

//     if (spaceCount == k) {
//         i--;
//     }

//     s[i] = '\0';
//     return s;
// }

char* truncateSentence(char* s, int k) {
    int i = 0;
    
    while (s[i] && k) {
        if (s[i++] == ' ') k--;
    }
    
    s[k ? i : i - 1] = '\0';
    return s;
}