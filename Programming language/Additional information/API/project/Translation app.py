import requests

url = "https://api.one-api.ir/translate/v1/google/"
headers = {
    "accept": "application/json",
    "one-api-token": "", 
    "Content-Type": "application/json"
}
data = {
    "source": "en",
    "target": "fa",
    "text": "Hello World!"
}

response = requests.post(url, headers=headers, json=data)

if response.status_code == 200:
    result = response.json()
    print(result)
else:
    print("Error:", response.status_code, response.text)
