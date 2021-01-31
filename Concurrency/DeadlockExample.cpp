mutex m1;
mutex m2;

void thread1() {
    m1.lock();
    this_thread::sleep_for(2ms);
    m2.lock(); //waiting on m2 since t2 has it
    cout << "Critical section of t1" << endl;
    m1.unlock();
    m2.unlock();
}

void thread2() {
    m2.lock();
    this_thread::sleep_for(2ms);
    m1.lock(); // waiting on m1 since t1 has it
    cout << "Critical section of t2" << endl;
    m2.unlock();
    m1.unlock();

}

void main() {

    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
    cout << "DONE!" << endl;
    system("PAUSE");
}
