#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>

std::vector<int> vec(){
  std::vector<int> vec{};
  for (int i = 0; i < 100000; i++){
    vec.push_back(std::rand() % 100000);
  }
  return vec;
}

std::vector<int> bubblesort(std::vector<int> v){
  bool a = true;
  while (a){
    a = false;
    for (int i = 0; i < v.size() - 1; i++){
      if (v[i] > v[i + 1]){
        a = true;
        std::swap(v[i], v[i + 1]);
      }
    }
  }
  return v;
  }

std::vector<int> bubblesort2(std::vector<int> v){
  for (int i = 0; i < v.size() - 1; i++){
    for (int j = 0; j < v.size() - 1 - i; j++){
      if (v[j] > v[j + 1]){
        std::swap(v[j], v[j + 1]);
      }
    }
  }
  return v;
  }

void quicksort(std::vector<int>& v, int start, int end){
  int pivot = end;
  int st = start;

  if (end - start == 0) return;
  if (end - start == 1 && v[start] > v[end]){
    std::swap(v[start], v[end]);
    return;
  }
  if (end - start == 1) return;

  while (st < pivot){
    if (v[st] <= v[pivot]) st++;
    else{
      std::swap(v[pivot], v[pivot - 1]);
      if (pivot - 1 != st){
        std::swap(v[pivot], v[st]);
      }
      pivot--;
    }
  }
  quicksort(v, start, pivot-1);
  quicksort(v, pivot, end);
}

int main() {
  srand( time( NULL ) );
  time_t start, end;
  double time_taken;
  
  std::vector<int> v = vec();
  
  start = clock();
  std::vector<int> sortb = bubblesort2(v);
  end = clock();
  std::cout<<"Bubblesort:"<<std::endl;
  std::cout<<double(end - start) / double(CLOCKS_PER_SEC)<<" s"<<std::endl;

  start = clock();
  quicksort(v, 0, v.size() - 1);
  end = clock();
  std::cout<<"Quicksort:"<<std::endl;
  std::cout<<double(end - start) /     double(CLOCKS_PER_SEC)<<" s"<<std::endl;

}
