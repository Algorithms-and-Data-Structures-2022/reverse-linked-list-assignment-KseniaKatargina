#include "assignment/linked_list.hpp"

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (size_ <= 1){
      return;
    }
    Node* prev = nullptr;
    Node* curr = front_;
    while (curr != nullptr){
      Node* temp = (*curr).next;
      (*curr).next = prev;
      prev = curr;
      curr = temp;
    }
    Node* n = back_;
    back_ = front_;
    front_ = n;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    reverse_recursive_helper(front_,nullptr);
    Node* n = back_;
    back_ = front_;
    front_ = n;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if(curr == nullptr){
      return;
    }
    Node* c = (*curr).next;
    reverse_recursive_helper(c, curr);
    (*curr).next = prev;
  }

}  // namespace assignment
