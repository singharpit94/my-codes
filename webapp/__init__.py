from flask import Flask,render_template

app = Flask(__name__)

@app.route('/')
def index():
    return "Hello Arpit"

@app.route('/hello')
def hello():
    return "Hello, Sameetha"
@app.route('/render')
def render():
    return render_template('render.html')


    
        
        
    
    
    
    
if __name__ == '__main__':
    app.run(debug=True)
