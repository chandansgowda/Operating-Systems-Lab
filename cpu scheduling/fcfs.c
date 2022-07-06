#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int pid, at, bt, ct, tt, wt;
} p;

float tot_tt = 0;
float tot_wt = 0;
void sort(struct process list[80], int s)
{
    int i, j;
    struct process temp;

    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1 - i); j++)
        {
            if (list[j].at > list[j + 1].at)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < s; i++)
    {
        list[i].ct = list[i].tt = list[i].wt = 0;
    }
}

void findtt(p a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i].tt = a[i].ct - a[i].at;
        tot_tt += a[i].tt;
    }
}

void findwt(p a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i].wt = a[i].tt - a[i].bt;
        tot_wt += a[i].wt;
    }
}

void findavg(p a[], int n)
{
    sort(a, n);
    int ct = a[0].at + a[0].bt;
    a[0].ct = ct;
    for (int i = 1; i < n; i++)
    {
        ct += a[i].bt;
        a[i].ct = ct;
    }
    findtt(a, n);
    findwt(a, n);

    printf("PID\tAT\tBT\tCT\tTT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", a[i].pid, a[i].at, a[i].bt, a[i].ct, a[i].tt, a[i].wt);
    printf("Avg wt = %.2f\nAvg tt = %.2f\n", tot_wt / n, tot_tt / n);
}

void main()
{
    int n;
    p a[10];
    printf("Enter the number of process: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        a[i].pid = i + 1;
        printf("\nEnter P%d arrival time: ", (i + 1));
        scanf("%d", &a[i].at);
        printf("Enter P%d burst time: ", (i + 1));
        scanf("%d", &a[i].bt);
    }
    findavg(a, n);
}
