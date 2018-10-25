//high-precision/source.cpp ver.1
#include<cstdio>
#include<cstring>
#define num(c) ((c)-'\x30')
#define let(i) ((i)+'\x30')
#define digit(c) ('\x30'<=(c)&&(c)<='\x39')
#define blank(c) ((c)=='\x0a'||(c)=='\x20')
#define capture(c,type) for((c)=getchar();type(c);(c)=getchar())
bool cmp(char *L,char *R,int S)
{
    for(int i(0);i<S;i++)
    {
        if(L[i]<R[i]) {return 1;}
        if(L[i]>R[i]) {return 0;}
    }
    return 0;
}
#include<stack>
using std::stack;
struct hp                       //unsigned!
{
    #define carry(pi) *(pi+1)=let(num(*(pi+1))+num(*(pi))/10),*(pi)=let(num(*(pi))%10)
    #define borrow(pi) *(pi+1)=let(num(*(pi+1)-1)),*(pi)=let(num(*(pi)+10));
    char bit[5120];
    hp(){memset(bit,let(0),sizeof(bit));}
    void in()
    {
        char c,*pc;
        stack<char>cs;
        capture(c,blank); cs.push(c);
        capture(c,digit) {cs.push(c);}
        for(pc=bit;!cs.empty();pc++) {*pc=cs.top(),cs.pop();}
    }
    void out()
    {
        char c,*pc;
        stack<char>cs;
        for(pc=bit;cs.size()<5120;pc++) {cs.push(*pc);}
        for(c=cs.top(),cs.pop();c=='\x30'&&!cs.empty();c=cs.top(),cs.pop());
        for(putchar(c);!cs.empty();c=cs.top(),cs.pop(),putchar(c));
    }
    friend hp operator+(hp _L,hp _R)
    {
        hp _A;
        for(int i=0;i<5120;i++)
        {
            _A.bit[i]=let(num(_A.bit[i])+num(_L.bit[i])+num(_R.bit[i]));
            if(num(_A.bit[i])>9) {carry(&_A.bit[i]);}
        }
        return _A;
    }
    friend hp operator-(hp _L,hp _R)
    {
        hp _A;
        for(int i=0;i<5120;i++)
        {
            _A.bit[i]=let(num(_A.bit[i]+num(_L.bit[i])-num(_R.bit[i])));
            if(num(_A.bit[i])<0) {borrow(&_A.bit[i]);}
        }
        return _A;
    }
    friend hp operator*(hp _L,hp _R)
    {
        hp _A;
        for(int i=0,ie=5120-0;i<ie;i++)
        for(int j=0,je=5120-i;j<je;j++)
        {
            _A.bit[i+j]=let(num(_A.bit[i+j]+num(_L.bit[i])*num(_R.bit[j])));
            if(num(_A.bit[i+j])>9) {carry(&_A.bit[i+j]);}
        }
        return _A;
    }
}
