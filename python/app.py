from flask import Flask, render_template

app = Flask(__name__)

@app.route("/home")
def first_fun():
	return render_template("sample.html")


if __name__ == "__main__":
	app.run(debug=True)

