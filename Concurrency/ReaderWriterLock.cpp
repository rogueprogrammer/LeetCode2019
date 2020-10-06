#include "Header.h"
#include <condition_variable>
#include <thread>         
#include <mutex>          


// https://en.wikipedia.org/wiki/Readers%E2%80%93writer_lock
// https://stackoverflow.com/questions/12033188/how-would-you-implement-your-own-reader-writer-lock-in-c11
// https://stackoverflow.com/questions/27860685/how-to-make-a-multiple-read-single-write-lock-from-more-basic-synchronization-pr


// will there be starvation for reader or writer here?

class ReaderWriterLock {

private:
    mutex m;
    condition_variable writerCV;
    condition_variable readerCV;
    bool isWriterActive;
    int numReadersActive;
    int numWritersWaiting;
    /*
    
        File

        r, r, r       w
        WRITER THREAD
        if readers active -> Writer thread waits
        if writers active -> Writer thread waits
        If no readers or writers active -> Writer thread acquires lock

        READER THREAD
        if 0 or more readers active -> Reader can acquire lock
        if writer active -> reader waits

        We need two condition variables so we know which group of threads to wake up, reader or writer
        do we even need to know numReadersActive? is the variable necessary?
    
    
    */



public:

    ReaderWriterLock() {
        numReadersActive = 0;
        numWritersWaiting = 0;
        isWriterActive = false;
    }

    void readLock() {
        unique_lock<mutex> lk(m);
        while (isWriterActive || numWritersWaiting > 0) {
            readerCV.wait(lk);
        }
        ++numReadersActive;
        lk.unlock();
    }

    void readUnlock() {
        unique_lock<mutex> lk(m);
        --numReadersActive;
        writerCV.notify_one();
        lk.unlock();
    }

    void writeLock() {
        unique_lock<mutex> lk(m);
        ++numWritersWaiting;
        while (isWriterActive || numReadersActive > 0) {
            writerCV.wait(lk);
        }
        isWriterActive = true;
        --numWritersWaiting;
        lk.unlock();
    }

    void writeUnlock() {
        unique_lock<mutex> lk(m);
        isWriterActive = false;
        if (numWritersWaiting > 0) {
            writerCV.notify_one();
        }
        else {
            readerCV.notify_all();
        }
        lk.unlock();
    }

};





void main() {
    

    system("PAUSE");
}
