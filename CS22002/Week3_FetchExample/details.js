const params = new URLSearchParams(window.location.search);
const userId = params.get('id');

fetch(`https://dummyjson.com/users/${userId}`)
    .then(response => response.json())
    .then(data => {
        const detailsDiv = document.getElementById('staffDetails');
        detailsDiv.innerHTML = `
            <h2>${data.firstName} ${data.lastName}</h2>
            <p>Email: ${data.email}</p>
            <p>Phone: ${data.phone}</p>
            <p>Age: ${data.age}</p>
            <p>Address: ${data.address.city}, ${data.address.state}</p>
        `;
    })
    .catch(error => console.error('Error:', error));