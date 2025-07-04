from flask import Flask, jsonify

app = Flask(__name__)

@app.route('/', methods=['GET'])
def home():
    return jsonify({"message": "Hello, this is my first API!"})

@app.route('/users', methods=['GET'])
def users():
    users_list = [
        {"id": 1, "name": "Ali"},
        {"id": 2, "name": "Sara"}
    ]
    return jsonify(users_list)

if __name__ == '__main__':
    app.run(debug=True)
