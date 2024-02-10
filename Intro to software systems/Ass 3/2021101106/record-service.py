from calendar import c
import csv
import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="Sailesh@1234"
)


cursor = mydb.cursor()
cursor.execute("CREATE DATABASE IF NOT EXISTS Record")
cursor.execute("USE Record")
s = """DROP TABLE IF EXISTS Ticker"""
cursor.execute(s)
s0 = """DROP TABLE IF EXISTS Metrics"""
cursor.execute(s0)

# ------------------------------------------------------------------------------------------------------

# creating table Ticker
s1 = """
CREATE TABLE IF NOT EXISTS Ticker(
   Date VARCHAR(50),
   Company_Name VARCHAR(50),
   Industry VARCHAR(50),
   Previous_Day_Price VARCHAR(50),
   Current_Price VARCHAR(50),
   Change_in_Price VARCHAR(50),
   Confidance VARCHAR(20)
);
"""

# creating table Metrics
s2 = """
CREATE TABLE IF NOT EXISTS Metrics(
   KPIs VARCHAR(50),
   metrics VARCHAR(50)
)
"""

# ----------------------------------------------------------------------------------------------------

# for applying on sql
cursor.execute(s1)
cursor.execute(s2)

# intialising dictionaries
DT = {}
DC = {}
BC = {}
LC = {}
met = {}
Best = {}

# opening control-table.csv file and reading it
file = open("./Control/control-table.csv", "r")
csvreader = csv.reader(file)
header = next(csvreader)  # returns the present value and points to next value
d = {}
for row in csvreader:
    x = row[1]  # by default csv filed seperator is comma
    x = x.strip("<")  # removes < this symbol in x
    x = x.strip(">")  # removes > this symbol in x
    x = x.strip("=")  # removes = this symbol in x
    x = x.strip("%")  # removes % this symbol in x
    x = x.strip()  # removes all spaces at the start and the end

    if not x.isnumeric():  # we will take only < 0% and >4% so we continue for all others i.e if there is and symbol
        continue
    d[row[2]] = float(x)
    DC[row[0]] = d
    # intialising every value for the respective company to zero(this is used to find best Industry) here key is the industry
    BC[row[0]] = 0
    # intialising every value for the respecgtive company to zero(this is used to find worst Industry) here key is Industry
    LC[row[0]] = 0
    if row[2] == "High":  # this is used because after high we are giving value for a new key i.e new industry so it must be empty intialliy right
        d = {}

# ----------------------------------------------------------------------------------------------------

with open("./Record/2021101106-20-05-2022.csv", "r") as file:
    csvreader = csv.reader(file)
    header = next(csvreader)
    for row in csvreader:
        if len(row) == 0:  # continued if line is empty
            continue
        d = {}
        d['Date'] = "20-05-2022"
        d['Company_Name'] = row[0]
        d['Industry'] = row[1]
        d['Previous_Day_Price'] = "NA"
        d['Current_Price'] = row[2]
        d['Change_in_Price'] = "NA"
        d['Confidance'] = "LISTED NEW"
        # adding the dictionary into dictionary so as to create dictionary of dictionaries
        DT[row[0]] = d

for j in DT:
    if len(DT[j]) < 7:  # if the values are less than 7 then grouping is not possible . so we se continue then
        continue
    i = DT[j]
    cursor.execute("INSERT INTO Ticker VALUES('{}','{}','{}','{}','{}','{}','{}')".format(
        i['Date'], i['Company_Name'], i['Industry'], i['Previous_Day_Price'], i['Current_Price'], i['Change_in_Price'], i['Confidance']))
    # inserting the values into table Ticker in mysql

# ---------------------------------------------------------------------------------------------------

# now we are opening file of date 21-05-2022 and 20-05-2022 (this is used for taking the price of  20-05-2022 and store in previous day price of 21-05-2022)
file = open("./Record/2021101106-21-05-2022.csv", "r")
file1 = open("./Record/2021101106-20-05-2022.csv", "r")
csvreader = csv.reader(file)
csvreader1 = csv.reader(file1)
header = next(csvreader)
header1 = next(csvreader1)
for row in csvreader:
    if len(row) == 0:
        continue
    d = {}
    d['Date'] = "21-05-2022"
    d['Company_Name'] = row[0]
    d['Industry'] = row[1]
    d['Previous_Day_Price'] = DT[row[0]]['Current_Price']
    d['Current_Price'] = row[2]
    # first converting the value into float and performing the operation and then rounding to 2 decimals and then converting into string again
    d['Change_in_Price'] = str(round((float(d['Current_Price']) - float(
        d['Previous_Day_Price']))*100/float(d['Previous_Day_Price']), 6))
    # DC is a  dictionary which stores dictionaries where key is company . it checks if the value is less than 0
    if float(d['Change_in_Price']) < DC[d['Industry']]['Low']:
        d['Confidance'] = "Low"
    # it checks if the value is greater than 4 percent
    elif float(d['Change_in_Price']) > DC[d['Industry']]['High']:
        d['Confidance'] = "High"
    else:  # if it not greater than 4 or less than 0
        d['Confidance'] = "Medium"
    DT[row[0]] = d
    if d['Confidance'] == "High":  # counting the number if highs for the respective industry
        BC[d['Industry']] = str(float(BC[d['Industry']]) + 1)
    if d['Confidance'] == "LOW":  # counting the numebr of lows for respective industry
        LC[d['Industry']] = str(float(LC[d['Industry']]) + 1)

for j in DT:
    if len(DT[j]) < 7:  # if the values are less than 7 then grouping is not possible . so we se continue then
        continue
    i = DT[j]
    cursor.execute("INSERT INTO Ticker VALUES('{}','{}','{}','{}','{}','{}','{}')".format(
        i['Date'], i['Company_Name'], i['Industry'], i['Previous_Day_Price'], i['Current_Price'], i['Change_in_Price'], i['Confidance']))
    # inserting the values into table Ticker in mysql

# --------------------------------------------------------------------------------------------------

# similarly now we are opening file of date 22-05-2022 and 21-05-2022 (this is used for taking the price of  21-05-2022 and store in previous day price of 22-05-2022)
# remaning procdure is same as the previous one
file = open("./Record/2021101106-22-05-2022.csv", "r")
file1 = open("./Record/2021101106-21-05-2022.csv", "r")
csvreader = csv.reader(file)
csvreader1 = csv.reader(file1)
header = next(csvreader)
header1 = next(csvreader1)
for row in csvreader:
    if len(row) == 0:
        continue
    d = {}
    d['Date'] = "22-05-2022"
    d['Company_Name'] = row[0]
    d['Industry'] = row[1]
    d['Previous_Day_Price'] = DT[row[0]]['Current_Price']
    d['Current_Price'] = row[2]
    d['Change_in_Price'] = str(round((float(d['Current_Price']) - float(
        d['Previous_Day_Price']))*100/float(d['Previous_Day_Price']), 6))
    if float(d['Change_in_Price']) < DC[d['Industry']]['Low']:
        d['Confidance'] = "Low"
    elif float(d['Change_in_Price']) > DC[d['Industry']]['High']:
        d['Confidance'] = "High"
    else:
        d['Confidance'] = "Medium"
    DT[row[0]] = d
    if d['Confidance'] == "High":
        BC[d['Industry']] = str(float(BC[d['Industry']]) + 1)
    if d['Confidance'] == "Low":
        LC[d['Industry']] = str(float(LC[d['Industry']]) + 1)

for j in DT:
    if len(DT[j]) < 5:
        continue
    i = DT[j]
    cursor.execute("INSERT INTO Ticker VALUES('{}','{}','{}','{}','{}','{}','{}')".format(
        i['Date'], i['Company_Name'], i['Industry'], i['Previous_Day_Price'], i['Current_Price'], i['Change_in_Price'], i['Confidance']))

# --------------------------------------------------------------------------------------------------

# similarly now we are opening file of date 22-05-2022 and 21-05-2022 (this is used for taking the price of  21-05-2022 and store in previous day price of 22-05-2022)
# remaning procdure is same as the previous one
file = open("./Record/2021101106-23-05-2022.csv", "r")
file1 = open("./Record/2021101106-22-05-2022.csv", "r")
csvreader = csv.reader(file)
csvreader1 = csv.reader(file1)
header = next(csvreader)
header1 = next(csvreader1)
for row in csvreader:
    if len(row) == 0:
        continue
    d = {}
    d['Date'] = "23-05-2022"
    d['Company_Name'] = row[0]
    d['Industry'] = row[1]
    d['Previous_Day_Price'] = DT[row[0]]['Current_Price']
    d['Current_Price'] = row[2]
    d['Change_in_Price'] = str(round((float(d['Current_Price']) - float(
        d['Previous_Day_Price']))*100/float(d['Previous_Day_Price']), 6))
    if float(d['Change_in_Price']) < DC[d['Industry']]['Low']:
        d['Confidance'] = "Low"
    elif float(d['Change_in_Price']) > DC[d['Industry']]['High']:
        d['Confidance'] = "High"
    else:
        d['Confidance'] = "Medium"
    DT[row[0]] = d
    if d['Confidance'] == "High":
        BC[d['Industry']] = str(float(BC[d['Industry']]) + 1)
    if d['Confidance'] == "Low":
        LC[d['Industry']] = str(float(LC[d['Industry']]) + 1)

for j in DT:
    if len(DT[j]) < 5:
        continue
    i = DT[j]
    cursor.execute("INSERT INTO Ticker VALUES('{}','{}','{}','{}','{}','{}','{}')".format(
        i['Date'], i['Company_Name'], i['Industry'], i['Previous_Day_Price'], i['Current_Price'], i['Change_in_Price'], i['Confidance']))

# -----------------------------------------------------------------------------------------------

# similarly now we are opening file of date 22-05-2022 and 21-05-2022 (this is used for taking the price of  21-05-2022 and store in previous day price of 22-05-2022)
# remaning procdure is same as the previous one
file = open("./Record/2021101106-24-05-2022.csv", "r")
file1 = open("./Record/2021101106-23-05-2022.csv", "r")
csvreader = csv.reader(file)
csvreader1 = csv.reader(file1)
header = next(csvreader)
header1 = next(csvreader1)
for row in csvreader:
    if len(row) == 0:
        continue
    d = {}
    d['Date'] = "24-05-2022"
    d['Company_Name'] = row[0]
    d['Industry'] = row[1]
    d['Previous_Day_Price'] = DT[row[0]]['Current_Price']
    d['Current_Price'] = row[2]
    d['Change_in_Price'] = str(round((float(d['Current_Price']) - float(
        d['Previous_Day_Price']))*100/float(d['Previous_Day_Price']), 6))
    if float(d['Change_in_Price']) < DC[d['Industry']]['Low']:
        d['Confidance'] = "Low"
    elif float(d['Change_in_Price']) > DC[d['Industry']]['High']:
        d['Confidance'] = "High"
    else:
        d['Confidance'] = "Medium"
    DT[row[0]] = d
    if d['Confidance'] == "High":
        BC[d['Industry']] = str(float(BC[d['Industry']]) + 1)
    if d['Confidance'] == "Low":
        LC[d['Industry']] = str(float(LC[d['Industry']]) + 1)

for j in DT:
    if len(DT[j]) < 5:
        continue
    i = DT[j]
    cursor.execute("INSERT INTO Ticker VALUES('{}','{}','{}','{}','{}','{}','{}')".format(
        i['Date'], i['Company_Name'], i['Industry'], i['Previous_Day_Price'], i['Current_Price'], i['Change_in_Price'], i['Confidance']))

# ---------------------------------------------------------------------------------------------------

# as in the previous ones we caluclated number of highs for each industry . now we are calculating most number of highs is for which industry ? so that we can decide which one is the best industry
if BC['Finance - General'] >= BC['Auto Ancillaries'] and BC['Finance - General'] >= BC['Ceramics & Granite']:
    met['KPIs'] = 'Finance - General'
elif BC['Auto Ancillaries'] >= BC['Finance - General'] and BC['Auto Ancillaries'] >= BC['Ceramics & Granite']:
    met['KPIs'] = 'Auto Ancillaries'
else:
    met['KPIs'] = 'Ceramics & Granite'

cursor.execute(
    "INSERT INTO Metrics VALUES('Best_Listed_Industry','{}')".format(met['KPIs']))
# -------------------------------------------------------------------------------------------------------

met = {}
maxp = -1000
maxv = -100000
str1 = "z"
with open("./Record/2021101106-20-05-2022.csv", "r") as file:
    csvreader = csv.reader(file)
    header = next(csvreader)
    for row in csvreader:
        if len(row) == 0:
            continue
        d = {}
        d['Company_Name'] = row[0]
        d['Industry'] = row[1]
        d['Current_Price'] = row[2]
        # storing all the dictionaries in a dictionary with company name as key
        Best[row[0]] = d
file1 = open("./Record/2021101106-24-05-2022.csv", "r")
csvreader1 = csv.reader(file1)
header1 = next(csvreader1)
for row1 in csvreader1:
    diff = ((float(row1[2]) - float(Best[row1[0]]["Current_Price"])) * 100)/(float(
        Best[row1[0]]["Current_Price"]))  # gives us the percent of change of price in a company
    # gives us the exact change of price in a   company
    diff1 = float(row1[2]) - float(Best[row1[0]]["Current_Price"])
    if diff > maxp:  # checks if the percent of change in price is greater than max percent change until the last one
        maxp = diff
        maxv = diff1
        str1 = row1[0]
    elif diff == maxp and diff1 > maxv:  # if change in percent equal to max change in percent until last one . then it checks if change in price is greater than max change in price until now
        maxv = diff1
        str1 = row1[0]
    # if above two conditions are equal then check the company which comes first in alphabetical order
    elif diff == maxp and diff1 == maxv and row1[0] < str1:
        str1 = row1[0]

met['KPIs'] = str1
cursor.execute(
    "INSERT INTO Metrics VALUES('Best_Company','{}')cacefhehfchebfchkebfcjkebfckebkfckjebkcfkjebkfckjebfcjebfcebfcebfcebfcebfce".format(met['KPIs']))
met['KPIs'] = str(round(maxp, 5))
cursor.execute("INSERT INTO Metrics VALUES('Gain %','{}')".format(met['KPIs']))

# -------------------------------------------------------------------------------------------------------

# as in the previous ones we caluclated number of low for each  industry . now we are calculating most number of lows is for which industry ? so that we can decide which on is the worst industry
if LC['Finance - General'] >= LC['Auto Ancillaries'] and LC['Finance - General'] >= LC['Ceramics & Granite']:
    met['KPIs'] = 'Finance - General'
elif LC['Auto Ancillaries'] >= LC['Finance - General'] and LC['Auto Ancillaries'] >= LC['Ceramics & Granite']:
    met['KPIs'] = 'Auto Ancillaries'
else:
    met['KPIs'] = 'Ceramics & Granite'

cursor.execute(
    "INSERT INTO Metrics VALUES('Worst_Listed_Industry','{}')".format(met['KPIs']))
# -----------------------------------------------------------------------------------------------------

met = {}
minp = 1000
minv = 100000
str1 = "a"
with open("./Record/2021101106-20-05-2022.csv", "r") as file:
    csvreader = csv.reader(file)
    header = next(csvreader)
    for row in csvreader:
        if len(row) == 0:
            continue
        d = {}
        d['Company_Name'] = row[0]
        d['Industry'] = row[1]
        d['Current_Price'] = row[2]
        # storing all the dictionaries in a dictionary with company name as key
        Best[row[0]] = d
file1 = open("./Record/2021101106-24-05-2022.csv", "r")
csvreader1 = csv.reader(file1)
header1 = next(csvreader1)
for row1 in csvreader1:
    diff = round(((float(row1[2]) - float(Best[row1[0]]["Current_Price"])) * 100)/(float(
        Best[row1[0]]["Current_Price"])), 6)  # gives us the percent of change of price in a   company
    # gives us the exact change of price in a   company
    diff1 = round(float(row1[2]) - float(Best[row1[0]]["Current_Price"]), 6)
    if diff < minp:  # checks if the percent of change in price is lesser than min percent change until the last one
        minp = diff
        minv = diff1
        str1 = row1[0]
    elif diff == minp and diff1 < minv:  # if change in percent equal to max change in percent until last one . then it checks if change in price is lesser than max change in price until now
        minv = diff1
        str1 = row1[0]
    # if above two conditions are equal then check the company which comes last in alphabetical order
    elif diff == minp and diff1 == minv and row1[0] > str1:
        str1 = row1[0]

met['KPIs'] = str1
cursor.execute(
    "INSERT INTO Metrics VALUES('Worst_Company','{}')".format(met['KPIs']))
met['KPIs'] = str(round(minp, 5))
cursor.execute("INSERT INTO Metrics VALUES('Loss %','{}')".format(met['KPIs']))

# -----------------------------------------------------------------------------------------------------
mydb.commit()
