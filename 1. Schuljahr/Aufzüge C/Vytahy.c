
// Modelovanie a simulacia:
// jednoducha implementacia kalendara udalosti a model zalozeny na grafe udalosti
// zdrojovy text na volne pouzitie

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)

int maxtime = 1000;    // maximal simulation timesteps
int simtime = 0;     // current timestep
int maximum = 120;   // event calendar capacity
int calendar[100];   // array: <time,event>,<time,event>,...

// user global variables in the model
int persons = 0;      // number of persons in the hall
// end of user global variables

void set_random_generator(void)
{
    time_t t;
    srand((unsigned)time(&t));
}

int get_random_number(int min, int max)
// integer random variable from <min,max>
{
    return(min + (int)((double)(rand()) / RAND_MAX * (1 + max - min)));
}

void calendar_initialise(void)
{
    int i;
    for (i = 0; i < maximum; i++) calendar[i] = 0;
    return;
}

void calendar_print(void)
{
    int i, k;
    printf("\n==");
    for (i = 0, k = 1; i < maximum; i = i + 2, k = k + 2)
        printf("<%d,%d>", calendar[i], calendar[k]);
    printf("==\n");
}

void event_schedule(int delay, int event)
// add <simtime+delay,event> to calendar
{
    int i, k, repeat, value;
    for (i = 0;; i = i + 2)
    {
        if (i >= maximum) exit(0);          // calendar overflow
        if (calendar[i] == 0)               // find free place at the end
        {
            calendar[i] = simtime + delay; // append new <time,event>
            calendar[i + 1] = event;
            break;
        }
    }
    for (repeat = 0; repeat < maximum; repeat++)
        // bubble sort of couples <time,event> by time
        for (i = 0, k = 1; i < maximum - 2; i = i + 2, k = k + 2)
            // the one passage through the calendar array
            if (calendar[i] > calendar[i + 2])
                // change item <i,k> and <i+2,k+2>
            {
                if (calendar[i] == 0)   continue; // empty item
                if (calendar[i + 2] == 0) continue;
                value = calendar[i];
                calendar[i] = calendar[i + 2]; calendar[i + 2] = value;
                value = calendar[k];
                calendar[k] = calendar[k + 2]; calendar[k + 2] = value;
            }
    return;
}

int event_cause(void)
// get first <time,event> from calendar
{
    int i, k, event;
    simtime = calendar[0]; // set current simulation time
    event = calendar[1]; // get current event
    for (i = 0, k = 1; i < maximum - 2; i = i + 2, k = k + 2)
    {
        calendar[i] = calendar[i + 2]; // shift all couples to the left
        calendar[k] = calendar[k + 2];
    }
    return event;
}

// user event description
void event1(void)
// people are coming to the hall
{
    int i;
    i = get_random_number(1, 3);
    printf("persons came: %d", i);
    persons = persons + i;
    event_schedule(get_random_number(1, 2), 1);
    // somebody else is going to come after 1 or 2 timesteps
    return;
}

// user event description
void event2(void)
// lift departures from the hall
{
    persons = persons - 3;       // maximal 3 people enter the lift
    if (persons < 0) persons = 0;
    printf("lift is left, waiting persons: %d", persons);
    event_schedule(get_random_number(2, 5), 2);
    // lift returns after 2 ... 5 timesteps
    return;
}

int main(void)
{
    int event;

    printf("simulation start\n");
    set_random_generator();
    calendar_initialise();
    // first events scheduled
    event_schedule(1, 1);
    event_schedule(1, 2);
    while (simtime < maxtime)
        // simulation loop
    {
        event = event_cause();
        printf("\ntime: %2d  event: %d  ", simtime, event);
        if (event == 0) break;      // empty calendar
        if (event == 1) event1();
        if (event == 2) event2();
        // calendar_print();
    }
    printf("\n\nsimulation finished\n\n");
    printf("\npress any key\n\n");
    (void)getchar();
    return 0;
}
