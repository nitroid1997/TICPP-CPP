#pragma once
#ifndef SUPPORT_H
#define SUPPORT_H

#include <string>
#include <cstring>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

namespace Exercise_3 {

    // EX_Chp_no_Ex_no

    class Ex1 {

        public:

        void printVoid(void);

        char printChar(void);

        int printInt(void);

        float printFloat(void);     

    };
    
    typedef struct Ex15 {
        string s1;
        string s2;
        int val;
    } Ex15;

    struct A { int i[100];};

    struct B { void f();};

    bool isPrime(int);

    void stringChangePtr(string*);

    void stringChangeRef(string&);

    void printBinary(const unsigned char);

    unsigned char rol(unsigned char);

    unsigned char ror(unsigned char);

    void printArrayD(double*, int, string);

    string makeBinaryFromDouble(double);

    void printArray(double*, int);

    int funPtrCall(double);

}

namespace Exercise_4 {

    struct EX4_2 {
        void printEx();
    };

    typedef struct EX4_4_Ctype { 
        int value; 
    } EX4_4_ctype;

    struct EX4_4 {
        int value;

        void putVal(int);
        void getVal();
    };

    class MyClass {
        public:
            void changeValue(int x);
            void notification();
            void printValue();
        private:
            int m_value;
    };
    
    struct Video {
        // constructor
        Video(int i,int len,int p,string str):id(i),length(len),price(p),name(str) {cout << "Constructor called..." << endl;}

        int id;
        int length;
        int price;
        string name;

        void print();
    };

    struct parentStruct {
        struct childStruct {
            int val1;
            int val2;

            childStruct(int v1, int v2):val1(v1),val2(v2) {cout << "Constructor called..." << endl;}    
            void printVal();        
        } cs;

        int val1;
        
        parentStruct(int v1, int v2, int v3):cs(v1,v2),val1(v3) { cout << "outer constructor called..." << endl;}
        void printVal();

        private:

        void printPrivate();
    };

    void putVal(EX4_4_ctype *, int);
    void getVal(EX4_4_ctype *);
    void ex9(int i); // to check same fun name with different arg defined in main global.
    char* CharPtrCpy(char*);
}

namespace Exercise_5 {

    /* This declaration simply tells the compiler there’s a struct by that
    name, so it’s OK to refer to it as long as you don’t require any more
    knowledge than the name. */
    struct X;

    struct Y {
        void f(X*); // X* is just address, hence can be used before X is declared.
    };

    struct X {
        private:
            int i;
        public:
            void initialize();
            friend void g(X*, int);
            friend void Y::f(X*);
            friend struct Z;
            friend void h();
    };

    struct Z {
        private:
            int j;
        public:
            void initialize();
            void g(X* x);
    };

    const int sz = 20;

    struct Holder {
        private:
            int a[sz];
        public:
            void initialize();
            struct pointer;
            friend pointer;

            struct pointer {
                private:
                    Holder *h;
                    int *p;
                public:
                    void initialize(Holder *h);
                    // Move around the array
                    void next();
                    void previous();
                    void top();
                    void end();
                    // Access value
                    int read();
                    void set(int i);
            };

    };

    class Ch5_Ex1;

    class Ch5_Ex1_2 {
        public:
            void print(Ch5_Ex1*);
    };

    class Ch5_Ex1_3 {
        public:
            void print(Ch5_Ex1*);
    };

    class Ch5_Ex1 {
        private:
            int pri;
            void prif(int x);
        protected:
            int pro;
            void prof(int x);
        public:
            int pub;
            void pubf(int x);
            friend Ch5_Ex1_2;
            friend void Ch5_Ex1_3::print(Ch5_Ex1*);
            friend void Ch5_Ex1_friend(Ch5_Ex1*, int);
    };
    
    class Mapper {
        public:
            Mapper() : a(1), b(2.2), c(3), d(4.4), e(5), f('z') {}
            void showMap();
            int a;
            double b;
        protected:
            int c;
            double d;
        private:
            int e;
            char f;
    };

    class DefCon {
            int i,j;
        public:
            DefCon(); 
            DefCon(int i,int j);
            void printVal(); 
    };

    class noCon {
        public:
            int i;
            noCon(int i);
            ~noCon();
    };

    void Ch5_Ex1_friend (Ch5_Ex1*,int);

    void h();

}
// namespace 5 include Ch 6 objects too.

namespace Exercise_7 {

    class SuperVar {
            enum {
                character,
                integer,
                floating_point
            } vartype;
            union {
                char c;
                int i;
                float f;
            };
        
        public:
            SuperVar(char ch);
            SuperVar(int li);
            SuperVar(float ff);
            void print();
    };

    typedef unsigned char byte;

    class Mem {
            byte* mem;
            int size;
        public:
            //Mem();
            Mem(int sz = 0);
            ~Mem();
            int msize();
            void ensureMinSize(int minSize);
            // byte* pointer();
            byte* pointer(int minSize = 0);
    };

    class MyString {
            Mem* buf;
        public:
            MyString();
            MyString(char* str);
            ~MyString();
            void concat(char* str);
            void print(std::ostream& os);
    };

    class Text {
            string data;
        public:
            Text();
            Text(string,string = "");
            Text(string,int = 1);
            ~Text();
            string contents();
            void concat(string);
            void print(string = "");
            void caller(int,float);
    };

}

#endif // SUPPORT_H