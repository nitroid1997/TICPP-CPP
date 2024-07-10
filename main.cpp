#include "Header/support.h"
#include "Header/CLib.h"

#include <cstdlib>
#include <cstring>
#include <cassert>
/* // #define NDEBUG 
// add this before #include <cassert>, to remove assert() code.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

#define PI 3.1486

using namespace std;
using namespace Exercise_3;
using namespace Exercise_4;
using namespace Exercise_5;
using namespace Exercise_7;
using namespace CLikeLib;
using namespace CppLikeLib;
using namespace TrivialObjects;
using namespace HandlerClass;
using namespace PushDownStack;
using namespace IntLinkedList;

#ifdef DEBUG
    #define PDD(A) cout << #A << " (debug version): " << (A) << endl;
#else
    #define PDD(A) cout << #A << ": " << (A) << endl;
#endif

// Global declaration
class Nest {
    public:
        Nest() {}
        void display() {cout << "display() from Nest" << endl; }

        class Hen {
            public:
                Hen(){}
                void display() {cout << "display() from Hen" << endl; }
                void print() {cout << "print() from Hen" << endl; }

                class Egg {
                    public:
                        Egg() {}
                        void display() {cout << "display() from Egg" << endl; }
                };

        };

};

void ex9 (int i)
    {   
        // use of function overload and global scope, it's overloaded in support.h
        cout << "Hey, " << i << " Don't listen !" << endl;
    }

void printStash(Stash *s) {
    int k = 0;
    char* cp;
    while((cp = (char*)s->fetch(k++)) != 0)
        cout << cp << '\n';
}

int main(int argc, char *argv[]){

    /* // Sample header import and header function call.
    Ex1 snap;
    cout << "Hello" << endl;
    snap.printVoid();
    */
    
    /* // Word counter from a file.
    ifstream reader("Resource/SampleData.txt");
    string word;
    int count = 0;
    while(reader >> word){
        count++;
        cout << word << "\n";
    }
    cout << "Count = " << count << endl;
    */

    /* // Chp 2 Exercise
    vector<string> V; 
    ifstream reader("Resource/SampleData.txt");
    string word, scramble;
    int count = 0;
    while(reader >> word){
        count++;
        //cout << word << "\n";
        V.push_back(word);
        scramble+=word;
    }
    //cout << "Count = " << count << endl;
    for(int i = V.size()-1; i>=0; i--)
    {
        cout << V[i] << "\n";
        while(cin.get()!='\n');
    }
    //cout << "Scramble: " << scramble << endl;
    char c = cin.get();
    cout << c << endl;
    */

    /* // Prime list printer.
    cout << isPrime(4) << endl;
    */

    /* // two ways to modify strings.
   string name = "Rudra";
   stringChangePtr(&name); 
   stringChangeRef(name);
   cout << name << endl;
   */

    /* // Trigraph sample.
    cout << "Rudra" << "??/n";
    */

    /* // Explicit operator
   int a = 1 or 0;
   cout << a << endl;
   */

    /* // print binary, ror and rol.
  printBinary(ror(3));
  */

    /* // Ex:15
    Ex15 samplestruc;
    Ex15 *psamplestruc = &samplestruc;

    samplestruc.s1 = "Rudra";
    samplestruc.s2 = "Palande";
    samplestruc.val = 10;
    cout << samplestruc.s1 << " " << samplestruc.s2 << " " << samplestruc.val << endl;

    psamplestruc->s1 = "Palande";
    psamplestruc->s2 = "Rudra";
    psamplestruc->val = 20;
    cout << "After\n" << samplestruc.s1 << " " << samplestruc.s2 << " " << psamplestruc->val << endl;
    */

    /* // EX:16 // float in binary rep in memory
   float f = 2.2;

   unsigned char *ucptr = reinterpret_cast<unsigned char*>(&f);

   for(int i = sizeof(float)-1; i>=0; i--)
   {
    printBinary(ucptr[i]);
    printBinary(ucptr[i-1]);
   }
   cout << endl;

   float a = -2.2;

   unsigned char *acptr = reinterpret_cast<unsigned char*>(&a);

   for(int i = sizeof(float)-1; i>=0; i--)
   {
    printBinary(acptr[i]);
    printBinary(acptr[i-1]);
   }
   */

    /* // EX:27 constant and volatile cast
    const int SIZE = 8;

    const double array1[SIZE] = {0};
    volatile double array2[SIZE] = {0};

    printArrayD(const_cast<double*> (array1), SIZE, "one");
    printArrayD(const_cast<double*> (array2), SIZE, "two");

    cout << "\nRemoving const and volatile modifiers, modifying...\n";

    double *modifyingPtr = 0;

    for (int i = 0; i < SIZE; i++) {

        modifyingPtr = const_cast<double*> (array1 + i);
        *modifyingPtr = i + 0.1 + 0.1 * i;

        modifyingPtr = const_cast<double*> (array2 + i);
        *modifyingPtr = i + 0.3 + 0.3 * i;
    }

    cout << "Modified arrays:\n";
    printArrayD(const_cast<double*> (array1), SIZE, "one");
    printArrayD(const_cast<double*> (array2), SIZE, "two");
    */

    /* // EX:28 
    const int SIZE = 5;
    double a[SIZE] = {0};

    unsigned char* chPtr = reinterpret_cast<unsigned char*> (a);

    printArray(a, SIZE);

    for(int i = sizeof(double)-1; i >= 0 ; i--)
        printBinary(chPtr[i]);

    for (int i = 0; i < sizeof(double); i++)
        *(chPtr + i) = 1;

    printArray(a, SIZE);

    for(int i = sizeof(double)-1; i >= 0 ; i--)
        printBinary(chPtr[i]);
    */

    /* // EX:29 // Verify it more...
    cout << makeBinaryFromDouble(-2.1) << endl << makeBinaryFromDouble(5.6) << endl; 
    */

    /* // ptr to function.
    int (*funptrcall)(double) = &funPtrCall;
    int ret = (*funptrcall)(2.48);
    cout << ret << endl;
    */

    /* // Dynamic array sample in a C like format.
    CStash intStash, stringStash;
    int i;
    char *cp;
    ifstream in;//("Resource/SampleData.txt");
    string line;
    const int bufsize = 80;

    initialize(&intStash, sizeof(int)); // initialize the variables of intStash
    for(int i = 0; i <= 100; i++) 
        add(&intStash, &i);
    for(i = 0; i < count(&intStash); i++)
        cout << "fetch(&intStash, " << i << ") = " << *(int*)fetch(&intStash, i) << endl;

    // Holds 80-character strings:
    initialize(&stringStash, sizeof(char)*bufsize);
    in.open("main.cpp");
    assert(in);
    while(getline(in, line))
        add(&stringStash, line.c_str()); // The c_str() method converts a string to an array of characters with a null character at the end.
    i = 0; 
    while((cp = (char*)fetch(&stringStash,i++))!=0)  // 0 indicate end from fetch function
        cout << "fetch(&stringStash, " << i << ") = " << cp << endl;

    cleanup(&intStash);
    cleanup(&stringStash);
    */
    
    /* // Dynamic array sample in a C++ like format.
    Stash intStash;
    intStash.initialize(sizeof(int));
    for (int i = 0; i<= 100; i++)
        intStash.add(&i);
    for (int j = 0; j< intStash.count(); j++)
        cout << "intStash.fetch (" << j << ") = " << *(int*)intStash.fetch(j) << endl;
    
    //Holds 80-character strings.
    Stash stringStash;
    const int bufsize = 80;
    stringStash.initialize(sizeof(char)*bufsize);
    ifstream in ("main.cpp");
    // assure(in, "main.cpp"); // function form require.h, which is a header provided by book auther.
    string line;
    while (getline(in, line))
        stringStash.add(line.c_str());
    int k = 0;
    char *cp;
    while ((cp = (char*)stringStash.fetch(k++))!=0)
        cout << "intStash.fetch (" << k << ") = " << cp << endl;
    
    intStash.cleanup();
    stringStash.cleanup();
    */

    /* // Structure size check and no data structure size check
    cout << "Size of struct A: " << sizeof(A) << "\nSize of struct B: " << sizeof(B) << "\nSize of struct CStash: " << sizeof(CStash) << "\nSize of struct Stash: " << sizeof(Stash) << endl;
    */

    /* // Push-down stack using a linked list.
    ifstream in("Resource/SampleData.txt");
    Stack textlines;
    textlines.initialize();
    string line;
    // Read file and store lines in the Stack:
    while(getline(in, line))
        textlines.push(new string(line));
    // Pop the lines from the Stack and print them:
    string* s;
    while((s = (string*)textlines.pop()) != 0) {
    cout << *s << endl;
    delete s;
    }
    textlines.cleanup();
    */

    /* // Chp 4, EX 2.
    EX4_2 Ch4;
    Ch4.printEx();
    */

    /* // Chp 4, EX 4,5.
    EX4_4_ctype ex4_ctype;
    putVal(&ex4_ctype, 125);
    getVal(&ex4_ctype);

    EX4_4 ex4;
    ex4.putVal(125);
    ex4.getVal();
    */

    /* // Chp 4, EX 6.
    MyClass test;
    test.changeValue(123);
    test.printValue();
    */

    /* // Chp 4, EX 7,8.
    /* // using Stash.
    Stash doubleStash;
    doubleStash.initialize(sizeof(double));
    for(int i = 0; i <= 25; i++) {
        doubleStash.add(new double(i));
    }
    for(int i = 0; i <= 25; i++) {
        cout << *(double*)doubleStash.fetch(i) << "\n";
    }
    doubleStash.cleanup();
    /* // Using Stack
    Stack doubleStash;
    int stackSize = 0;
    doubleStash.initialize();
    for(int i = 0; i <= 25; i++) {
        doubleStash.push(new double(i));
    }
    double *dptr;
    while((dptr = (double*)doubleStash.pop()) != nullptr) {
        cout << *dptr << "\n";
    }
    // same thing as above using for loop.
    //for( int i = 0; i < 26; i++) {
    //    double *dp = (double*)doubleStash.pop();
    //    cout << *dp << "\n";
    //}
    */

    /* // Chp 4, EX 9.
    // use of function overload and global scope
    ex9(3);
    ex9(3.0f);
    ex9(float(3));
    ::ex9(3);

    //ex9(4); 
    // Failure if global is also taking int argument due to: 
    // [{"message": "call of overloaded ‘ex9(int)’ is ambiguous",}]

    // Chp 4, EX 12.
    // assert(false);
    cout << " Hello" << endl;
    */

    /* // Chp 4, EX 13
    Video InitialRelease;
    InitialRelease.print();
    */

    /* // Chp 4, EX 14
    Stack recordAlbum;
    recordAlbum.initialize();
    vector <string> albumNames = {"Arrows in your heart","Thriller","come undone","I am the Hype","I am Rock"};
    for(int i = 0; i < albumNames.size(); i++) {
        Video* Vidptr = new Video(int(i),i*2,i*10,albumNames[i]);
        recordAlbum.push(Vidptr);
    }
    cout << "\nENJOY !!!, all album added to collection.\n" << endl;
    
    Video* albumName;
    int rating = 0;
    while((albumName = (Video*)recordAlbum.pop())!= nullptr) {
        cout << ++rating << ": "; albumName->print(); cout << '\n';
    }
    */

    /* // Chp 4, EX 16
    VectorStash intStash;
    intStash.initialize(sizeof(int));
    for (int i = 0; i<= 100; i++)
        intStash.add(&i);
    for (int j = 0; j< intStash.count(); j++)
        cout << "intStash.fetch (" << j << ") = " << *(int*)intStash.fetch(j) << endl;
    
    //Holds 100-character strings.
    VectorStash stringStash;
    const int bufsize = 100;
    stringStash.initialize(sizeof(char)*bufsize);
    ifstream in ("Resource/SampleData.txt");
    //assure(in, "main.cpp"); // function form require.h, which is a header provided by book auther.
    string line;
    while (getline(in, line))
        stringStash.add(line.c_str());
    int k = 0;
    char *cp;
    while ((cp = (char*)stringStash.fetch(k++))!=0)
        cout << "intStash.fetch (" << k << ") = " << cp << endl;

    intStash.cleanup();
    stringStash.cleanup();
    */

    /* // Chp 4, EX 17
    int *nInt = new int(12);
    long *nLong = new long(1234);
    char *nChar = new char[10];
    float *nFloat = new float[10];

    cout << "Address:\n" << "nInt: " << nInt <<
            "\nnLong: " << nLong << "\nnchar: " << (void*)nChar <<
            "\nnFloat: " << nFloat << endl;
    
    delete nInt;
    delete nLong;
    delete []nChar;
    delete []nFloat;
    */
   
    /* // Chp 4, EX 18
    const char* s1 = "RudraP";
    char* s2;
    s2 = CharPtrCpy((char*)s1);
    cout << "s1: " << s1 <<": " << strlen(s1) << " " <<(void*)s1 << endl;
    cout << "s2: " << s2 <<": " << strlen(s2) << " " <<(void*)s2 << endl;
    delete []s2;
    */

    /* // Chp 4, EX 19
    parentStruct ps(123,456,789);
    ps.cs.printVal();
    ps.printVal();
    // Cannot call the below function as it is a private function in the struct, will result in compile error.
    // ps.printPrivate();
    */

    /* // Chp 4, EX 23
    Stack stashStack;
    stashStack.initialize();

    Stack reverseStack;
    reverseStack.initialize();

	const int bufsize = 200;
	ifstream in("main.cpp");
	string line;
	int counter = 0;

	Stash *stashPtr = new Stash;
    stashPtr->initialize(sizeof(char)*bufsize);

    while(getline(in, line)) {
        stashPtr->add(line.c_str());
        counter++;

        if (counter % 5 == 0) {
            stashStack.push(stashPtr);
            stashPtr = new Stash;
            stashPtr->initialize(sizeof(char) * bufsize);
        }
	}
    // Adds remainig lines
    stashStack.push(stashPtr);

    Stash* sPointer = 0;
    while((sPointer = (Stash*)stashStack.pop()) != 0)
        reverseStack.push(sPointer);
    
    while((sPointer = (Stash*)reverseStack.pop()) != 0) {
		printStash(sPointer);
		delete sPointer;
	}
    */

    /* // Chp 4, EX 25
    outerStruct o;
    o.createLL(10);
    o.printDestroy();
    */

    /* // Function pointer call
    bool (*pisPrime)(int) = &isPrime;
    bool val = pisPrime(14);
    cout << val << endl;
    */

    /* // Function address 
    cout << (void*)isPrime << endl;
    */

    /* // Friend function sample.
    X x;
    Z z;
    Y y;
    x.initialize();
    z.initialize();
    g(&x,123);
    y.f(&x);
    z.g(&x);
    h();
    */

    /* // Nested friend sample.
    Holder h;
    Holder::pointer hp, hp2;
    int i;

    h.initialize();
    hp.initialize(&h);
    hp2.initialize(&h);
    for(i = 0;i<sz; i++) {
        hp.set(i);
        hp.next();
    }
    hp.top();
    hp2.end();
    for(i = 0;i<sz; i++) {
        cout << "hp = " << hp.read() << ", hp2 = " << hp2.read() << endl;
    hp.next();
    hp2.previous();
    }
    */

    /* // Chp 5, EX 1,3.
    Ch5_Ex1 sample;
    sample.pubf(10); // will work as it is public.
    cout << sample.pub << endl;
    Ch5_Ex1_friend(&sample,123); // friend called.
    Ch5_Ex1_2 ex2;
    Ch5_Ex1_3 ex3;
    ex2.print(&sample);
    ex3.print(&sample);
    // sample.prif(10); // will not work as it is private.
    // cout << sample.pri << endl;
    // sample.prof(10); // will not work as it is protected.
    // cout << sample.pro << endl;
    */

    /* // Chp 5, Ex 8.
    Mapper m;
    m.showMap();
    */

    /* // Chp 5, Ex 10.
    Stash henStash;
    henStash.initialize(sizeof(Nest::Hen));

    Nest::Hen *aPtr = new Nest::Hen;
    Nest::Hen *bPtr = new Nest::Hen;
    Nest::Hen *cPtr = new Nest::Hen;

    henStash.add(aPtr);
    henStash.add(bPtr);
    henStash.add(cPtr);

    size_t count = henStash.count();

    for(size_t i = 0; i<count; i++) {
        Nest::Hen *tempPtr = (Nest::Hen*)henStash.fetch(i);
        tempPtr->print();
    }

    delete aPtr;
    delete bPtr;
    delete cPtr;
    */

    /* // Chp 5, Ex 12.
    Stack henStack;
    henStack.initialize();

    Nest::Hen *aPtr = new Nest::Hen;
    Nest::Hen *bPtr = new Nest::Hen;
    Nest::Hen *cPtr = new Nest::Hen;

    henStack.push(aPtr);
    henStack.push(bPtr);
    henStack.push(cPtr);

    Nest::Hen *tempPtr;

    while((tempPtr = (Nest::Hen*)henStack.pop())!=nullptr) {
        tempPtr->print();
    }

    delete aPtr;
    delete bPtr;
    delete cPtr;
    */

    /* // Chp 5, Ex 13: Handle class.
    Handle U;
    U.initialize();
    U.read();
    U.change(1);
    U.cleanup();
    */

    /* // Chp 5, Ex 14.
    StackOfInt st;

    st.push_to_stack(1);
    st.push_to_stack(2);
    st.push_to_stack(3);
    st.push_to_stack(4);
    cout << "Current peek: " << st.peek_from_stack() << endl;
    st.push_to_stack(5);
    st.push_to_stack(6);
    st.print_stack();

    while ( !st.isEmpty() )
        cout << st.pop_from_stack() << endl;
    cout << "Empty!!!" << endl;
    */

    /* // Stash with con & des.
    Stash intStash(sizeof(int));
    for(int i = 0; i < 100; i++)
        intStash.add(&i);
    for(int j = 0; j < intStash.count(); j++)
        cout << "intStash.fetch(" << j << ") = "<< *(int*)intStash.fetch(j)<< endl;
    const int bufsize = 80;
    Stash stringStash(sizeof(char) * bufsize);
    ifstream in("Resource/SampleData.txt");
    // assure(in, " Stash2Test.cpp");
    string line;
    while(getline(in, line))
        stringStash.add((char*)line.c_str());
    int k = 0;
    char* cp;
    while((cp = (char*)stringStash.fetch(k++))!=0)
        cout << "stringStash.fetch(" << k << ") = "<< cp << endl;
    */

    /* // Print data from example file that is pushed to stack, giving reverse output.
    ifstream in("Resource/SampleData.txt");
    Stack textlines;
    string line;
    while(getline(in,line)) {
        textlines.push(new string(line));
    }
    string *s;
    while((s=(string*)textlines.pop())!=0) {
        cout << *s << "\n";
        delete s;
    }
    */

    /* // Print data from example file that is pushed to stack, but print correct output.
    ifstream in("Resource/SampleData.txt");
    Stack textlines;
    string line;
    while(getline(in,line)) {
        textlines.push(new string(line));
    }
    RecReverser(&textlines);
    // ~Stack(); // destructors are called by compiler, no need to call them explicitely.
    */

    /* // Default constructor sample.
    // DefCon df(2,3);
    DefCon df = DefCon(2,3); // equivalent to DefCon df(2,3);
    df.printVal();

    DefCon dfar[2] = {DefCon(4,5)}; // Second object is created using default object.
    dfar[0].printVal();
    dfar[1].printVal();

    DefCon ddfar[2];
    ddfar[0].printVal();
    ddfar[1].printVal();
    // Will give garbage value, no out-of-bound error or warning triggered.
    ddfar[2].printVal();
    ddfar[3].printVal();
    ddfar[4].printVal();
    ddfar[5].printVal();

    cout << "No-con class called..." << endl;
    noCon noConO(898);
    // noConO.i = 2;
    cout << noConO.i << endl;
    */

    /* // Destructor is called even if we go to goto.
    for(int i=0; i<4; i++) {
        noCon noConn(i);
        if (i==2)
            goto EXIT_HERE;
    }
    EXIT_HERE:
    */

    /* // Ch 6, Ex 8
    string holder[] = { "one", "two", "three", "four", "five"};
    Stack NameHolder;
    int array_size = sizeof(holder)/sizeof(*holder);
    for(int i=0; i<array_size; i++) {
        NameHolder.push(new string(holder[i]));
    }
    string* line;
    while((line=(string*)NameHolder.pop())!=0) {
        cout << *line << "\n";
        delete line;
    }
    */

    /* // using overloaded constructors in Stash.
    Stash intStash(sizeof(int));
    for(int i=0; i<100; i++)
        intStash.add(&i);
    for(int i=0; i<intStash.count(); i++)
        cout << "intstash.fetch(" << i << ") = " << *(int*)intStash.fetch(i) << endl;

    const int bufsize = 80;
    Stash stringStash(sizeof(char)*bufsize,100);
    ifstream in("Resource/SampleData.txt");
    string line;
    while(getline(in,line))
        stringStash.add((char*)line.c_str());
    int k = 0;
    char *cp;
    while((cp=(char*)stringStash.fetch(k++))!=0)
        cout << "stringStash.fetch(" << k << ") = " << cp << endl;
    */

    /* // Using private, public in Union.
    SuperVar A('c'), B(12), C(1.4f);
    A.print();
    B.print();
    C.print();
    */

    /* // Sample MyString class using Mem class.
    MyString s("My test String");
    s.print(cout);
    s.concat(" some additional stuff");
    s.print(cout);
    MyString s2;
    s2.concat("Using default constructor");
    s2.print(cout);
    */

    /* // Chp 7, Ex 1.
    Text fromSampleData("Resource/SampleData.txt","");
    // Text fromSampleData("Resource/SampleData.txt",1);
    Text emptyData;
    // fromSampleData.concat(" -> file name\n");
    string data = fromSampleData.contents();
    cout << data << endl;
    emptyData.concat("Rudra");
    data = emptyData.contents();
    cout << "EMPTY: " << data << endl;
    emptyData.print();
    cout << ".............................." << endl;
    emptyData.print("\nHello..!");
    emptyData.caller(1,2.3);
    */

    /* // Chp 7, Ex 6.
    string lines[] = {"one", "two", "three", "four", "five"};
    Stack textLines(lines,5);

    string* s;
    while((s=(string*)textLines.pop())!=0) {
        cout << *s << endl;
    }
    delete s;
    */

    /* // Chp 7, Ex 10.
    memStash intStash(sizeof(int));
    for(int i = 0; i < 100; i++)
        intStash.add(&i);
    for(int j = 0; j < intStash.count(); j++)
        cout << "intStash.fetch(" << j << ") = "<< *(int*)intStash.fetch(j)<< endl;
    const int bufsize = 80;
    memStash stringStash(sizeof(char) * bufsize);
    ifstream in("Resource/SampleData.txt");
    // assure(in, " Stash2Test.cpp");
    string line;
    while(getline(in, line))
        stringStash.add((char*)line.c_str());
    int k = 0;
    char* cp;
    while((cp = (char*)stringStash.fetch(k++))!=0)
        cout << "stringStash.fetch(" << k << ") = "<< cp << endl;
    */
    
    
    cmd_halter();
    return 0;
}