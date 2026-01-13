int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize) {
    int total_time = 0;
    char garbage_types[] = {'M', 'P', 'G'};

    for (int i = 0; i < 3; i++) {
        char garbage_type = garbage_types[i];
        int pickup_time = 0, last_house = -1;

        for (int i = 0; i < garbageSize; i++) {
            int count = 0;
            for (int j = 0; garbage[i][j] != '\0'; j++) if (garbage[i][j] == garbage_type) count++;
            if (count > 0) { pickup_time += count; last_house = i; }
        }

        if (last_house != -1) {
            int travel_time = 0;
            for (int i = 0; i < last_house; i++) travel_time += travel[i];
            total_time += pickup_time + travel_time;
        }
    }
    return total_time;
}
