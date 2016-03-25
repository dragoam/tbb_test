#include "tbb/tbb.h"
#include <cstdio>

using namespace tbb;

class say_hello {

	const char* id;

	public:

	say_hello(const char* s) : id(s) { }
	void operator( ) ( ) const {
		printf("hello from %s\n",id);
	}
};
// --------
// Main
// --------
int main( ){

	task_group tg;

	tg.run(say_hello("child 1")); // spawn 1st task and return
	tg.run(say_hello("child 2")); // spawn 2nd task and return

	tg.wait( );             // wait for tasks to complete

}
