import time
import datetime as dt

current = dt.datetime.now()
attendance_time = current.replace(hour=11, minute=3, second=30, microsecond=0)

if current < attendance_time :
    print('sleeping...')
    sleeptime = (11*60*60+3*60+30) - (current.hour*60*60 + current.minute*60 + current.second)
    time.sleep(sleeptime)

print('hi')
