#pragma once
template <typename T>
void swap(T& a, T& b);

template <typename Iterator>
void bubble_sort(Iterator begin, Iterator end);

template <typename Iterator>
void insertion_sort(Iterator begin, Iterator end);

template <typename Iterator, typename KeyFunc>
void counting_sort(Iterator begin, Iterator end, KeyFunc keyFunc);   
