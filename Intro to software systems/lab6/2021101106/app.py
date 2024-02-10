from flask import Flask , redirect ,url_for , render_template , request
app = Flask(__name__)

@app.route('/calc/sum/<n1>+<n2>')
def sum(n1, n2):
    if(n1.isdecimal() & n2.isdecimal()):
     return render_template('sum.html', n1=n1, n2=n2, ans=float(n1) + float(n2))
    else :
     return render_template('error.html')

@app.route('/calc/multiply/<n1>*<n2>')
def product(n1, n2):
    if(n1.isdecimal() & n2.isdecimal()):
     return render_template('product.html', n1=n1, n2=n2, ans=float(n1) * float(n2))
    else :
     return render_template('error.html')

@app.route('/login/sum', methods=['POST', 'GET'])
def login_sum():
    if request.method == 'POST':
        print("we got POST")
        num1 = request.form['num1']
        num2 = request.form['num2']
        return redirect(url_for('sum', n1=num1, n2=num2))

    num1 = request.form['num1']
    num2 = request.form['num2']
    return redirect(url_for('sum', n1=num1, n2=num2))


@app.route('/login/product', methods=['POST', 'GET'])
def login_product():
    if request.method == 'POST':
        print("we got POST")
        num1 = request.form['num1']
        num2 = request.form['num2']
        return redirect(url_for('product', n1=num1, n2=num2))

    num1 = request.form['num1']
    num2 = request.form['num2']
    return redirect(url_for('product', n1=num1, n2=num2))

@app.route('/calc/sum')
def index_sum():
    return """<html>
    <body>
    <form action = "http://localhost:5000/login/sum" method = "post" >
    <p> Enter num1 </p>
    <p><input type = "text" name = "num1" required/></p>
    <p> Enter num2 </p>
    <p><input type = "text" name = "num2" required/></p>
    <p><input type = "submit" value="submit" /></p>
    </form>
    </body>
    </html>"""

@app.route('/calc/multiply')
def index_product():
    return """<html>
    <body>
    <form action = "http://localhost:5000/login/product" method = "post" >
    <p> Enter num1 </p>
    <p><input type = "text" name = "num1" required/></p>
    <p> Enter num2 </p>
    <p><input type = "text" name = "num2" required/></p>
    <p><input type = "submit" value="submit" /></p>
    </form>
    </body>
    </html>"""


@app.route('/')
def goto_sum():
    return redirect(url_for('index_sum'))


if __name__ == '__main__':
     app.run(debug=True)