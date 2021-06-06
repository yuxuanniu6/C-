void merge(int* A, int ALen, int m, int* B, int BLen, int n) {
    // write code here
    for(int i=m+n+1;i>=0;i--){
        //B数组中用完，就填A数组中的
        if(n-1<0||(m-1>=0&&(*(A+m-1)>*(B+n-1))))
        {
            *(A+m+n-1)=*(A+m-1);
            m--;
        }
        else
        {
            *(A+m+n-1)=*(B+n-1);
            n--;
        }
    }
}
