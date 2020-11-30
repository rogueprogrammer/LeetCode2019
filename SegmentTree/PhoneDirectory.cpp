// https://leetcode.com/problems/design-phone-directory/
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
        // important note: if inputted numbers is not a power of 2, then you need to make it a power of 2 by incrementing the log2 base. example, 
        // if you have 7 nodes then log2(7) = 2. add one and you will get 3. thus you should have 2^3 = 8 leaves. this will make the tree to be complete, which is necessary
        // for the get() function to work.
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
