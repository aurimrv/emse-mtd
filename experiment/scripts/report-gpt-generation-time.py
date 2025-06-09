#!/usr/bin/python3

###############################################
#
# report-gpt-generation-time.py <3.5|4.0>
# 
###############################################

import pandas as pd
import sys

BEGIN_TS="BEGIN_TS"
END_TS="END_TS"

def extractData(line):
    data = line.split(";")
    temperature = data[2].strip()
    dateTime = data[3].strip()
    return temperature, dateTime

def listAverageExecutionTime(temperatures,file_name):
    executionTime={}
    beginTime = ""
    endTime = ""
    beginStr = BEGIN_TS
    endStr = END_TS

    with open(file_name) as f:
        for line in f:
            if (beginStr in line):
                temperature,beginTime = extractData(line)
            elif (endStr in line):
                temperature,endTime = extractData(line)

                start = pd.to_datetime(beginTime, format='%Y-%m-%d %H:%M:%S.%f')
                end = pd.to_datetime(endTime, format='%Y-%m-%d %H:%M:%S.%f')
                diff = end - start
                diff = diff.total_seconds()

                #print(f"temperature: {temperature} - begin: {beginTime} - end: {endTime} - diff: {diff}")
                if temperature not in executionTime.keys():
                    executionTime[temperature] = diff
                else:
                    executionTime[temperature] = executionTime[temperature] + diff

    return executionTime

def main():
    # total arguments
    n = len(sys.argv)
    if (n < 2):
        print("Usage: report-gpt-generation-time.py <3.5|4.0> <file_project_names>")
        exit(1)
    else:
        model = sys.argv[1]
        file_name = sys.argv[2]
        
        print("PROG;0.0;0.1;0.2;0.3;0.4;0.5;0.6;0.7;0.8;0.9;1.0")

        with open(file_name) as f:

            for line in f:
                project = line.strip()
                print(f"{project}", end="")
                temperatures=["0.0","0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1.0"]
                executionTime = listAverageExecutionTime(temperatures,f"mode-test-empty-driver/{project}/gpt-{model}-time.txt")

                for key in list(executionTime.keys()):
                    value=executionTime[key]/3
                    print(";%.3f" % (value), end="")
                print()

if (__name__ == "__main__"):
    main()