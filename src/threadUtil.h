#pragma once
#ifndef THREADUTIL_H
#define THREADUTIL_H

#include "world.h"

#include <thread>
#include<condition_variable>
#include<mutex>
#include<barrier>

const int max_threads = 4;//std::thread::hardware_concurrency();
const size_t numthreads = max_threads;

//barrier sync_point(numthreads, [](){cout << "barrier success\n";});


vector<int> partition_vector(int total);
void thread_func(int start, int end, World* w, int id);
void create_thread(int numthreads, World* w, vector<int> partitionVals);
void main_thread_func(World*  w);

#endif