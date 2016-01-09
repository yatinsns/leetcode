bool isMatch(char* s, char* p) {
    // If pattern ends, so should string.
    if (*p == '\0') {
        return *s == '\0';
    }
    
    // If second character is not '*', then match first character
    if (*(p + 1) != '*') {
      return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);    
    }
    
    // Second character is '*'
    // 0 or 1 or 2 or more occurences
    while (((*p == *s) || (*p == '.')) && *s != '\0') {
        if (isMatch(s, p + 2)) {
            return true;
        }
        s++;
    }
    
    // Conside '.*' to be done
    return isMatch(s, p + 2);
}

int main(int argc, char *argv[]) {
    printf("%d", isMatch("geeks", "ge*ks"));
    return 0;
}
