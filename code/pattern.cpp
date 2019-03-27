/**
	\author: Trasier
	\date: 2019.01.04
*/
#include <bits/stdc++.h>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,1024000")
#include "global.h"
#include "monitor.h"

double* responses = NULL;
int atn = 0, awn = 0;
int* avaTasks = NULL;
int* avaWorkers = NULL;
int* tCand = NULL, wCand = NULL;

void init() {
	vaTasks = new int[taskN];
	avaWorkers = new int[wokerN];
	tCand = new int[taskN];
	wCand = new int[workerN];
	responses = new double[taskN];
	for (int i=0; i<taskN; ++i)
		responses[i] = -1.0;
	
	#ifdef WATCH_MEM
	watchSolutionOnce(getpid(), usedMemory);
	#endif
}

void calcResult() {
	int cnt = 0;
	
	totTime = calc_time(begProg, endProg);
	for (int i=0; i<taskN; ++i) {
		if (responses >= 0) {
			avgTime += responses[i] - tasks[i].at;
			++cnt;
		}
	}
	
	#ifdef DEBUG
	assert(cnt == obj);
	#endif
	
	if (cnt > 0)
		avgTime /= cnt;
}

void Delete(){
	delete[] responses;
	delete[] tasks;
	delete[] workers;
	delete[] avaTasks;
	delete[] avaWorkers;
	delete[] wCand;
	delete[] tCand;
}

void taskArrive(int tid) {
	const task_t& t = tasks[tid];
	int k = 0;
	
	for (int i=0; i<awn; ++i) {
		int wid = avaWorkers[i];
		if (checkRange(t, workers[wid]) && checkDeadline(t, workers[wid])) {
			wCand[k++] = i;
		}
	}
	
	if (k == 0) {
		avaTasks[atn++] = tid;
	} else {
		int r = rand() % k, wid = avaWorkers[r];
		swap(avaWorkers[awn-1], avaWorkers[r]);
		--awn;
		
		++obj;
		responses[tid] = t.at;
	}
}

void workerArrive(int wid) {
	const worker_t& w = workers[wid];
	int k = 0;
	
	for (int i=0; i<atn; ++i) {
		int tid = avaTasks[i];
		if (checkRange(tasks[tid], w) && checkDeadline(tasks[tid], w)) {
			tCand[k++] = i;
		}
	}
	
	if (k == 0) {
		avaWorkers[awn++] = wid;
	} else {
		int r = rand() % k, tid = avaTasks[r];
		swap(avaTasks[atn-1], avaTasks[r]);
		--atn;
		
		++obj;
		responses[tid] = w.at;
	}
}

void solve(){
	int tid = 0, wid = 0;
	
	init();
	while (tid<taskN && wid<workerN) {
		if (tasks[tid].at <= workers[wid].at) {
			taskArrive(tid);
			++tid;
		} else {
			workerArrive(wid);
			++wid;
		}
	}
	while (tid < taskN) {
		taskArrive(tid, wid);
		++tid;
	}
	while (wid < workerN) {
		workerArrive(tid, wid);
		++wid;
	}
	
	#ifdef WATCH_MEM
	watchSolutionOnce(getpid(), usedMemory);
	#endif
}

int main(int argc, char **argv) {
	string fileName;
	
	if (argc > 1) {
		fileName = string(argv[1]);
	} else {
		fileName = "./data.txt";
	}
	
	readInput(fileName);
	
	save_time(begProg);
	solve();
	save_time(endProg);

	
	calcResult(begProg, endProg);
    dumpResult("Greedy", obj, totTime, avgTime, memUsage);
	fflush(stdout);
	Delete();
	
	return 0;
}