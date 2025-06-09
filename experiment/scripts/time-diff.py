import pandas as pd

def timeDifference(interval, formatStr):
    dates = interval.split(";")
    beginTime=dates[0].strip()
    endTime=dates[1].strip()
    start = pd.to_datetime(beginTime, format=formatStr)
    end = pd.to_datetime(endTime, format=formatStr)
    diff = end - start
    return diff.total_seconds()
    
if (__name__ == "__main__"):
    import argparse
    parser = argparse.ArgumentParser(description='Calculate time difference in seconds')
    parser.add_argument('--interval', metavar='datetime;datetime', required=True,
                        help='begin time;end time')
    parser.add_argument('--format', metavar='string', required=True,
                        help='datatime format')
    
    args = parser.parse_args()

    print(timeDifference(args.interval, args.format), end="")