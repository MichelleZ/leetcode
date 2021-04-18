// Source: https://leetcode.com/problems/the-dining-philosophers/
// Author: Miao Zhang
// Date:   2021-04-18

class DiningPhilosophers {
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int l = philosopher;
        int r = (philosopher + 4) % 5;
        if (philosopher % 2 == 0) { // left -> right
            lock[l].lock();
            pickLeftFork();
            lock[r].lock();
            pickRightFork();
        } else {
            lock[r].lock();
            pickRightFork();
            lock[l].lock();
            pickLeftFork();
        }
        
        eat();
        putLeftFork();
        lock[l].unlock();
        putRightFork();
        lock[r].unlock();
    }

private:
    std::mutex lock[5];
};
