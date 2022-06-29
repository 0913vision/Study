from selenium import webdriver
import os
import time
import datetime as dt
from bs4 import BeautifulSoup
student_name = ["강지연","김민재","김재휘","김진아","김태윤","남기찬","박정주","박지윤","안연아","이수빈","이유빈","이정민","이지언","이지우","장나경"]
my_id = '20191575'
my_pwd = 'saint!@5133202'
raw_today = dt.datetime.now()
today = "".join([str(raw_today.month), '월 ', str(raw_today.day), '일'])
board_title = "".join([today, ' 출석'])

# options = webdriver.ChromeOptions()
# options.add_argument('window-size=300,300')
# browser = webdriver.Chrome('D:/programming/2020-2021/python/chromedriver.exe', options=options)
browser = webdriver.Chrome('D:/programming/2020-2021/python/chromedriver.exe')

browser.get('http://eclass.sogang.ac.kr')
time.sleep(2)

browser.find_element_by_class_name('header_login').click()

time.sleep(2)

browser.find_element_by_id('usr_id').send_keys(my_id)
browser.find_element_by_id('usr_pwd').send_keys(my_pwd)
submit_bt = browser.find_element_by_id('login_btn').click()

time.sleep(2)

browser.find_element_by_xpath('//*[@title="Advanced Applied C Programming Enter"]').click()

time.sleep(2)

browser.find_element_by_id('menu_open_material_28749').click()

time.sleep(2)

current = dt.datetime.now()
attendance_time = current.replace(hour=12, minute=5, second=0, microsecond=0)

if current < attendance_time :
    sleeptime = (12*60*60+5*60) - (current.hour*60*60 + current.minute*60 + current.second)
    time.sleep(sleeptime)

browser.find_element_by_partial_link_text(board_title).click()

time.sleep(2)

browser.find_element_by_class_name('commentBtn').click()

time.sleep(2)

comment_box = browser.find_elements_by_name('Explain')[0]
comment_box.send_keys('--')
dash_flag = True
comment_btn = browser.find_elements_by_class_name('comment-submit-btn')[0]
comment_btn.click()

time.sleep(2)

html = browser.page_source
soup = BeautifulSoup(html, 'html.parser')
tmplist = soup.find_all(attrs={'class':'comment-name'})
todayStudent = []

print("list print")
for t in tmplist:
    todayStudent.append(str(t).replace(" ", "").replace("\n","")[str(t).find('>'):str(t).find('>')+3])

attendance = []
absent = []
late = []

for name in student_name:
    if(name in todayStudent):
        attendance.append(name)
    else:
        absent.append(name)

print("▶ 결석")
print(" ".join(absent))
print("▶ 출석")
print(" ".join(attendance))

if not absent:
    browser.close()
else:
    current = dt.datetime.now()
    attendance_time = current.replace(hour=12, minute=15, second=0, microsecond=0)

    if current < attendance_time :
        dash_flag = False
        print('지각처리까지 대기중 ...')
        sleeptime = (12*60*60+15*60) - (current.hour*60*60 + current.minute*60 + current.second)
        time.sleep(sleeptime)

    comment_box = browser.find_elements_by_name('Explain')[1]
    comment_box.send_keys('--')
    comment_btn = browser.find_elements_by_class_name('comment-submit-btn')[1]
    comment_btn.click()
    
    time.sleep(2)
    browser.refresh()

    html = browser.page_source
    soup = BeautifulSoup(html, 'html.parser')
    tmplist = soup.find_all(attrs={'class':'comment-name'})
    todayStudent = []

    for t in tmplist:
        name = str(t).replace(" ", "").replace("\n","")[str(t).find('>'):str(t).find('>')+3]
        if name in absent:
            late.append(name)
    
    print("▶ 지각처리")
    print(" ".join(late))
    
    browser.close()
        
os.system("pause")
