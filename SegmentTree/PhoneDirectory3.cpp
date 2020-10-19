#include "Header.h"
#include <time.h>
#include <mutex>
#include <thread>


class PhoneDirectory {
public:
       
    /*
    allocate(4)  //{0, 1, 2, 3}
    int x = get(); //x is 0
    release(0);
    //x = get();
          1, 0
       0, 1            1, 2
     0, 3  0, 4     1, 5   1, 6
    [0, 1, 2, 3, ][0, 1, 2, 3]

    */
    int maxVal;
    int totalBits; // last bit in the bitset
    bitset<20000> bits;
    int offset;
    PhoneDirectory(int maxNumbers) {
        bits.set(); // set all bits to 1
        maxVal = maxNumbers;
        totalBits = maxVal - 1 + maxVal;

        // calculate offset
        if (!powerOf2(maxVal)) {
            int next = log2(maxVal) + 1;
            offset = pow(2, next);
        }
        else {
            offset = 0;
        }
    }
    bool powerOf2(int x) {
        return x & (x-1) == 0;
    }

    
    int get() {
        int index = 0;
        // the leaf nodes's index is among [offset, offset + MAX_ID]
        while (1) {
            int leftChild = index * 2 + 1;
            int rightChild = index * 2 + 2;
            if (rightChild >= offset + maxVal) {
                break;
            }
            if (bits[leftChild] == 1) {
                index = leftChild;
            }
            else if (bits[index * 2 + 2] == 1) {
                index = rightChild;
            }
            else {
                return -1;
            }
        }
        // not found if the leaf nodes's index is outside [offset, offset + MAX_ID]
        if (index >= offset + maxVal - 1) {
            return -1;
        }
        bits[index] = 0;
        updateTree(index);
        // the id = index - offset + 1
        return index - offset + 1;

    }

    void updateTree(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            int sibling;
            if (i % 2 == 1) { // i is left child
                sibling = bits[i + 1]; //get right sibling
            }
            else {
                sibling = bits[i - 1]; // get left sibling
            }
            bits[parent] = bits[i] | sibling;
            i = parent;
        }
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return bits[maxVal - 1 + number];
    }

    /** Recycle or release a number. */
    void release(int number) { 
        bits[maxVal - 1 + number] = 1;
        //update parents in segment tree
        updateTree(number);
    }
};



void main() {
    /*


    n=5


    1       1        1         1


    */
    PhoneDirectory* ph = new PhoneDirectory(5);
    cout <<"New ID: " << ph->get() << endl;
    cout << "New ID: " << ph->get() << endl;
    cout << "New ID: " << ph->get() << endl;
    cout << "New ID: " << ph->get() << endl;
    cout << "New ID: " << ph->get() << endl;
    cout << "New ID: " << ph->get() << endl;
    cout << "New ID: " << ph->get() << endl;


	system("PAUSE");
}
