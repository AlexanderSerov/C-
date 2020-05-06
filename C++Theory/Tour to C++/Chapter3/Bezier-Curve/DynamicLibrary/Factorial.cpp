int factorial(int n) {
        int r = 1;
        for(int i = n; i>0; i--){
                r *= i;
        }
        return r;
}