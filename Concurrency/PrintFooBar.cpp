// https://leetcode.com/problems/print-foobar-alternately/

class FooBar {
private:
    int n;
    mutex m;
    int count;
    condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        this->count = 0;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lk(m);
        for (int i = 0; i < n; i++) {
            while(count % 2 != 0){
                cv.wait(lk);
            }
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            ++count;
            cv.notify_one();
        }
        lk.unlock();
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lk(m);
        for (int i = 0; i < n; i++) {
            while(count % 2 == 0){
                cv.wait(lk);
            }
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            ++count;
            cv.notify_one();
        }
        lk.unlock();
    }
};
