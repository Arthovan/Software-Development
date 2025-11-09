#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_TASKS 5
#define TIME_SLICE_MS 500

typedef void (*task_func_t)(void);

typedef struct {
    char name[16];
    task_func_t func;
    int active;
    int remaining_time_ms;
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

/* ------------ Add a new task ------------ */
void add_task(const char *name, task_func_t func, int run_time_ms) {
    if (num_tasks >= MAX_TASKS) {
        printf("Task limit reached!\n");
        return;
    }
    strcpy(tasks[num_tasks].name, name);
    tasks[num_tasks].func = func;
    tasks[num_tasks].remaining_time_ms = run_time_ms;
    tasks[num_tasks].active = 1;
    num_tasks++;
}

/* ------------ Task examples ------------ */
void task_A(void) {
    printf("   Running Task A\n");
}

void task_B(void) {
    printf("   Running Task B\n");
}

void task_C(void) {
    printf("   Running Task C\n");
}

/* ------------ Round Robin Scheduler ------------ */
void round_robin_run(void) {
    int all_done = 0;

    while (!all_done) {
        all_done = 1;
        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].active && tasks[i].remaining_time_ms > 0) {
                all_done = 0;
                printf(">> Switching to %s\n", tasks[i].name);
                tasks[i].func();
                usleep(TIME_SLICE_MS * 1000);
                tasks[i].remaining_time_ms -= TIME_SLICE_MS;

                if (tasks[i].remaining_time_ms <= 0) {
                    tasks[i].active = 0;
                    printf("   %s finished.\n", tasks[i].name);
                }
            }
        }
    }

    printf("\nAll tasks finished.\n");
}

/* ------------ Main ------------ */
int main(void) {
    add_task("TaskA", task_A, 1500);
    add_task("TaskB", task_B, 1000);
    add_task("TaskC", task_C, 2000);

    printf("Starting Round Robin Scheduler...\n");
    round_robin_run();
    return 0;
}
