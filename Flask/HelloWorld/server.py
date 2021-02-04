from flask import Flask, render_template, request

app = Flask(__name__)


@app.route('/hello')
def helloWorld():
    return 'Hello World!'


@app.route('/hello/<name>')
def helloName(name=None):
    return render_template('test.html', name=name)


@app.route('/')
def index():
    return render_template('login.html')


@app.route('/login', methods=['POST', 'GET'])
def login():
    uname = request.form.get('username')
    pwd = request.form.get('password')
    print(uname)
    print(pwd)
    if (uname == 'rickwayne' and pwd == '123'):
        return 'Login Success'
    else:
        return render_template('login.html', msg='Login Failed')


if __name__ == '__main__':
    app.run()
