import time
import linecache
import os

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

#display cumulative timing data every second for [secs] seconds 
def monitor_c(secs):        
        for i in range(secs):
                os.system('clear')
                print(time.time())
                print(usage_c(0))
                print(avg_usage_pct(0))
                printtime_c()
                time.sleep(1 - (time.time() % 1))

#returns the cumulative usage seconds of a core
def usage_c(core):
        total = 0
        data = read_core_time(core)
        for i, val in enumerate(data):
                if (not i == 0) and (not i == 4):
                        total += int(val)
        return total                

#returns the percent average CPU usage for a core
def avg_usage_pct(core):
        data = read_core_time(core)
        use = usage_c(core)
        total = int(data[4]) + use
        return use / float(total)


        

