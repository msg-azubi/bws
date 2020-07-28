#include "demo-schleifen.h"


int main()
{
    copy_array();
}


void copy_array(){
    std::cout << "copy_array";
    const size_t size {10};
    int v1[size] = {0, 1, 2 ,3 , 4, 5, 6 , 7 ,8, 9 };
    int v2[size];

    for (auto i=0; i!= size; ++i){
        v2[i] = v1[i];
        // ... v2 ist
    }
    std::cout << "... copy_array done: ";
    for(auto const& value: v2)
      {
          std::cout << value << ",";
      }
      std::cout << "\n";
}
