#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

rt_table_t publisher_rt_table;

rt_table_t* publisher_get_rt_table() {
    return &publisher_rt_table;
}

int main(int argc, char**argv) {
    rt_init_rt_table(&publisher_rt_table);

    /* create subscriber threads */
    create_subscriber_thread(1);
    sleep(1);

    create_subscriber_thread(2);
    sleep(1);

    create_subscriber_thread(3);
    sleep(1);
    
    /* create_publisher_thread() */
    create_publisher_thread();
    printf("Publisher thread created\n");

    pthread_exit(0);
    return 0;
}