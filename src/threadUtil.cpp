#include "threadUtil.h"
int phase = 0;
std::barrier sync_point(numthreads, [](){});

vector<int> partition_vector(int total){
  vector<int> parts;
  int leftover = total % numthreads;
  if(leftover>0){   //case where total alive isn't divisible by max threads
    int section_size = (total - leftover) / numthreads;
    int temp_size = section_size+1;
    for (int i = 0; i<leftover; i++){   //adds 1 extra to group of cells until no more remainder
      parts.push_back(temp_size*i);
      //printf("%d ", parts.back());
      parts.push_back(temp_size*(i+1) -1);
      //printf("%d\n", parts.back());
    }
    int temp = parts.back() + 1;
    for (int i = 0; i<(numthreads - leftover); i++){   //completes remaining groups with normal size
      parts.push_back(temp + section_size*i);
      //printf("%d ", parts.back());
      parts.push_back(temp + section_size*(i+1) -1);
      //printf("%d\n", parts.back());
    }
  }
  else{   //case where alive is divisible by max threads
    int section_size = total / numthreads;
      for (int i = 0; i<(numthreads - leftover); i++){   //splits alive into equal parts
        parts.push_back(section_size*i);
        //printf("%d ", parts.back());
        parts.push_back(section_size*(i+1) -1);
       // printf("%d\n", parts.back());
      }
  }

  return parts;
}

void thread_func(int start, int end, World* w, int id){
  if(phase == 1){
    w->play(start, end);
  }
  else if(phase == 2){
    w->cleanup(start, end);
    //sync_point.arrive_and_wait();
  }
  else if(phase ==3){
    w->setAlive(start,end);
    //sync_point.arrive_and_wait();
  }
  //printf("%d at barrier\n", id);
  sync_point.arrive_and_wait();  
}

void create_thread(int numthreads, World* w, vector<int> partitionVals){
  vector<thread> threads;  
  for (int i = 0; i < numthreads; i++){
    threads.push_back(thread(thread_func, partitionVals[2*i], partitionVals[(2*i)+1], w, i));
    //printf("%d did phase %d\n", i, phase);
  }
  for (int i = 0; i < numthreads; i++){
    threads[i].join();
  }
}

void main_thread_func(World*  w){
    //printf("\nat partition 1\n");
    vector<int> partitionVals = partition_vector(w->alive.size());
    phase++;
    create_thread(numthreads, w, partitionVals);

    //printf("\nat partition 2\n");
    //printf("RESETS SIZE: %llu\n", w->resets.size());
    partitionVals = partition_vector(w->resets.size());
    phase++;
    create_thread(numthreads, w, partitionVals);
    w->transfer();

    //printf("\nat partition 3\n");
    partitionVals = partition_vector(w->alive.size());
    phase++;
    create_thread(numthreads, w, partitionVals);

    phase=0;


}

