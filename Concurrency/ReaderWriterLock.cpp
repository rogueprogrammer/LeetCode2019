//
// https://en.wikipedia.org/wiki/Readers%E2%80%93writer_lock
// https://stackoverflow.com/questions/12033188/how-would-you-implement-your-own-reader-writer-lock-in-c11
// https://stackoverflow.com/questions/27860685/how-to-make-a-multiple-read-single-write-lock-from-more-basic-synchronization-pr


// are 2 condition variables needed, one for reader and one for writer? or one is fine?
// will there be starvation for reader or writer here?

class ReaderWriterLock {

private:
    mutex m;
    condition_variable cv;
    int numWritersWaiting;
    int numReadersActive;
    bool writerCurrentlyWriting;

public:

    ReaderWriterLock() {
        numWritersWaiting = 0;
        numReadersActive = 0;
        writerCurrentlyWriting = false;
    }

    void readLock() {
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this] { return numWritersWaiting == 0 && writerCurrentlyWriting; }); // take this lock if writers aren't after it and writer isn't writing
        ++numReadersActive;
        lk.unlock();
    }

    void readUnlock() {

        unique_lock<mutex> lk(m);
        --numReadersActive;
        lk.unlock();
        cv.notify_one();
    }

    void writeLock() {
        unique_lock<mutex> lk(m);
        ++numWritersWaiting;
        while (numReadersActive > 0 && writerCurrentlyWriting) {
            cv.wait(lk);
        }
        writerCurrentlyWriting = true;
        lk.unlock();
    }

    void writeUnlock() {
        unique_lock<mutex> lk(m);
        --numWritersWaiting;
        writerCurrentlyWriting = false;
        if (numWritersWaiting > 1) {
            cv.notify_all();
        }

        lk.unlock();
    }

};
