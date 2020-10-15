#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <memory>
#include <limits>
#include <list>
#include <regex>
#include <functional>
#include <math.h>
#include <unordered_set>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
using namespace std;

void daemon()
{
    if (fork() > 0)
        exit(0);
    setsid();
    chdir("/");
    umask(0);
    for (int i = 0; i < 64; i++)
        close(i);
    int cnt = 0;
    while (cnt < 10)
    {
        syslog(LOG_INFO, "this is %d message", cnt);
        cnt++;
        sleep(1);
    }
}

void test_fork()
{
    int sum = 10;
    printf("before fork(): %p\n", &sum);
    if (fork() > 0)
    {
        printf("father process: %p\n", &sum);
        sum++;
        cout << "father process:" << sum << endl;
    }
    else
    {
        printf("child process: %p\n", &sum);
        sum++;
        cout << "child process:" << sum << endl;
    }
}

int main()
{
    test_fork();
    return 0;
}
