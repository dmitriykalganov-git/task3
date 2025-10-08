#ifndef __IPSIMALLOC
#define __IPSIMALLOC
#include <iostream>
//#include <memory>


// Simple custom allocator that tracks memory allocations
template<typename T>
class SimpleAllocator {
public:
    // Required type definitions for allocator
    using value_type = T;
    // Static counter to track allocations (shared by all instances)
    static int allocations;
    static int deallocations;
    
    // Default constructor
    SimpleAllocator() = default;
    
    // Copy constructor for different types (required by standard)
    template<typename U>
    SimpleAllocator(const SimpleAllocator<U>&) {}
    
    // The main function: allocate memory for 'n' objects of type T
    T* allocate(size_t n) {
        allocations++;
        std::cout << "Allocating " << n << " objects of size " << sizeof(T) 
                  << " bytes each\n";
        
        // Use standard malloc to get memory
        T* ptr = static_cast<T*>(std::malloc(n * sizeof(T)));
        
        if (!ptr) {
            throw std::bad_alloc(); // If allocation fails
        }
        
        return ptr;
    }
    
    // The cleanup function: free the memory
    void deallocate(T* ptr, size_t n) {
        deallocations++;
        std::cout << "Deallocating " << n << " objects\n";
        
        // Use standard free to release memory
        std::free(ptr);
    }
    
    // Print statistics
    static void printStats() {
        std::cout << "Total allocations: " << allocations << "\n";
        std::cout << "Total deallocations: " << deallocations << "\n";
    }
};

// Initialize static members (required for static variables)
template<typename T>
int SimpleAllocator<T>::allocations = 0;

template<typename T>
int SimpleAllocator<T>::deallocations = 0;

// Comparison operators (required by standard)
template<typename T, typename U>
bool operator==(const SimpleAllocator<T>&, const SimpleAllocator<U>&) {
    return true; // All instances are equal
}

template<typename T, typename U>
bool operator!=(const SimpleAllocator<T>&, const SimpleAllocator<U>&) {
    return false; // All instances are equal
}

#endif
