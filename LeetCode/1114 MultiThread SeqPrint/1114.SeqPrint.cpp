

#include <functional>
#include <mutex>

using namespace std;


class Foo {
public:
    Foo() {

    }

    void first(std::function<void()> printFirst) {
        // 等待直至 main() 发送数据
        std::unique_lock<std::mutex> lk(g_mutex);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        // 通知前完成手动解锁，以避免等待线程才被唤醒就阻塞（细节见 notify_one ）
        counter++;
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(g_mutex);
        cv1.wait(lk, [this]() {return counter == 2; }); // 阻塞当前线程，直到条件变量被唤醒
                                                        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        counter++;
        cv2.notify_one();
    }

    void third(function<void()> printThird) {

        std::unique_lock<std::mutex> lk(g_mutex);
        cv2.wait(lk, [this]() {return counter == 3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    int counter = 1;
    std::condition_variable cv1;
    std::condition_variable cv2;
    // 使用lock和unlock手动加锁
    std::mutex g_mutex;
};

/**
 * 1. std::lock_guard 和 std::unique_lock
 * 1.1 std::lock_guard 在构造函数中进行加锁，析构函数中进行解锁。
 * 1.2 类 unique_lock 是通用互斥包装器，允许延迟锁定、锁定的有时限尝试、递归锁定、所有权转移和与条件变量一同使用。
 * unique_lock 比 lock_guard 使用更加灵活，功能更加强大。
 * 使用 unique_lock 需要付出更多的时间、性能成本。
 *
 *
 * 2. 条件变量 (condition_variable)
 * 条件变量实际上是condition_variable类的对象，通过这个对象可以实现对调用线程的阻塞。条件变量往往需要绑定一个unique_lock(也是互斥锁的一种实现)，当在线程中通过条件变量调用wait函数时，
 * 该线程就会被阻塞住，直到在另一个线程中调用notify函数来唤醒这个线程。
 * 而对于其中的“wait函数”，它需要两个参数，一个unique_lock对象，和一个bool型的调用对象（可以通过lambda表达式实现，或者自定义一个bool型函数）。
 * 调用wait时，会执行以下步骤：1) 对绑定的unique_lock对象解锁；2) 判断调用对象的返回值。如果调用对象返回值为false，则wait就一直阻塞，一直等待被notify唤醒；如果调用对象为true，则会对绑定的unique_lock对象重新上锁，然后wait函数返回，继续执行后续的程序。
 *当wait被notify唤醒时，会先重新对绑定的unique_lock对象上锁，然后执行上面的1)2)。

 */