#include "types.h"
#include "stat.h"
#include "user.h"

void print_test(void* arg1, void* arg2){
    printf(1, "hello arg1 %d \n", *(int*)arg1);
    printf(1, "goodbye arg2 %d \n", *(int*)arg2);
    exit();
}

void sleep_test(void *arg1, void* arg2){
    printf(1, "welcome arg1 %d \n", *(int*)arg1);
    printf(1, "arg2 is fall a sleep .. %d \n", *(int*)arg2);
    sleep(50);
    exit();
}
void swap_test(void *arg1, void* arg2){
    printf(1, "first: %d || second: %d \n", *(int*)arg1, *(int*)arg2);
    int temp;
    temp = *(int*)arg2;
    *(int*)arg2 = *(int*)arg1;
    *(int*)arg1 = temp;
    exit();
}

int main(int argc, char** argv){
    int arg1 = 10;
    int arg2 = 20;
    thread_create(
        &print_test, 
        (void*)&arg1, 
        (void*)&arg2
    );
    thread_join();

    arg1 = 30;
    arg2= 250;
    thread_create(
        &sleep_test,
        (void*)&arg1,
        (void*)&arg2
    );
    thread_join();

    arg1 = 100;
    arg2 = 500;
    thread_create(
        &swap_test,
        (void*)&arg1,
        (void*)&arg2
    );
    thread_join();
    
    //swap done 
    printf(1, "after -> arg1: %d || arg2: %d \n", arg1, arg2);

    exit();
}	