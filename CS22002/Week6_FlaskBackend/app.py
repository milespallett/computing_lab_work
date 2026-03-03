from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/')
def home():
    return 'Hello, Flask!'

if __name__ == "__name__":
    app.run(debug=True, host='0.0.0.0', port=8000)

@app.route('/user/<name>')
def user(name):
    return f'Hello, {name}!'

@app.route('/search')
def search():
    term = request.args.get('term', 'nothing')
    return f'You searched for: {term}'

@app.route('/text')
def text():
    return 'This is plain text.'

@app.route('/html')
def html():
    return "<h1>Welcome!</h1><p>this is HTML content.</p>"

@app.route('/json')
def json():
    return jsonify({"message": "Success", "status": "ok"})