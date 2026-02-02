fetch('https://jsonplaceholder.typicode.com/posts/1')
    .then(response => response.text())
    .then(data => {
        console.log('Response:', data);
        document.getElementById('output').textContent = data;
    })
    .catch(error => console.error('Error:', error));