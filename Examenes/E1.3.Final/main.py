# Joan Andoni Gonzalez Rioz
# A00569929

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from time import sleep
import csv

driver = webdriver.Chrome()
driver.get("http://fiware01.cem.itesm.mx:3000/~certificatec/pronosticos")

driver.find_element_by_id("login_username").send_keys("ariel.garcia@itesm.mx")
driver.find_element_by_id("login_password").send_keys("1234")
driver.find_element_by_id("login_submit").click()
sleep(1)
driver.find_element_by_xpath('//*[@id="nav"]/div/ul/li[7]/a').click()
sleep(1)
driver.find_element_by_xpath('//*[@id="sidebar"]/ul[1]/li[5]/a').click()
sleep(1)

table = len(driver.find_elements_by_tag_name("tr"))+1

alumnos = [['Matricula', 'Nombre', 'Materia', 'Codigo']]

for row in xrange(1,table):
    matricula = driver.find_element_by_xpath('//*[@id="candidatos_container"]/tbody/tr['+str(row)+']/td[1]/a').text
    nombre = driver.find_element_by_xpath('//*[@id="candidatos_container"]/tbody/tr['+str(row)+']/td[2]/a').text
    #print(matricula)
    #print(nombre)
    driver.find_element_by_xpath('//*[@id="candidatos_container"]/tbody/tr['+str(row)+']/td[1]/a').click()
    sleep(1)
    driver.find_element_by_xpath('//*[@id="sidebar"]/ul[1]/li[3]/a').click()
    sleep(1)
    tableMaterias = len(driver.find_elements_by_tag_name("tr"))+1
    for row2 in xrange(1,tableMaterias):
        codigo = driver.find_element_by_xpath('//*[@id="pronosticos_container"]/tbody/tr['+str(row2)+']/td[1]').text
        nombreMateria = driver.find_element_by_xpath('//*[@id="pronosticos_container"]/tbody/tr['+str(row2)+']/td[2]').text
        #print(codigo)
        #print(nombreMateria)
        sleep(1)
        alumnos.append([matricula.encode('utf-8'), nombre.encode('utf-8'), nombreMateria.encode('utf-8'), codigo.encode('utf-8')])
    driver.back()
    driver.back()
    sleep(1)
#print(alumnos)

with open('pronosticos.csv', 'a') as csvFile:
    writer = csv.writer(csvFile)
    for col in alumnos:
        writer.writerow(col)
    csvFile.close()
