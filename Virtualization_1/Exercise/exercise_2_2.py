import requests

icao_code_repo =  {
	"Dusseldorf" : "EDDL", "Frankfurt" : "EDDF", "Tokio" : "RJAA", "Buenos Aires" : "SAEZ", "Vancouver" : "CYVR", "Longyearbyen" : "ENSB", "Goose Bay" : "CYYR"
}

for city in icao_code_repo:
	temp = 0
	response = requests.get(url='https://www.aviationweather.gov/adds/dataserver_current/httpparam?dataSource=metars&requestType=retrieve&format=csv&stationString=' + icao_code_repo[city] + '&hoursBeforeNow=2')
	temp = response.text.rsplit('/', 1)[0].rsplit(' ', 1)[1].replace('M', '-');
	print("The temperature in " + city + "\tis : " + temp + " degrees C")