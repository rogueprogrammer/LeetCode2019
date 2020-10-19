class ReadWriteLock {

public:
    mutex m;
    condition_variable writerCv;
    condition_variable readerCv;
    bool isWriterActive;
    bool isReaderActive;
    queue<condition_variable> cvQ;

    ReadWriteLock() {
        isWriterActive = false;
        isReaderActive = false;
    }

    
    void getNextCv() {
        unique_lock<mutex> lk(m);
        if (!cvQ.empty()) {
            cout << "Getting next cv..." << endl;
            condition_variable& cv = cvQ.front();
            cv.notify_all();
            cvQ.pop();
        }
        lk.unlock();
    }

    void readLock() {
        unique_lock<mutex> lk(m);
        while (isWriterActive) {
            cvQ.push(readerCv);
            readerCv.wait(lk);
        }
        cout << "ReadLock()" << endl;
        isReaderActive = true;
        lk.unlock();
    }

    void readUnlock() {
        unique_lock<mutex> lk(m);
        cout << "ReadUnlock()" << endl;
        isReaderActive = false;
        getNextCv();
        lk.unlock();
    }

    void writeLock() {
        unique_lock<mutex> lk(m);
        while (isWriterActive || isReaderActive) {
            cvQ.push(writerCv);
            writerCv.wait(lk);
        }
        cout << "WriteLock()" << endl;
        isWriterActive = true;
        lk.unlock();
    }

    void writeUnlock() {
        unique_lock<mutex> lk(m);
        cout << "WriteUnlock()" << endl;
        isWriterActive = false;
        getNextCv();
        lk.unlock();
    }

    
};
