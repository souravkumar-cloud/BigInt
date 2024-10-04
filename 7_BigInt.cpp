#include<bits/stdc++.h>
using namespace std;
class BigInt{
    string digits;
    public:
    BigInt(unsigned long long n=0);
    BigInt(string &);
    BigInt(BigInt &);
    BigInt(const char *);
    //below some friend function
    //these are not the member of the class but can access private data of the class
    friend void divide_by_2(BigInt &a);
    friend bool Null(BigInt &);
    friend int length(BigInt &);
    int operator[](const int)const;

    BigInt &operator=(const BigInt &);

    BigInt &operator++();
    BigInt operator++(int temp);
    BigInt &operator--();
    BigInt operator--(int temp);

    friend BigInt &operator+=(BigInt & , const BigInt &);
    friend BigInt operator+(const BigInt &,const BigInt &);
    friend BigInt operator-(const BigInt &,const BigInt &);
    friend BigInt &operator-=(BigInt &,const BigInt &);

    friend bool operator==(const BigInt & ,const BigInt &);
    friend bool operator!=(const BigInt & ,const BigInt &);

    friend bool operator<(const BigInt &,const BigInt &);
    friend bool operator>(const BigInt &,const BigInt &);
    friend bool operator>=(const BigInt &,const BigInt &);
    friend bool operator<=(const BigInt &,const BigInt &);

    friend BigInt &operator*=(BigInt &,const BigInt &);
    friend BigInt operator*(const BigInt &,const BigInt &);
    friend BigInt operator/=(BigInt &,const BigInt &);
    friend BigInt &operator/(const BigInt &,const BigInt &);
    
}; 

BigInt &operator+=(BigInt &a,const BigInt &b){
    int t=0,s,i;
    int n=a.digits.size(),m=b.digits.size();
    if(m>n) a.digits.append(m-n,0);
    for(i=0;i<n;i++){
        if(i<m) s=(a.digits[i]+b.digits[i]) + t;
        else s=a.digits[i]+t;
        t=s/10;
        a.digits[i]=s%10;
    }
    if(t) a.digits.push_back(t);
    return a;
}
BigInt operator+(const BigInt &a,const BigInt &b){
    BigInt temp;
    temp=a;
    temp+=b;
    return temp;
}
BigInt &operator-=(BigInt &a,const BigInt &b){
    if(a<b) throw("UNDERFLOW");
    int n=a.digits.size(),m=b.digits.size();
    int i,t=0,s;
    for(i=0;i<n;i++){
        if(i<m) s=a.digits[i]-b.digits[i]+t;
        else s=a.digits[i]+t;
        if(s<0) s+=10,t= -1;
        else t=0;
        a.digits[i]=s;
    }
    while(n>1 && a.digits[n-1]==0) a.digits.pop_back(),n--;
    return a;
}
BigInt operator-(const BigInt &a,const BigInt &b){
    BigInt temp;
    temp=a;
    temp-=b;
    return temp;
}

bool operator<(const BigInt &a,const BigInt &b){
    int n=a.digits.size(),m=b.digits.size();
    if(n!=m) return n<m;
    while(n--){
        if(a.digits[n]!=b.digits[n]) return a.digits[n]<b.digits[n];
    }
    return false;
}
bool operator>(const BigInt &a,const BigInt &b){
    return b<a;
}

bool operator>=(const BigInt &a ,const BigInt &b){
    return !(a<b);
}
bool operator<=(const BigInt &a,const BigInt &b){
    return !(a>b);
}

bool operator==(const BigInt &a,const BigInt &b){
    return a.digits==b.digits;
}
 
bool operator!=(const BigInt &a,const BigInt &b){
    return !(a.digits==b.digits);
}

BigInt::BigInt(string & s){
    digits="";
    for(int i=s.size()-1;i>=0;i--){
        if(!isdigit(s[i])) throw ("ERROR");
        digits.push_back(s[i]-'0');
    }
}

BigInt::BigInt(unsigned long long n){
    do{
        digits.push_back(n%10);

        n/=10;
    }while(n);
}

BigInt::BigInt(const char *s){
    digits="";
    for(int i=strlen(s)-1;i>=0;i++){
        if(!isdigit(s[i])) throw "ERROR";
        digits.push_back(s[i]-'0');
    }
}
BigInt::BigInt(BigInt &a){
    digits=a.digits;
}
bool Null(BigInt &a){
    if(a.digits.size()==1&&a.digits[0]==0) return true;
    return false;
}
int length(BigInt &a){
    return a.digits.size();
}
int BigInt:: operator[](const int idx)const{ //const indicates that the function is not able to change the data which is passint in it
    if(idx<0||idx>=digits.size()) throw "ERROR";
    return digits[idx]; 
}

BigInt  &BigInt ::  operator++(){
    int i,n=digits.size();
    for( i=0;i<n&&digits[i]==9;i++) digits[i]=0;
    if(i==n) digits.push_back(1);
    else digits[i]++;    
    return *this;
}
BigInt &BigInt :: operator--(){
    int i,n=digits.size();
    if(digits[0]=0 && digits.size()==1) throw ("UNDERFLOW");
    for( i=0;i<n&&digits[i]==0;i++) digits[i]=9;
    digits[i]--;
    if(n>1&&digits[n-1]==0) digits.pop_back();
    return *this;

}
int main(){
    
    return 0;
}