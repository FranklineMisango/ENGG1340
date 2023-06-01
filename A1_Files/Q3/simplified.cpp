char CaesarShift(char c, int k) {
    if (c >= 'A' && c <= 'Z') {
        int x = c - 'A';
        int y = (x + k) % 26;
        char w = y + 'a';
        return w;
    }
    else if (c >= 'a' && c <= 'z') {
        int x = c - 'a';
        int y = (x + k) % 26;
        char w = y + 'A';
        return w;
    }
    else {
        return c;
    }
}
