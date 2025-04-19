#pragma once

// ----------------------
// UTILS
// ----------------------

template <typename T>
void swap(T& a, T& b);

template <typename Iterator>
Iterator max_element(Iterator begin, Iterator end);

template <typename Iterator>
Iterator min_element(Iterator begin, Iterator end);

// ----------------------
// SORTING ALGORITHMS
// ----------------------

template <typename Iterator>
void bubble_sort(Iterator begin, Iterator end);

template <typename Iterator>
void insertion_sort(Iterator begin, Iterator end);

template <typename Iterator, typename KeyFunc>
void counting_sort(Iterator begin, Iterator end, KeyFunc keyFunc);   
