import requests

API_KEY = ""
CITY = "Tehran"
URL = f"http://api.openweathermap.org/data/2.5/weather?q={CITY}&appid={API_KEY}&units=metric"

response = requests.get(URL)

if response.status_code == 200:
    data = response.json()
    temp = data['main']['temp']
    description = data['weather'][0]['description']
    humidity = data['main']['humidity']
    print(f"Weather in {CITY}:\nTemperature: {temp}°C\nDescription: {description}\nHumidity: {humidity}%")
else:
    print("Error while fetching data:", response.status_code)
