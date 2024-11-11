from flask import Flask, request, render_template_string,render_template

app = Flask(__name__)

# Variable to store the image URL
image_url = None

@app.route('/malicious_req', methods=['POST','GET'])
def store_image_url():
    global image_url
    # Get the URL from the POST request
    data = request.form.get('image_url')

    if data:
        # Store the URL
        image_url = data
        return f'Image URL stored! You can view the image <a href="/view_image">here</a>.'
    else:
        return 'No image URL provided!', 400

@app.route('/view_image')
def view_image():
    # Display the image if a URL has been stored
    if image_url:
        return f'<h1>Uploaded Image</h1><img src="{image_url}" alt="Image">'
    else:
        return 'No image URL stored yet. Please upload an image URL first.', 400



@app.route('/')
def home():
    return render_template('you_hacked.html')



