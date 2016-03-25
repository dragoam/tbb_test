#include "tbb/tbb.h"
#include <iostream>

using namespace tbb;
using namespace std;

class first_task : public task { 

    public: 

    task* execute( ) { 

	static int cnt = 0;
	task_list t_list; 	

	if (cnt < 10){
		cout << "Child " << ++cnt << " says: Hello World!\n";

		t_list.push_back( *new( allocate_child() ) first_task( ) );
		t_list.push_back( *new( allocate_child() ) first_task( ) );

		set_ref_count(3); // 2 (1 per child task) + 1 (for the wait)

		spawn_and_wait_for_all(t_list);
	} else {
		return NULL;
	}

	return NULL;
    }
};
// --------
// Main
// --------
int main( ){ 

    task_scheduler_init init(task_scheduler_init::automatic);
    first_task& f1 = *new(tbb::task::allocate_root()) first_task( );
    tbb::task::spawn_root_and_wait(f1);

}
