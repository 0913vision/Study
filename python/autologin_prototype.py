from selenium import webdriver
import time
import datetime as dt
import os

my_id = '20191575'
my_pwd = 'saint!@5133202'
raw_today = dt.datetime.now()
today = "".join([str(raw_today.month), '월 ', str(raw_today.day), '일'])
board_title = "".join([today, ' 출석'])
board_context = '댓글로 달아주세요.'
# options = webdriver.ChromeOptions()
# options.add_argument('window-size=300,300')

current = dt.datetime.now()
attendance_time = current.replace(hour=11, minute=54, second=30, microsecond=0)

if current < attendance_time :
    print('sleeping...')
    sleeptime = (11*60*60+54*60+30) - (current.hour*60*60 + current.minute*60 + current.second)
    time.sleep(sleeptime)
    

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

browser.find_element_by_class_name('site_button').click()

time.sleep(2)

browser.find_element_by_id('wrtTitle').send_keys(board_title)

board_editor = browser.find_element_by_tag_name('iframe')

browser.switch_to.frame(board_editor)

browser.find_element_by_css_selector('body').send_keys(board_context)

browser.switch_to.default_content()

time.sleep(2)

# cancle_btn = browser.find_element_by_class_name('site_button')
save_btn = browser.find_element_by_class_name('site_button_reverse')
save_btn.click()

browser.find_element_by_id('menu_notice').click()

time.sleep(2)


zoomTitle = "".join([today, ' 줌강의 링크'])
browser.find_element_by_partial_link_text(zoomTitle).click()

time.sleep(2)

browser.find_element_by_partial_link_text('https://sogang-ac-kr.zoom.us/j/').click()

browser.close()

os.system("pause")
