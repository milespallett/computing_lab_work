async function fetchUsers(){
    const response = await fetch("https://randomuser.me/api/?results=20");
    const data = await response.json();

    localStorage.setItem("users", JSON.stringify(data.results));
    return data.results;
}

function createUserCard(user){
    const card = document.createElement("div");
    card.className = "col-md-4 mb-3";
    card.innerHTML = `
        <div class="card">
            <img src="${user.picture.large}" class="card-image-top" alt="${user.name.first}">
            <div class="card-body">
                <h5 class="card-title">${user.name.first} ${user.name.last}</h5>
                <p class="card-text">${user.email}</p>
                <a href="profile.html?userID=${user.login.uuid}" class="btn btn-primary">View Profile</a>
            </div>
        </div>
    `;
    return card;
}

function searchUsers(query){
    const users = JSON.parse(localStorage.getItem("users")) || [];
    const resultsContainer = document.getElementById("userContainer");
    resultsContainer.innerHTML = ``;

    const filteredUsers = users.filter(user => 
        user.name.first.toLowerCase().includes(query.toLowerCase()) ||
        user.name.last.toLowerCase().includes(query.toLowerCase())
    );

    filteredUsers.forEach(user => resultsContainer.appendChild(createUserCard(user)));
}

document.getElementById("searchInput").addEventListener("input", (e) => {
    searchUsers(e.target.value);
})

