// https://leetcode.com/problems/design-phone-directory/
/*
this problem is to allocate an available number from (0-n)
the easy solution is to maintain a set of numbers that are allocated and deallocated, and whenever a call to get() made, 
return the first element from the deallocated set. if deallocated is empty, then use a variable which contains the next highest number that isn't allocated.
this algo is O(1) runtime, and O(n) space.

to optimize space complexity, can use a bitset where bitset[i] = 1 if a particular bit is available and 0 if already allocated.
searching for next available bit can be utilized with segment tree search O(logn) algorithm if segment tree is used.
left part of bitset is the segment tree
bitset structure:
{[0, ..., maxVal][maxVal+1, ..., 2maxVal]}
0, ..., maxVal = segment tree
maxVal+1, ..., 2maxVal = actual bitset of values that are 0, 1 if num at index i is allocated
eg:
consider bitset: 0, 1, 1, 1

segment tree constructed by doing bitwise or on all the leaves:
        1
   0         1
0    1     1    1
thus, the bitset structure would be:
[1, 0, 1, 0, 1, 1, 1]
note that going from left tree nodes to actual bits, from parent to child => left child = (2*i)+1, right child = (2*i+2)
going to parent is just: i-1/2
segment tree search can be used to get to parents and children by checking if each child is 1 or not. if it's 1, that means that somewhere down the path, an available
bit will be there.

*/

class PhoneDirectory {
public:
    bitset<20000> bits; //let bits[i] = 1 if available 0 if allocated
    int maxVal;
    bool odd; //if number of values is odd

    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        bits.set(); //set all bits to 1, as they are all available
        maxVal = maxNumbers;
        odd = maxVal % 2 == 1;
    }

    void printBits() {
        for (int i = 0; i < maxVal*2; ++i) {
            cout << i << "  ";
        }
        cout << endl;
        for (int i = 0; i < maxVal*2; ++i) {
            cout << bits[i] << "  ";
        }
        cout << endl;
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int i = 0;
        while (i <= maxVal - 1) {
            if (bits[i * 2 + 1] == 1) {
                i = i * 2 + 1;
            }
            else if (bits[i * 2 + 2] == 1) {
                i = i * 2 + 2;
            }
            else {
                break;
            }
        }
        bits[i] = 0;
        updateSegmentTree(i);
        if (odd == true) {
            return i - maxVal;
        }
        else {
            return i - maxVal + 1;
        }
    }

    
  
    void updateSegmentTree(int i) {
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
        if (odd) {
            return bits[maxVal + number];
        }
        else {
            return bits[maxVal + number - 1];
        }
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (odd) {
            bits[maxVal + number] = 1;
        }
        else {
            bits[maxVal + number - 1] = 1;
        }
        updateSegmentTree( maxVal+number-1);
    }
};


void main() {

    PhoneDirectory* ph = new PhoneDirectory(3);
    int next = ph->get();
    //cout << next << endl;
    //ph->printBits();
    //cout << endl;

    next = ph->get(); // 1

    next = ph->get(); //2

    bool ch = ph->check(2);
    ph->release(2);
    ch = ph->check(2);
    


    /*PhoneDirectory* ph = new PhoneDirectory(4);
    
    int next = ph->get();
    cout << next << endl;
    ph->printBits();
    cout << endl;
    
    next = ph->get();
    cout << next << endl;
    ph->printBits();
    cout << endl;
    
    next = ph->get();
    cout << next << endl;
    ph->printBits();
    cout << endl;

    next = ph->get();
    cout << next << endl;
    ph->printBits();
    cout << endl;

    ph->release(0);
    next = ph->get();
    cout << next << endl;
    ph->printBits();
    cout << endl; */



	system("PAUSE");
}
