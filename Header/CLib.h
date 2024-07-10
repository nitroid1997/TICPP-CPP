//: C04:CLib.h
// Header file for a C-like library
// An array-like entity created at runtime

// include guards
#pragma once
#ifndef CLIB_H
#define CLIB_H

#include "support.h"

#include <vector>

using namespace Exercise_7;

using std::vector;

namespace TrivialObjects {

    void cmd_halter();

};

namespace CLikeLib {

    typedef struct CStashTag {
        /*  Structure of Stash:
            size: size of each space
            quantity: numberb of storage space
            next: next empty space
            storage: dynamically allocate array of bytes */
        int size;  
        int quantity;
        int next;
        unsigned char* storage;
    } CStash;

    void initialize (CStash* s, int size);
    void cleanup (CStash* s);
    int add (CStash* s, const void* element);
    void* fetch (CStash* s, int index);
    int count (CStash* s);
    void inflate (CStash* s, int increase);

}

namespace CppLikeLib {

    /* // Stash using a C++ style structure.
    struct Stash {
        int size; // Size of each space
        int quantity; // Number of storage spaces
        int next; // Next empty space
        unsigned char* storage; // Dynamically allocated array of bytes

        // Functions inside struct body
        void initialize(int size);
        void cleanup();
        int add(const void* element);
        void* fetch(int index);
        int count();
        void inflate(int increase);
    };
    */

    struct VectorStash {
        int size; // Size of each space
        int quantity; // Number of storage spaces
        int next; // Next empty space
        std::vector <char> storage; // Dynamically allocate char through vector

        // Functions inside struct body
        void initialize(int size);
        void cleanup();
        int add(const void* element);
        void* fetch(int index);
        int count();
        void inflate(int increase);
    };

    // Stash using a C++ classes.
    class Stash {
            int size; // Size of each space
            int quantity; // Number of storage spaces
            int next; // Next empty space
            unsigned char* storage; // Dynamically allocated array of bytes
            void inflate(int increase);

        public:
            // Functions inside struct body
            // Stash(int size); // removed due to addition of default argument.
            Stash(int size, int initQuantity = 0,int = 100);
            ~Stash();
            void initialize(int size); // Not required due to constructor, but kept for oldere programs.
            void cleanup(); // Not required due to destructor, but kept for oldere programs.
            int add(const void* element);
            void* fetch(int index);
            int count();    
    };

    // Stash using a mem class as storage.
    class memStash {
            int block_size;          // Block size
            int blocks_quantity;    // Blocks quantity
            int next;               // Next empty space
            Mem* storage;           // Storage, instead of unsigned char*
            void inflate(int increase);
        public:
            memStash(int block_size); // Zero quantity
            memStash(int block_size, int initQuantity);
            ~memStash();
            int add(void* element); // Adds element
            void* fetch(int index); // Returns element[index]
            int count();            
    };
}

namespace PushDownStack {

    /* // Stack implementation in C++ structure style.
    struct Stack {
        //  Structure og pushdown stack:
        //  initially head = 0
        //  after adding 4 dat value:
        //  dat1 <- dat2 <- dat3 <- dat4 <-head
        struct Link {
            void *data;
            Link *next;

            void initialize (void* dat, Link* nxt);
        } *head;

        void initialize();
        void push(void* dat);
        void* peek();
        void* pop();
        void cleanup();
    };
    */

    class Stack;

    void RecReverser(Stack*); // friend function to print stack in reverse.

    // Stack implementation in C++ Class style
    class Stack {
            /*  Structure og pushdown stack:
                initially head = 0
                after adding 4 dat value:
                dat1 <- dat2 <- dat3 <- dat4 <-head */
            struct Link {
                void *data;
                Link *next;
                Link(void *dat, Link* nxt);
                ~Link();
                void initialize (void* dat, Link* nxt);
            } *head;
        public:
            Stack();
            Stack(void* element,int sz);
            ~Stack();
            void initialize();
            void push(void* dat);
            void* peek();
            void* pop();
            void cleanup();
            friend void RecReverser(Stack*);
    };

}

namespace IntLinkedList {

    struct outerStruct {
        struct IntLList {
            int data;
            IntLList* nextPtr;

            IntLList():data(0),nextPtr(nullptr) {}  
        } base;

        outerStruct():base(){}
        void createLL(int count);
        void printDestroy();
    };
}

namespace HandlerClass {

    class Handle {
            struct Cheshire;
            Cheshire *smile;
        public:
            void initialize();
            void cleanup();
            int read();
            void change(int);
    };

    class StackImp {
        private:
            // int data[array_size]; // Variant with int[]
            vector<int> data;
            int head;
        public:
            StackImp(): data(0),head(-1){}
            void print();
            void push(int );
            int peek();
            int pop();
            bool empty();
        
    };

    class StackOfInt {
        private:
            StackImp intStack;
        public:
            StackOfInt():intStack(){}
            void print_stack();
            void push_to_stack(int);
            int peek_from_stack();
            int pop_from_stack();
            bool isEmpty();
    }; 
    
}

#endif // CLIB_H