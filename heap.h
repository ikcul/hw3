#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  void trickleUp(size_t loc);
  void trickleDown(size_t loc);
  size_t m_;
  PComparator c_;

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c){
  m_ = m;
  c_ = c;
}
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){
  
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(size_t loc){
  size_t curr = loc;
  while (curr != 0){
    size_t parent = (curr-1)/m_;
    if (c_(data[curr], data[parent])){
      std::swap(data[parent], data[curr]);
      curr = parent;
    }else{
      return;
    }
  }

}
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(size_t loc){
  size_t curr = loc;
  while ((m_*curr) + 1 < data.size()){
    size_t child = (m_*curr) + 1;
    //finding the best child to swap with
    for (size_t i = 2; i <= m_; i++){
      size_t tempChild = (m_*curr) + i;
      if (tempChild >= data.size()){
        break;
      }else{
        if (c_(data[tempChild], data[child])){
          child = tempChild;
        }
      }
    }

    if (c_(data[child], data[curr])){
      std::swap(data[child], data[curr]);
      curr = child;
    }else{
      return;
    }
  }

}
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  data.push_back(item);
  trickleUp(data.size() - 1);
}
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return data.empty();
}
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return data.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("heap is empty");

  }
  std::swap(data[0], data[data.size() - 1]);
  data.pop_back();
  if (!empty()){
    trickleDown(0);
  }


}




#endif

