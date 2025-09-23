#include <iostream>
//#include <vector>
#include <memory>
#include <map>
#include <list> 

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


int main() {
 //MyAllocator<std::pair <const int, int>> 
    //std::map<int, int, SimpleAllocator<std::pair <const int, const int>>> Mymap;  
 //   std::map<int, int, std::less<int>,SimpleAllocator<int>> Mymap; 
    std::map<int, int> defaultmap;  
    for (int i = 0; i < 10; ++i) {
        if (i==1)defaultmap.insert({1,1});
        else defaultmap.insert({i,(i-1)*i});
    }
    std::map<int, int, std::less<int>,SimpleAllocator<int>> Mymap;
        for (int i = 0; i < 10; ++i) {
        if (i==1)Mymap.insert({1,1});
        else Mymap.insert({i,(i-1)*i});
    }
    std::cout << "------Map default------" << std::endl;
    for (auto iter = defaultmap.begin(); iter != defaultmap.end(); ++iter) 
    { 
        std::cout << iter->first << " ";
        std::cout << iter->second << std::endl;
        // Доступ к ключу — iter->first, к значению — iter->second 
    }
    std::cout << "------Map allocator------" << std::endl;
    for (auto iter = Mymap.begin(); iter != Mymap.end(); ++iter) 
    { 
        std::cout << iter->first << " ";
        std::cout << iter->second << std::endl;
        // Доступ к ключу — iter->first, к значению — iter->second 
    }

    std::list<int> myList;
    std::list<int>::iterator it1 = myList.begin();
    for (int i = 0; i < 10; ++i) {
        myList.insert(it1, i);
        };



    std::list<int,SimpleAllocator<int>> myContainer;
    std::list<int>::iterator it2 = myContainer.begin();
    for (int i = 0; i < 10; ++i) {
        myContainer.insert(it2, i);
        };

    
std::cout << "------My conteiner------" << std::endl;
    for (auto iter = myList.begin(); iter != myList.end(); ++iter) { std::cout << *iter << "\n"; }
std::cout << "------My conteiner allocator------" << std::endl;    
    for (auto iter = myContainer.begin(); iter != myContainer.end(); ++iter) { std::cout << *iter << "\n"; }


   
    return 0;
}

