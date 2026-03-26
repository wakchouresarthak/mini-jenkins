#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>
using namespace std;

class Job{
    private:
        int jobID;
    public:
        void task();
};
class Scheduler{
    private:
        queue<Job> jobQueue;
        mutex m;
        condition_variable cv;
        vector<thread> workers;
        bool stop = false;
    public:
        Scheduler(int);
        void submit(Job);
        void workerThread(int);
        ~Scheduler();
};