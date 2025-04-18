#include <iostream>
#include <vector>

template<typename T>
using Iterator = std::vector<T>::iterator;

template <typename T>
void swap(T& a, T& b);

template <typename Iterator>
void bubble_sort(Iterator begin, Iterator end);

template <typename Iterator>
void insertion_sort(Iterator begin, Iterator end);

