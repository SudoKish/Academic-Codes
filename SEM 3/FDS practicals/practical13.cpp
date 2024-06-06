// Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++ program for simulating job queue. Write functions to add job and delete job from queue.

#include <iostream>
#include <queue>

using namespace std;

class Job {
public:
    int id;
    int burstTime;

    Job(int id, int burstTime) {
        this->id = id;
        this->burstTime = burstTime;
    }
};

void addJob(queue<Job*> &jobQueue, int id, int burstTime) {
    jobQueue.push(new Job(id, burstTime));
}

void deleteJob(queue<Job*> &jobQueue) {
    if (!jobQueue.empty()) {
        cout << "Job with ID " << jobQueue.front()->id << " and burst time " << jobQueue.front()->burstTime << " is deleted." << endl;
        delete jobQueue.front();
        jobQueue.pop();
    } else {
        cout << "Job queue is empty." << endl;
    }
}

int main() {
    queue<Job*> jobQueue;

    addJob(jobQueue, 1, 10);
    addJob(jobQueue, 2, 5);
    addJob(jobQueue, 3, 8);

    deleteJob(jobQueue);
    deleteJob(jobQueue);

    addJob(jobQueue, 4, 12);

    deleteJob(jobQueue);
    deleteJob(jobQueue);

    return 0;
}
