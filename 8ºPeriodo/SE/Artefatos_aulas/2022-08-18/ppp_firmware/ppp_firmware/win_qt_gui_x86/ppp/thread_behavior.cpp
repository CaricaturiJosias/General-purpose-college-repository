#include "thread_behavior.h"
extern "C"{
    #include "../../common/behavior.h"
}
thread_behavior::thread_behavior()
{

}

void thread_behavior::run(){
    behavior();
}
