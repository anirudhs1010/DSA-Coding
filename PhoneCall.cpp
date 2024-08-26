//Build the sequence. Problem credits: https://app.codesignal.com/arcade/code-arcade/intro-gates/mZAucMXhNMmT7JWta
int solution(int min1, int min2_10, int min11, int s) {
    if (s < min1)
        return 0;
    if (s < min2_10*9 + min1)
        return 1 + (s-min1)/min2_10;
    else {
        return 10 + (s-min1-min2_10*9)/min11;
    }
}

