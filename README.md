# CPP_Containers
Implementation of the containers.h library in C++

## Description

In this project I've developed my own "containers" library that implements the basic C++ container classes: `list`, `map`, `queue`, `set`, `multiset`, `stack`, `vector` and `array`. Implementations provide a full set of standard methods and attributes for element handling, container capacity checking and iteration.

## Important notes

- The program has been developed in C++ language of C++17 standard using gcc compiler;
- Library code follows the Google style;
- Full coverage of library functions code has been prepared with unit-tests using the GTest library;
- Container classes are templates like standard C++ containers;
- The logic of the Standard Template Library (STL) is followed (in terms of checks, memory handling and behaviour in abnormal situations), but implementation has not been copied;
- The gcov_report target generates a gcov report in the form of an html page.

## Information

**Containers** are used to contain sets of objects of the same type. There are a huge number of container classes. This is because container classes differ in the organisation of the stored object sets and in the methods provided to interact with them. For example, lists (list) store any object, while sets (set) store only some unique objects.

The need to separate containers, rather than using the same container for different tasks, is not only due to obvious functional differences. In some cases it is more efficient to use lists, e.g. if the task at hand requires frequent insertion of elements in the middle of the container, but if new elements are only added at the end, it is better to use a queue.

Each type of containers provides the user with the following methods:

- standard constructors (default constructor, copy constructor, move constructor, constructor with initialization list);

- methods for accessing container elements (e.g. accessing an element with the index i);

- methods for checking if a container is full (e.g. the number of elements in the container, check if the container is empty);

- methods for changing the container (removing and adding new elements, cleaning the container);

- methods for dealing with the container iterator.

**Iterators** provide access to container elements. The specific type of iterator will be different for each container. This is due to the different way of organising object sets in container classes, as well as the actual implementation of the container. Iterators are implemented to work in a similar way to a pointer to an array element in C. So this approach to iterators allows you to interact with any container in the same way. Containers provide iterators via the `begin()` and `end()` methods, which point to the first and next after last elements of the container respectively.

Iterator `iter` has the following operations:

- `*iter`: gets the element pointed to by the iterator;

- `++iter`: moves the iterator forward to the next element;

- `--iter`: moves the iterator backwards to the previous element;

- `iter1 == iter2`: two iterators are equal if they point to the same element;

- `iter1 != iter2`: two iterators are not equal if they point to different elements.

