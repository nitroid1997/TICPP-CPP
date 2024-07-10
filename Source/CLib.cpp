#include "../Header/CLib.h"

#include <iostream>
#include <cassert>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

namespace TrivialObjects {

    void cmd_halter() {
        int cmd_halter;
        cin >> cmd_halter;
    }

};

namespace CLikeLib {

    // Quantity of elements to add
    // when increasing storage:
    const int increment = 100;

    void initialize (CStash* s, int sz) {
        s->size = sz;
        s->quantity = 0;
        s->storage = 0;
        s->next = 0;
    }

    void cleanup (CStash* s) {
        if(s->storage != 0) {
            cout << "freeing storage" << endl;
            delete []s->storage;
        }
    }

    int add (CStash* s, const void* element) {
        if(s->next >= s->quantity)  // is enough space left ?
            inflate(s,increment);
        // Copy element into storage, starting at next empty space.
        int startBytes = s->next * s->size;
        unsigned char *e = (unsigned char*)element;
        for(int i = 0; i < s->size; i++)
            s->storage[startBytes + i] = e[i];
        s->next++;
        return(s->next - 1); // Index number
    }

    void* fetch (CStash* s, int index) {
        // Check index boundaries:
        assert(0 <= index);
        if(index >= s->next)
            return 0; // To indicate the end
        // Produce pointer to desired element:
        return &(s->storage[index * s->size]);
    }

    int count (CStash* s) {
        return s->next; // Elements in CStash
    }

    void inflate (CStash* s, int increase) {
        assert(increase > 0);
        int newQuantity = s->quantity + increase;
        int newBytes = newQuantity * s->size;
        int oldBytes = s->quantity * s->size;
        unsigned char *b = new unsigned char [newBytes];
        for(int i = 0; i < oldBytes; i++)
            b[i] = s->storage[i]; // copy old to new
        delete [](s->storage); // old storage deleted
        s->storage = b; // point to new memory
        s->quantity = newQuantity;
    }

}

namespace CppLikeLib {

    // Quantity of elements to add
    // when increasing storage:
    const int increment = 100;

    /*
    Stash::Stash(int sz) {
        size = sz;
        quantity = 0;
        storage = 0;
        next = 0;
    }
    */

    Stash::Stash(int sz, int initQuantity, int reserve_word /*no warning msg for unused reserve argument, it is set to a default value in declaration.*/) {
        size = sz;
        quantity = 0;
        storage = 0;
        next = 0;
        inflate(initQuantity);
    }

    Stash::~Stash() {
        if(storage != 0) {
            cout << "freeing storage" << endl;
            delete []storage;
        }
    }

    void Stash::initialize (int sz) {
        size = sz;
        quantity = 0;
        storage = 0;
        next = 0;
    }

    void Stash::cleanup () {
        if(storage != 0) {
            cout << "freeing storage" << endl;
            delete []storage;
        }
    }

    int Stash::add (const void* element) {
        if(next >= quantity)  // is enough space left ?
            inflate(increment);
        // Copy element into storage, starting at next empty space.
        int startBytes = next * size;
        unsigned char *e = (unsigned char*)element;
        for(int i = 0; i < size; i++)
            storage[startBytes + i] = e[i];
        next++;
        return(next - 1); // Index number
    }

    void* Stash::fetch (int index) {
        // Check index boundaries:
        assert(0 <= index);
        if(index >= next)
            return 0; // To indicate the end
        // Produce pointer to desired element:
        return &(storage[index * size]);
    }

    int Stash::count () {
        return next; // Elements in CStash
    }

    void Stash::inflate (int increase) {
        assert(increase >= 0);
        int newQuantity = quantity + increase;
        int newBytes = newQuantity * size;
        int oldBytes = quantity * size;
        unsigned char *b = new unsigned char [newBytes];
        for(int i = 0; i < oldBytes; i++)
            b[i] = storage[i]; // copy old to new
        delete [](storage); // old storage deleted
        storage = b; // point to new memory
        quantity = newQuantity;
    }

    // VectorStash:

    void VectorStash::initialize (int sz) {
        size = sz;
        quantity = 0;
        storage.reserve(100);
        next = 0;
    }

    void VectorStash::cleanup () {
        if(!(storage.empty())) {
            cout << "freeing storage" << endl;
            storage.clear();
        }
    }

    int VectorStash::add (const void* element) {
        if(next >= quantity)  // is enough space left ?
            inflate(increment);
        // Copy element into storage, starting at next empty space.
        int startBytes = next * size;
        unsigned char *e = (unsigned char*)element;
        for(int i = 0; i < size; i++)
            storage[startBytes + i] = e[i];
        next++;
        return(next - 1); // Index number
    }

    void* VectorStash::fetch (int index) {
        // Check index boundaries:
        assert(0 <= index);
        if(index >= next)
            return 0; // To indicate the end
        // Produce pointer to desired element:
        return &(storage[index * size]);
    }

    int VectorStash::count () {
        return next; // Elements in CStash
    }

    void VectorStash::inflate (int increase) {
        assert(increase > 0);
        int newQuantity = quantity + increase;
        int newBytes = newQuantity * size;
        storage.resize(newBytes);
    }
    
    // Stash using mem as storage.

    memStash::memStash(int sz) : storage(new Mem(sz)) {
        block_size = sz;
        blocks_quantity = 0;
        next = 0;
    }

    memStash::memStash(int sz, int initQuantity) : storage(new Mem(sz * initQuantity)) {
        block_size = sz;
        blocks_quantity = 0;
        next = 0;
        inflate(initQuantity);
    }

    memStash::~memStash() {
        if(storage != 0) {
            cout << "Freeing storage..." << endl;
            delete storage;
        }
    }

    void memStash::inflate(int increase) {
        int newQuantity = blocks_quantity + increase;
        blocks_quantity = newQuantity;
        int newMemory = newQuantity * block_size;
        storage->ensureMinSize(newMemory);
    }

    int memStash::add(void* element) {

        if(next >= blocks_quantity)
            inflate(increment);
        // Copy element into storage,
        // starting at next empty space:
        int startBytes = next * block_size;
        unsigned char* e = (unsigned char*)element;
        byte* temp = storage->pointer();
        for(int i = 0; i < block_size; i++)
            *(temp + startBytes + i) = e[i];
        next++;
        return(next - 1); // Index number
    }

    void* memStash::fetch(int index) {
        if(index >= next)
            return 0; // To indicate the end
        // Produce pointer to desired element:
        byte* temp = storage->pointer();
        return (temp + index * block_size);
    }

    int memStash::count() {
        return next; // Number of elements in CStash
    }
}

namespace PushDownStack {

    Stack::Link::Link(void *dat, Link *nxt) {
        data = dat;
        next = nxt;
    }

    Stack::Link::~Link() {}

    void Stack::Link::initialize (void* dat, Link* nxt) {
        data = dat;
        next = nxt;
    }

    Stack::Stack() {
        head = 0;
    }

    Stack::Stack(void* element,int sz) {
        head = 0;
        for(int i = 0; i < sz; i++)
            this->push(((string*)element+i));
    }

    void Stack::initialize () {
        head = 0;
    }

    void Stack::push (void* dat) {
        /* // Old defination of push.
        Link* newLink = new Link;
        newLink -> initialize (dat,head);
        head = newLink;
        */
        head = new Link(dat, head);
    }

    void* Stack::peek () {
        if (head != 0)
            return head -> data;
        return 0;
    }

    void* Stack::pop () {
        if (head == 0) return 0;
        void* result = head -> data;
        Link* oldHead = head;
        head = head->next;
        delete oldHead;
        return result;
    }

    Stack::~Stack() {
        if (head!=0)
            cout << "Delete more element" << endl;
        else
            cout << "Stack is empty !" << endl;
    }

    void Stack::cleanup () {
        if (head!=0)
            cout << "Delete more element" << endl;
        else
            cout << "Stack is empty !" << endl;
    }

    void RecReverser(Stack* textlines) {
        string *s = (string*)textlines->pop();
        if(s!=nullptr) {
            RecReverser(textlines);
            cout << *s << "\n";
            delete s;
        }
    }

}

namespace IntLinkedList {

    void outerStruct::createLL(int count) {
        IntLList* tempPtr = &base;
        for(int i = 1; i <= count; i++) {
            IntLList* newPtr = new IntLList;
            newPtr->data = i;
            newPtr->nextPtr = nullptr;
            tempPtr->nextPtr = newPtr;
            tempPtr = newPtr;
        }
    }

    void outerStruct::printDestroy() {
        IntLList* tempPtr = &base;

        while(tempPtr != nullptr) {
            cout << tempPtr << ": " << tempPtr->data << endl;
            tempPtr = tempPtr->nextPtr;
        }

        IntLList* delPtr;
        tempPtr = base.nextPtr;
        while(tempPtr != nullptr) {
            delPtr = tempPtr;
            tempPtr = tempPtr->nextPtr;
            cout << "deleting " << delPtr << ": " << delPtr->data << "..." << endl;
            delete delPtr;        
        }
        base.nextPtr = nullptr;
    }

}

namespace HandlerClass {
    
    struct Handle::Cheshire{
            int i;
    };

    void Handle::initialize() {
        smile = new Cheshire;
        smile->i = 0;
    }

    void Handle::cleanup() {
        delete smile;
    }

    int Handle::read() {
        return smile->i;
    }

    void Handle::change(int x) {
        smile->i = x;
    }

    void StackImp::print() {
        for (int i = head; i >= 0; i--)
            cout << data[i] << ' ';
        cout << endl;
    }

    void StackImp::push(int x) {
        // Variant with int[]
        //if (head >= array_size) {
        //    cout << "Stack is full!" << endl;
        //    return;
        //}
        cout << "Push(" << x << ")" << endl;
        //data[++head] = x;
        data.push_back(x);
        head++;
    }

    int StackImp::peek() {
        return (head >= 0) ? data[head] : 0;
    }

    int StackImp::pop() {
        if (head == -1)
            return 0;
        cout << "Pop(" << data[head] << ")" << endl;
        int element = data[head];
        data[head--] = 0;
        return element;
    }

    bool StackImp::empty() {
        return (head == -1);
    }

    void StackOfInt::print_stack() {
        intStack.print();
    }

    void StackOfInt::push_to_stack(int x) {
        intStack.push(x);
    }

    int StackOfInt::peek_from_stack() {
        return intStack.peek();
    }

    int StackOfInt::pop_from_stack() {
        return intStack.pop();
    }

    bool StackOfInt::isEmpty() {
        return intStack.empty();
    } 

}


