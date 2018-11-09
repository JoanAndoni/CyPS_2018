from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as ec
from selenium.webdriver import ActionChains

browser = webdriver.Chrome()

browser.get('https://www.w3schools.com/default.asp')
"""
image2drag = browser.find_element_by_xpath('//*[@id="div1"]')
element2put = browser.find_element_by_css_selector('#div2')

actions = ActionChains(browser)
actions.drag_and_drop(image2drag, element2put)
actions.click(element2put)
actions.release()
actions.perform()
actions.pause(2)
"""

menu =  browser.find_element_by_xpath('//*[@id="navbtn_references"]')
subMenu = browser.find_element_by_xpath('//*[@id="nav_references"]/div/div[1]/a[1]')
actions = ActionChains(browser)
actions.click(menu)
actions.click(subMenu)
actions.pause(4)
actions.perform()

browser.back()
browser.find_element_by_xpath('//*[@id="navbtn_references"]').click()
subMenu = browser.find_element_by_xpath('//*[@id="nav_references"]/div/div[1]/a[1]')
try:
    WebDriverWait(browser, 10).until(ec.presence_of_element_located((By.XPATH,'//*[@id="nav_references"]/div/div[1]/a[1]' ))).click()
finally:
    browser.quit()
