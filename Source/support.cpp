#include "../Header/support.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstring> // for memset()

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

namespace Exercise_3 {

    void Ex1::printVoid(void){
        cout << "printVoid called...."<<"\n";
    }

    char Ex1::printChar(void){
        cout << "printChar called...."<<"\n";
        return 'c';
    }

    int Ex1::printInt(void){
        cout << "printInt called...."<<"\n";
        return 1;
    }

    float Ex1::printFloat(void){
        cout << "printFloat called...."<<"\n";
        return 1.1;
    }

    bool isPrime(int n){
        bool isPrimeNum = true;
        for(int i = 2; i<=n/2 && n>1; i++){
            if(n%i==0)
                isPrimeNum = false;
        }
        return isPrimeNum;
    }

    void stringChangePtr(string *pstr){
        *pstr+=" Palande";
    }

    void stringChangeRef(string &pstr){
        pstr+=" Palande";
    }

    void printBinary(const unsigned char val){
        for(int i = 7; i>=0; i--)
            if(val & (1<<i))
                cout <<"1";
            else
                cout << "0";
    }

    unsigned char rol(unsigned char val){
        int lowbit = 0;
        if(val & 1)
            lowbit = 1;
        val >>= 1;
        val |= (lowbit << 7);
        return val;
    }

    unsigned char ror(unsigned char val){
        int highbit = 0;
        if(val & (1 << 7))
            highbit = 1;
        val <<= 1;
        val |= highbit;
        return val;
    }

    void printArrayD(double* a, int size, string name) {
    cout << "Array " << name << ": ";
    for (int i = 0; i < size; i++)
        cout <<*(a + i) << " ";

    cout << endl;
}

    string makeBinaryFromDouble (double num) {

    string result = "";

    unsigned char* charPtr =
    reinterpret_cast<unsigned char*>(&num);

    unsigned char val;

    int digit = 63;

    for(int index = sizeof(double)-1; index >= 0 ; index -= 1) {

        val = *(charPtr + index);

        for(int i = 7; i >= 0; i--) {
            if(val bitand (1 << i))
                result += "1";
            else
                result += "0";

        if (digit == 63 || digit == 52)
            result += " ";

        digit--;
        } 
    }
    return result;
    }
    
    void printArray(double* a, int arraySize) {
    cout << endl;

    for (int i = 0; i < arraySize; i++)
        cout <<*(a + i) << " ";

    cout << endl;
    }

    int funPtrCall(double d){
        int i = 101;
        cout << "number: " << d << endl;
        return i; 
    }

    void B::f(){}
}

namespace Exercise_4 {

    void EX4_2::printEx() {
        cout << "Working on Chapter 4, Exercise 2.\n" << endl;
    }

    void putVal(EX4_4_ctype* ex4, int val) {
        ex4->value = val;
    }

    void getVal(EX4_4_ctype* ex4) {
        cout << "value: " << ex4->value << endl; 
    }

    void EX4_4::putVal(int val) {
        value = val;
    }

    void EX4_4::getVal() {
        cout << "value: " << value << endl; 
    }

    void MyClass::changeValue(int x) {
        this->notification();
        this->m_value = x;
    }

    void MyClass::notification() {
        cout << "changing value..." << endl;
    }

    void MyClass::printValue() {
        cout << "MyClass:m_value = " << this->m_value << endl;
    }

    void ex9(int i)
    {
        cout << "Hey, " << i << " listen !" << endl;
    }
    
    void Video::print() {
        cout << name << endl;
    }

    char* CharPtrCpy(char* str) {
        int strSize = 0;
        while(*(str + strSize++)!='\0');
        char* s1 = new char[strSize];
        for(int i = 0; i <= strSize; i++) {
            *(s1+i) = *(str+i);
        }
        return s1;
    }

    void parentStruct::childStruct::printVal() {
        cout <<"from child: " << val1 << ", " << val2 << endl;
    }

    void parentStruct::printVal() {
        cout <<"from parent: " << cs.val1 << ", " << cs.val2 << ", " << val1 << endl;
        printPrivate();
    }

    void parentStruct::printPrivate() {
        cout << "From private: This is private..!\n";
    }

}

namespace Exercise_5 {

    void X::initialize() {
        i=0;cout <<"from X::initialize, i = " << i << endl;        
    }

    void g(X*x, int i) {
        x->i = i;cout <<"from global g(), i = " << x->i << endl;
    }

    void Y::f(X* x) {
        x->i = 47;cout <<"from Y::f(), i = " << x->i << endl;
    }

    void Z::initialize() {
        j=0;cout <<"from Z::initialize, j = " << j << endl;
    }

    void Z::g(X* x) {
        x->i += j;cout <<"i = " << x->i << endl;
    }

    void h() {
        X x; x.i=100;cout <<"i = " << x.i << endl;
    }

    void Holder::initialize() {
        memset(a,0,sz*sizeof(int));
    }

    void Holder::pointer::initialize(Holder *rv) {
        h = rv;
        p = rv->a;
    }

    void Holder::pointer::next() {
        if(p < &(h->a[sz - 1])) p++;
        //cout << p << ", " << h->a[0] << endl;
    }

    void Holder::pointer::previous() {
        if(p > &(h->a[0])) p--;
    }

    void Holder::pointer::top() {
        p = &(h->a[0]);
    }

    void Holder::pointer::end() {
        p = &(h->a[sz - 1]);
    }

    int Holder::pointer::read() {
        return *p;
    }

    void Holder::pointer::set(int i) {
        *p = i;
    }

    void Ch5_Ex1::prif(int x) {
        pri = x;
    }

    void Ch5_Ex1::prof(int x) {
        pro = x;
    }

    void Ch5_Ex1::pubf(int x) {
        pub = x;
    }

    void Ch5_Ex1_friend(Ch5_Ex1* ex,int i) {
        ex->pri = i;
        cout << "private value is " << ex->pri << endl;
    }

    void Ch5_Ex1_2::print(Ch5_Ex1* ex) {
        cout << "private value from 2 is " << ex->pri << endl;
    }

    void Ch5_Ex1_3::print (Ch5_Ex1* ex) {
        cout << "private value from 3 is " << ex->pri << endl;
    }

    void Mapper::showMap() {
        cout << "Public: "
         << "\n&a: " << (long)&a
         << "\n&b: " << (long)&b
         << "\nProtected: "
         << "\n&c: " << (long)&c
         << "\n&d: " << (long)&d
         << "\nPrivate: "
         << "\n&e: " << (long)&e
         << "\n&f: " << (long)&f
         << endl;
    }

    DefCon::DefCon() {
        this->i = 0;
        this->j = 0;
    }

    DefCon::DefCon(int i, int j) {
        this->i = i;
        this->j = j;
    }

    void DefCon::printVal() {
        cout << i << ", " << j << endl;
    }

    noCon::noCon(int i) {
        this->i = i;
        cout << "constructor called... Value: " << this->i << "." << endl;
    }

    noCon::~noCon() {
        cout << "Destructor called... Value: " << this->i << "." << endl;    
    }

}

namespace Exercise_7 {

    SuperVar::SuperVar(char ch) {
        vartype = character;
        c = ch;
    }

    SuperVar::SuperVar(int ii) {
        vartype = integer;
        i = ii;
    }

    SuperVar::SuperVar(float ff) {
        vartype = floating_point;
        f = ff;
    }

    void SuperVar::print() {
        switch (vartype) {
            case character:
                cout << "character: " << c << endl;
                break;
            case integer:
                cout << "integer: " << i << endl;
                break;
            case floating_point:
                cout << "float: " << f << endl;
                break;
        }
    }

    // Removed Default con, due to default arg in other con.
    // Mem::Mem() {
    //     mem = 0;
    //     size = 0;
    // }

    Mem::Mem(int sz) {
        mem = 0;
        size = 0;
        if(size!=0)
            ensureMinSize(sz);
    }

    Mem::~Mem(){
        delete []mem;
    }

    int Mem::msize()
    {
        return size;
    }

    void Mem::ensureMinSize(int minSize) {
        if(size < minSize) {
            byte* newmem = new byte[minSize];
            memset(newmem+size, 0, minSize-size);
            memcpy(newmem, mem, size);
            delete []mem;
            mem = newmem;
            size = minSize;
        }
    }

    // byte* Mem::pointer() {
    //     return mem;
    // }

    byte* Mem::pointer(int minSize) {
        if(minSize!=0)
            ensureMinSize(minSize);
        return mem;
    }

    MyString::MyString() {
        buf = 0; 
    }

    MyString::MyString(char* str) {
        buf = new Mem(strlen(str) + 1);
        strcpy((char*)buf->pointer(), str);
    }

    void MyString::concat(char* str) {
        if(!buf) 
            buf = new Mem;
        strcat((char*)buf->pointer(buf->msize() + strlen(str) + 1), str);  
    }

    void MyString::print(std::ostream& os) {
        if(!buf) return;
        os << buf->pointer() << endl;
    }

    MyString::~MyString() { 
        delete buf; 
    }

    Text::Text() {
        data = "";
    }

    Text::Text(string fileName, string placeHolder) {
        ifstream in(fileName);
        string line;
        while(getline(in, line)) {
            data += line;
            data += '\n';
        }
    }

    Text::Text(string str, int placeHolder) {
        data = str;
    }

    Text::~Text() {
        cout << "String cleared...." << endl;
    }

    string Text::contents() {
        return data;
    }

    void Text::concat(string dataStr) {
        data += dataStr;
        data += '\n';
    }

    void Text::print(string s) {
        data += s;
        cout << data << endl;
    }

    void Text::caller(int, float) {
        cout << "fun called...." << endl;
    }


}