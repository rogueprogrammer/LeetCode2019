
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
    int boundary;
    int numLeaves;

    bool powerOf2(int x) {
        return x & (x - 1) == 0;
    }

    PhoneDirectory(int maxNumbers) {
        bits.set(); //set all bits to 1, as they are all available
        maxVal = maxNumbers;
        boundary = maxVal + maxVal - 1;
        // calculate offset
        if (!powerOf2(maxVal)) {
            int next = log2(maxVal) + 1;
            numLeaves = pow(2, next);
        }
        else {
            numLeaves = maxVal;
        }
    }

    /*
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
    */


    int get() {

        int i = 0;
        while (1) {
            int leftChild = i * 2 + 1;
            int rightChild = i * 2 + 2;

            // if left child out of range, break
            if (leftChild >= (numLeaves + numLeaves - 1)) {
                break;
            } //if i is more than numLeaves - 1 + maxVal

            if (bits[leftChild] == 1) {
                i = leftChild;
            }
            else if (bits[rightChild] == 1) {
                i = rightChild;
            }
            else {
                return -1;
            }
        }
        if (i >= numLeaves - 1 + maxVal) {
            return -1;
        }

        bits[i] = 0;
        updateTree(i);

        return i - numLeaves + 1;
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
        return bits[numLeaves - 1 + number];

    }

    /** Recycle or release a number. */
    void release(int number) {
        bits[numLeaves-1+number] = 1;
        updateTree(numLeaves-1+number);
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
