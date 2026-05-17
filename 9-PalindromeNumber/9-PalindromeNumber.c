// Last updated: 5/17/2026, 5:52:48 PM
bool isPalindrome(int x) {
    int output=0,flag=0;
    long long int num = 0;
    int original=x;
    if(x==0){
        return true;
    }
    while(x>0){
        num=num*10;
        output=x%10;
        x=x/10;
        num=num+output;
        flag=1;
    }
    if(num==original && flag==1){
        return true;
    }
    else{
        return false;
    }
}