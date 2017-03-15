#ifndef THREAD_PROCESS_H_INCLUDED
#define THREAD_PROCESS_H_INCLUDED
#include "io.h"
#include <pthread.h>
#include "utility.h"

void *MaxPop_thread(void* arg );
dados* processa_threads(int n_threads, dados *arg);

#endif // THREAD_PROCESS_H_INCLUDED
