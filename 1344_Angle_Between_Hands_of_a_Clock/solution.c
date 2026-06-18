double angleClock(int hour, int minutes) {
    double h = (hour % 12) * 30.0 + minutes * 0.5, m = minutes * 6.0;
    double d = fabs(h - m);
    return d < (360.0 - d) ? d : (360.0 - d);
}