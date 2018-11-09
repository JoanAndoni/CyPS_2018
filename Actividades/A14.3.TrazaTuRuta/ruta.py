from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver import ActionChains
import time
browser = webdriver.Chrome()

browser.get('http://app.sct.gob.mx/sibuac_internet/ControllerUI?action=cmdEscogeRuta')
#De estado
browser.find_element_by_xpath('//*[@id="headerEPN"]/table[3]/tbody/tr/td/table/tbody/tr[3]/td/table/tbody/tr[2]/td[2]/select/option[10]').click()
#De cuidad
browser.find_element_by_xpath('//*[@id="headerEPN"]/table[3]/tbody/tr/td/table/tbody/tr[3]/td/table/tbody/tr[3]/td[2]/select/option[2]').click()

#A estado
browser.find_element_by_xpath('//*[@id="headerEPN"]/table[3]/tbody/tr/td/table/tbody/tr[3]/td/table/tbody/tr[2]/td[5]/select/option[15]').click()
#A cuidad
browser.find_element_by_xpath('//*[@id="headerEPN"]/table[3]/tbody/tr/td/table/tbody/tr[3]/td/table/tbody/tr[3]/td[5]/select/option[42]').click()

#Agregar ciudad boton
browser.find_element_by_xpath('//*[@id="headerEPN"]/table[3]/tbody/tr/td/table/tbody/tr[3]/td/table/tbody/tr[5]/td/a').click()

#De estado intermedio
browser.find_element_by_xpath('//*[@id="headerEPN"]/table[3]/tbody/tr/td/table/tbody/tr[3]/td/table/tbody/tr[6]/td[2]/select/option[15]').click()
#A cuidad intermedia
browser.find_element_by_xpath('//*[@id="headerEPN"]/table[3]/tbody/tr/td/table/tbody/tr[3]/td/table/tbody/tr[7]/td[2]/select/option[20]').click()

#Detalles boton
browser.find_element_by_xpath('//*[@id="headerEPN"]/table[3]/tbody/tr/td/table/tbody/tr[3]/td/table/tbody/tr[14]/td/a').click()

#Tamaño del vehiculo
browser.find_element_by_xpath('//*[@id="headerEPN"]/table[3]/tbody/tr/td/table/tbody/tr[3]/td/table/tbody/tr[15]/td[2]/select/option[3]').click()
#Desplazamiento del vehiculo
browser.find_element_by_xpath('//*[@id="headerEPN"]/table[3]/tbody/tr/td/table/tbody/tr[3]/td/table/tbody/tr[15]/td[5]/select/option[4]').click()
#Rendimento del vehiculo
browser.find_element_by_xpath('//*[@id="headerEPN"]/table[3]/tbody/tr/td/table/tbody/tr[3]/td/table/tbody/tr[16]/td[2]/input').send_keys(Keys.BACK_SPACE+Keys.BACK_SPACE+Keys.BACK_SPACE+Keys.BACK_SPACE+Keys.BACK_SPACE+'8.36')
#Gasolina
browser.find_element_by_xpath('//*[@id="headerEPN"]/table[3]/tbody/tr/td/table/tbody/tr[3]/td/table/tbody/tr[16]/td[5]/select/option[2]').click()

#Consultar boton
browser.find_element_by_xpath('//*[@id="headerEPN"]/table[3]/tbody/tr/td/table/tbody/tr[4]/td[2]/input').click()
tabla_casetas = browser.find_element_by_xpath('//*[@id="tContenido"]/tbody')
table_rows = tabla_casetas.find_elements_by_tag_name('tr')
count = 0
estados_holder = {}
for i in range(2, len(table_rows)-10):
    td = table_rows[i].find_elements_by_tag_name('td')
    edo = td[1].text.split(',')
    for ed in edo:
        if ed not in estados_holder:
            estados_holder = ed
        if td[6].text != " ":
            count = count +1

#Total
print('KM: ', browser.find_element_by_xpath('//*[@id="tContenido"]/tbody/tr[24]/td[2]').text)
print('Tiempo: ', browser.find_element_by_xpath('//*[@id="tContenido"]/tbody/tr[24]/td[3]').text)
print('Costo Casetas: ', browser.find_element_by_xpath('//*[@id="tContenido"]/tbody/tr[24]/td[5]').text)
print('Costo combustible: ', browser.find_element_by_xpath('//*[@id="tContenido"]/tbody/tr[26]/td[5]').text)
print('Costo combustible + Casetas: ', browser.find_element_by_xpath('//*[@id="tContenido"]/tbody/tr[28]/td[5]').text)
print('Se recorren :', len(estados_holder), " Estados")
print('Se pagan :', count, " Casetas")
