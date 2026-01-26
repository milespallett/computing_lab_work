let players = [
    { name: "Alice", score: 150 },
    { name: "Bob", score: 200 },
    { name: "Charlie", score: 100 }
];

function populateLeaderboard(data) {
    const table = document.getElementById("leaderboard");
    //reset table content everytime it is populated↴
    table.innerHTML = `
        <tr>
            <td>Name</td>
            <td>Score</td>
        </tr>
    `
    data.forEach(player => {
        const row = document.createElement("tr");
        row.innerHTML = `
            <td>${player.name}</td>
            <td>${player.score}</td>
        `
        table.appendChild(row);
    })
}

function sortLeaderboard(data) {
    data.sort(function(a, b){return a.score - b.score});
    populateLeaderboard(players);
}

function addPlayer(){
    const newName = document.getElementById("newName").value;
    const newScore = parseInt(document.getElementById("newScore").value);
    
    if (newName && !isNaN(newScore)){
        players.push({ newName, newScore });
        sortLeaderboard(players);
        document.getElementById("newName").value = "";
        document.getElementById("newScore").value = "";
    } else {
        alert("Please provide valid inputs");
    }
}

//On page load
populateLeaderboard(players);
sortLeaderboard(players);