int totalMoney(int n) {
    int N_of_Weeks = n / 7, N_of_Days = n % 7;
    int Total_Amount_of_Weeks = (N_of_Weeks * (56 + (N_of_Weeks - 1) * 7)) / 2;
    int Total_Amount_of_Days = (N_of_Days * (2 * (N_of_Weeks + 1) + (N_of_Days - 1))) / 2;
    
    return Total_Amount_of_Weeks + Total_Amount_of_Days;
}