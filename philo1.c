#include "philo.h"

long int  time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) / 1e-6 +  (end->tv_usec - start->tv_usec);
}

void    *routine(void *arg);
{
    struct timeval start;
    struct timeval end;
    t_philo *pl;
    int     index;
    int     time_diff;

    pl = (t_philo*)arg;
    index = pl->index;
    time_diff = 0;
    while (1)
    {
        gettimeofday(&start, NULL);
        pthread_mutex_lock(&pl->forks[index]);
        gettimeofday(&ned,NULL);
        if(time_diff = time_diff(&start,&end) > pl->timetodie * 1000)
        {
            print("philosopher %d die",index + 1);
            pl->reminder = 1;
            break;
        }
        printf("philosopher %d took the left fork",index + 1);

    }pth

}
void    gettinginfos(char **argv, t_philo gl)
{
    gl->numofphilo = atoi(argv[1]);
    gl->timetodie = atoi(argv[2]);
    gl->timetoeat = atoi(argv[3]);
    gl->timetosleep = atoi(argv[4]);
    gl->reminder = 0;
}

int main(int argc, char **argv)
{
    t_philo gl;
    int     j;

    gettinginfos(argv, gl);
    gl.forks = malloc(sizeof(pthread_mutex_t) * gl.numofphilo);
    j = 0;
    while(j < gl.numofphilo)
    {
        gl.index = j;
        pthread_create(&thread[j], NULL, &routine, &gl);
        usleep(100);
        if (pl->reminder == 1)
        {
            return (0);
        }
        j++;
    }
    return (0);
}