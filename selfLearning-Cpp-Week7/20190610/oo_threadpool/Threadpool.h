 ///
 /// @file    Threadpool.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-10 15:09:09
 ///
 
#pragma once

#include "TaskQueue.h"
#include "Thread.h"
#include "Task.h"
#include <vector>
#include <memory>

using namespace std;

namespace wd
{

class Threadpool
{
	friend class WorkerThread;
public:
	Threadpool(size_t threadNum, size_t queSize)
	: _threadNum(threadNum)
	, _queSize(queSize)
	, _taskque(queSize)
	, _isExit(false)
	{
		_threads.reserve(_threadNum);
	}

	void start();
	void stop();
	void addTask(Task * task);
private:
	void threadFunc();
	Task * getTask();

private:
	size_t _threadNum;
	size_t _queSize;
	vector<unique_ptr<Thread>> _threads;
	TaskQueue _taskque;
	bool _isExit;
};

}//end of namespace wd
