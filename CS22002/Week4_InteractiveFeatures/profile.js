function loadUserProfile(){
    const users = JSON.parce(localStorage.getItem("users")) || [];
    const params = new URLSearchParams(window.location.search);
    const userID = params.get("userID");

    const user = users.find(u => u.login.uuid === userID);
    if (!user) {
        document.getElementById("profileContainer").innerHTML = `<h3>No users found</h3>`;
        return;
    }

    document.getElementById("profileContainer").innerHTML = `
        <div class="card">
            <img src="${user.image.large}" class="card-img-top" alt="${user.name.first}">
            <div class="card-body">
                <h5 class="card-title">${user.name.first} ${user.name.last}</h5>
                <p>Email: ${user.email}</p>
                <p>Phone: ${user.phone}</p>
                <p>Location: ${user.location.city}, ${user.location.country}</p>
                <a href="index.html" class="btn btn-secondary">Back to Search</a>
            </div>
        </div>
    `;
}

loadUserProfile();