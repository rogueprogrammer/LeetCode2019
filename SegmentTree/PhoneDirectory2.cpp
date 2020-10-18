#include "Header.h"
#include <time.h>
#include <mutex>
#include <thread>


class PhoneDirectory {
public:
    bitset<20000> bits; //let bits[i] = 1 if available 0 if allocated
    int maxVal;
    int boundary;
    

    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        bits.set(); //set all bits to 1, as they are all available
        maxVal = maxNumbers;
        boundary = maxVal + maxVal - 1;
    }

    int get() {
        int index = 0;
        while (index < maxVal) {
            int leftChild = index * 2 + 1;
            int rightChild = index * 2 + 2;
            if (leftChild >= boundary) {
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
        bits[index] = 0;
        updateTree(index);

        return index-maxVal+1;
    }

    void updateTree(int i) {
            while (i > 0) {
                int parent = (i - 1) / 2;
                int sibling;
                if (i % 2 == 1) { //left child
                    sibling = bits[i + 1];
                }
                else {
                    sibling = bits[i - 1];
                }
                bits[parent] = bits[i] | sibling;
                i = parent;
            }

        
    }


    /** Check if a number is available or not. */
    bool check(int number) {
        return number >= 0 and number < maxVal and bits[number + maxVal];

    }

    /** Recycle or release a number. */
    void release(int number) {
        int i = maxVal + number;
        while (i > 0) {
            bits[i] = 1;
            i /= 2;
        }
    }

    void printBits() {
        for (int i = 0; i < maxVal * 2; ++i) {
            cout << i << "  ";
        }
        cout << endl;
        for (int i = 0; i < maxVal * 2; ++i) {
            cout << bits[i] << "  ";
        }
        cout << endl;
    }
};



void main() {
    /*


    n=5


    1       1        1         1


    */
    PhoneDirectory* ph = new PhoneDirectory(4);
    cout <<"New ID: " << ph->get() << endl;
    cout << "New ID: " << ph->get() << endl;
    cout << "New ID: " << ph->get() << endl;
    cout << "New ID: " << ph->get() << endl;
    cout << "New ID: " << ph->get() << endl;
    cout << "New ID: " << ph->get() << endl;
    cout << "New ID: " << ph->get() << endl;


	system("PAUSE");
}
