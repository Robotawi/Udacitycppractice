//
// Created by zozo on 1/17/20.
//
#include <iostream>
class Mynono{
private:
    int number;
};

class Myclass{
private:
    int* ptr;
    Mynono* ptrnono;
public:
    Myclass(){
        //By separating allocation from construction, we can get a significant performance increase.
        void *memory = malloc(sizeof(Mynono));//make pointer to void object, but with size of mynono (process: allocation)
        //Now let the pointer take the
        Mynono *object = new (memory) Mynono; //make a pointer to nono object and use the new (void pointer) Mynono
        /*
         he syntax new (memory) is denoted as placement new.
         The difference to the "conventional" new we have been using so far is that that no memory is allocated.
         The call constructs an object and places it in the assigned memory location.
         There is however, no delete equivalent to placement new, so we have to call the destructor explicitly
         in this case instead of using delete as we would have done with a regular call to new
         */
    }

    Myclass(int size){
        ptr = (int *) malloc (size * sizeof(int));
        std::cout <<"Allocated memory of size "<<size << ", starting at address "<< ptr <<std::endl;
    }

    Myclass(Mynono nono){
        ptrnono = (Mynono *) malloc (sizeof(Mynono));
        std::cout <<"Allocated memory of size "<<sizeof(Mynono) << ", starting at address "<< ptr <<std::endl;
    }




    ~Myclass(){
        free(ptrnono);
        std::cout <<"De-allocated memory" <<std::endl;
    };
};


int main(){
    Mynono noone;
    Myclass mimi(noone);
}