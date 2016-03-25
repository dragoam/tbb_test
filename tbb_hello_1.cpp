//
// tbb example with one child task
//
#include "tbb/tbb.h"
#include <iostream>

using namespace tbb;
using namespace std;

class first_task : public task { 

    public: 

    task* execute( ) { 
       cout << "Hello World!\n";
       return NULL;
    }
};
// --------
// Main
// --------
int main( ){ 

    task_scheduler_init init(task_scheduler_init::automatic);
    first_task& task_1 = *new(tbb::task::allocate_root()) first_task( );
    tbb::task::spawn_root_and_wait(task_1);

}
