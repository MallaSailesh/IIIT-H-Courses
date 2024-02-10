from flask import Flask
app = Flask(__name__)

@app.route('/')
def index():
     return "Hello"

@app.route('/hello/<name>')
def hello_name(name):
    return "Hello %s" % name

@app.route('/hello/<int:num>')
def int_num(num):
    return "%d is my number" % num

if __name__ == '__main__':
    app.run(debug=True)