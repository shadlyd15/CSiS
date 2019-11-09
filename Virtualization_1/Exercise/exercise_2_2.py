import requests
icao_code_repo = {"Dusseldorf" : "EDDL", "Frankfurt" : "EDDF", "Tokio" : "RJAA", "Buenos Aires" : "SAEZ", "Vancouver" : "CYVR", "Longyearbyen" : "ENSB", "Goose Bay" : "CYYR"}

for city in icao_code_repo:
	response = requests.get(url='https://www.aviationweather.gov/adds/dataserver_current/httpparam?dataSource=metars&requestType=retrieve&format=csv&stationString=' + icao_code_repo[city] + '&hoursBeforeNow=2')
	print("The temperature in " + city + "\tis : " + response.text.rsplit('/', 1)[0].rsplit(' ', 1)[1].replace('M', '-') + " degrees C")