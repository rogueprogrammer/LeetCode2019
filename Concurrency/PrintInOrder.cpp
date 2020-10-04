
//https://leetcode.com/problems/print-in-order/submissions/
class Foo {
public:
    mutex m;
    condition_variable cv;
    int count;
    
    Foo() {
        count = 3;    
    }


    void first(function<void()> printFirst) {
        
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this]{return count == 3;});
        count = 2;
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this]{return count == 2;});
        count = 1;
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this]{return count == 1;});
        count = 1;
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        cv.notify_all();
    }
};
