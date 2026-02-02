fetch('https://jsonplaceholder.typicode.com/posts/1')
    .then(response => response.text())
    .then(data => {
        console.log('Response:', data);
        document.getElementById('output').textContent = data;
    })
    .catch(error => console.error('Error:', error));

fetch('https://dummyjson.com/users/1')
    .then(response => response.json())
    .then(data => {
        const userDiv = document.getElementById('user');
        userDiv.innerHTML = `
            <h2>${data.firstName} ${data.lastName}</h2>
            <p>Email: ${data.email}</p>
            <p>Phone: ${data.phone}</p>
        `;
    })
    .catch(error => console.error('Error:', error));

fetch('https://dummyjson.com/users')
    .then(response => response.json())
    .then(data => {
        const staffList = document.getElementById('staffList');
        data.users.forEach(user => {
            const staffCard = document.createElement('div');
            staffCard.innerHTML = `
                <h2>${user.firstName} ${user.lastName}</h2>
                <a href="details.html?id=${user.id}">View Details</a>
            `;
            staffList.appendChild(staffCard);
        });
    })
    .catch(error => console.error('Error:', error));