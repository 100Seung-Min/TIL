from flask import Flask, escape, request, jsonify
import recommendAI

# 서버 실행
app = Flask(__name__)

@app.route('/')
def hello():
    movieName = request.args.get('movieName', 'The Dark Knight')
    result = recommendAI.callAi(movieName)
    if len(result) < 1 :
        return 'Not Found', 404
    return jsonify(result)