import time
import linecache
import os

#system information file paths
cpuinfo = "/proc/cpuinfo"
meminfo = "/proc/meminfo"
stat    = "/proc/stat"

#returns the number of CPU cores in a linux system
def cpucores():
        ss = "cpu cores" #search string
        with open("/proc/cpuinfo", "r") as cpuinfo:
                for line in cpuinfo:
                        if (line[:len(ss)] == ss):
                                return(int(line.split()[3]))
        return 0                             

#returns a list containing cumulative CPU times read from /proc/stat 
def read_core_time(core):
        usage = []
        numcores = cpucores()
        if (core < 0 or core >= numcores):
                print("invalid core id, exiting")
                return usage
        else:
                usage = linecache.getline("/proc/stat", core + 2).split()
                linecache.clearcache()
                #for i in usage
                return usage

#prints readable value for cumulative cpu core timings to console
def printtime_c():
        head = ["core", "user", "nice", "system", "idle", "iowait", "irq", "softirq", "steal", "guest"]
        for x in head:
                print("{:^8}".format(x), end = ''),
        print('\n') 
        for i in range(cpucores()):
                data = read_core_time(i)
                for x in data:
                        print("{:^8}".format(x), end = ''),
                print('\n') 

#returns a 2 element list containing the cumulative usage and idle time of a core
def usage_idle_c(core):
        total = 0
        use_idle = []
        data = read_core_time(core)
        for i, val in enumerate(data):
                if (not i == 0) and (not i == 4):
                        total += int(val)
        use_idle.append(total)
        use_idle.append(int(data[4]))
        return use_idle

#returns the percent average CPU usage for a core
def avg_usage_pct(core):
        data = usage_idle_c(core)
        use = data[0]
        idle = data[1]
        total = use + idle 
        return use / float(total)



#display cumulative timing data every second for [secs] seconds 
def monitor_c(secs):
        prev = usage_idle_c(0)
        for i in range(secs):
                os.system('clear')
                curr = usage_idle_c(0)
                print(curr)
                print([int(curr[0] - prev[0]), int(curr[1] - prev[1])])
                print(time.time())
                print(avg_usage_pct(0))
                printtime_c()
                time.sleep(1 - (time.time() % 1))


