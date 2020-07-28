#include "demo-schleifen.h"


int main()
{
    copy_array();
    traditional_size();
}


void copy_array(){

    const size_t size {10};
    int v1[size] = {0, 1, 2 ,3 , 4, 5, 6 , 7 ,8 , 9 };
    int v2[size];

    std::cout << "copy_array";
    // the handy `std::size()` helper function was added to {cpp}17
    for (auto i=0; i!= std::size(v1); ++i){
        v2[i] = v1[i];
        // ... v2 ist
    }
    std::cout << "... copy_array done: ";

    // print_array(v2)
    for(auto const& value: v2) {
        std::cout << value << ",";
    }
    std::cout << "\n";

}

void traditional_size(){

    const size_t size {10};
    int v2[size] = {0, 1, 2 ,3 , 4, 5, 6 , 7 ,8 , 9 };

    std::cout << "Vektor contains "
              << sizeof(v2) / sizeof( v2[0])
              << " elements";

    std::cout << "... traditional_size done: ";

    // print_array(v2)
    for(auto const& value: v2) {
        std::cout << value << ",";
    }
    std::cout << "\n";

}

/*
 * skipped, because
 *
 * cannot build range expression with array function parameter,
 * since parameter with array type `int[10] is treated as pointer type `int *`

void print_array_specific_size( int a_array[10]){
    for(auto const& value: a_array) {
        std::cout << value << ",";
    }
    std::cout << "\n";

}
*/
