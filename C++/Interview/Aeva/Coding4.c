// Design and develop pseudo code for software timer
// Define APIs to be exposed to the application layer
// write skeleton code for each api. Write a code so that it has 1 timer where 5 thread can use that same timer 

/////////// Timer Data Structure ////////////
#define MAX_TIMERS 5

typedef void (*timer_cb_t)(void *);

typedef struct {
    int active;
    unsigned int remaining_ms;
    unsigned int period_ms;
    timer_cb_t callback;
    void *arg;
} soft_timer_t;
////////////////////////////////////////////////

//////////////// Internal Timer Table ////////////////////////
static soft_timer_t timers[MAX_TIMERS];
////////////////////////////////////////

/// Public APIs (Application Layer) ///////
void timer_init(void);

int timer_start(int id, unsigned int timeout_ms,
                unsigned int period_ms,
                timer_cb_t cb,
                void *arg);

void timer_stop(int id);

void timer_tick_handler(void);   // called every system tick
//////////////////////////////////////////////

////////// Skeleton Implementation (C) ///////////
/* Initialize timer system */
void timer_init(void)
{
    for (int i = 0; i < MAX_TIMERS; i++)
        timers[i].active = 0;
}
/* Start a timer (used by any thread) */
int timer_start(int id,
                unsigned int timeout_ms,
                unsigned int period_ms,
                timer_cb_t cb,
                void *arg)
{
    if (id < 0 || id >= MAX_TIMERS)
        return -1;

    timers[id].active = 1;
    timers[id].remaining_ms = timeout_ms;
    timers[id].period_ms = period_ms;
    timers[id].callback = cb;
    timers[id].arg = arg;

    return 0;
}

/* Stop a timer */
void timer_stop(int id)
{
    if (id < 0 || id >= MAX_TIMERS)
        return;

    timers[id].active = 0;
}

/* System Tick Handler (called every 1 ms for example) */
void timer_tick_handler(void)
{
    for (int i = 0; i < MAX_TIMERS; i++)
    {
        if (!timers[i].active)
            continue;

        if (timers[i].remaining_ms > 0)
            timers[i].remaining_ms--;

        if (timers[i].remaining_ms == 0)
        {
            if (timers[i].callback)
                timers[i].callback(timers[i].arg);

            if (timers[i].period_ms > 0)
            {
                timers[i].remaining_ms = timers[i].period_ms;  // periodic
            }
            else
            {
                timers[i].active = 0;  // one-shot
            }
        }
    }
}
//////////////////////////////////////////////////

/////////// Example Usage by 5 Threads ////////////
void thread1_cb(void *arg) { printf("T1 expired\n"); }
void thread2_cb(void *arg) { printf("T2 expired\n"); }

int main()
{
    timer_init();

    timer_start(0, 1000, 0, thread1_cb, NULL);   // one-shot 1 sec
    timer_start(1, 500, 500, thread2_cb, NULL); // periodic 500ms

    while (1)
    {
        sleep_ms(1);
        timer_tick_handler();
    }
}
////////////////////////////////// 