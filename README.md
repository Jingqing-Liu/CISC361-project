# CISC361-project

Project execution instructions:

In order to compile the program and generate the a.out file, we should do the following command in the terminal!
In terminal:
1. cd <folder name>
2. g++ -std=c++11 Main.cpp
3. ./a.out
The result will display in the terminal window.
If you choose to execute the program and get the result via Eclipse, simply build it and run it.

  
In this project, we have designed and implemented a program that simulated the job scheduling, CPU scheduling, and deadlock avoidance of an operating system.
We used C++ language to make this project work as we expected. We implemented Shortest Job First and First In First Out methods in job scheduling(especially in Queue 1 and Queue 2) and the Round Robin method in process scheduling(with a quantum). Moreover, we also implemented the Banker’s Algorithm to avoid deadlock.

- If there is a completion of a job, check Wait Queue then the two Hold Queues.
- When a job completes, it releases main memory and implicitly releases the devices.
- The only constraints to move from one of the Hold Queues to the Ready Queue are main memory and devices.
- Priority is for the job scheduling, not process scheduling.
- if more resources are needed for a job than in the system then do not consider that job.
- If jobs have same run-time and same priority, use FIFO scheduling (FIFO within SJF).
- Handle all internal events before external.
- Internal Event: The events that are related to the CPU quantum (i.e., execution, completion, and quantum interruption) are considered as internal events. When a device requests or releases devices that is an internal event.
- External Event: Arrival of new jobs (reading from the file) and display events are considered as external events.
- There will never be two external events at the same time.
- The program must not read the entire input file in the beginning of the program to preprocess or use any advanced information. Execution is line by line and your program’s operations should not, for example, use future information about device requests.
- When an external release occurs and jobs are still in Ready Queue, check the Wait Queue
- to determine if something can start (i.e., get into the Ready Queue).
- Devices are only requested by jobs while running on the CPU, and if this happen, the job’s time slice is interrupted.
- On an arrival, the “S=” denotes the maximum number of device(s) the job will ever use.
- Pretend to allocate devices before using Banker’s.
- A job that requests a device in the middle of a time quantum, whether it gets the device or not, does NOT finish its time quantum. It blocks immediately.
- Do not use an array of size 100 for jobs.
