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
    data.forEach((player, index) => {
        const row = document.createElement("tr");
        row.innerHTML = `
            <td>${player.name}</td>
            <td>${player.score}</td>
        `
        if (index === 0){
            row.classList.add("top-player");
        }
        table.appendChild(row);

    })
}

function sortLeaderboard(data) {
    data.sort(function(a, b){return b.score - a.score});
    populateLeaderboard(players);
}

function addPlayer(){
    const name = document.getElementById("newName").value;
    const score = parseInt(document.getElementById("newScore").value);
    if (name && !isNaN(score)){
        players.push({ name, score });
        sortLeaderboard(players);
        document.getElementById("newName").value = "";
        document.getElementById("newScore").value = "";
    } else {
        alert("Please provide valid inputs");
    }
}

function filterLeaderboard(){
    const minScore = parseInt(document.getElementById("minScore").value);

    if (!isNaN(minScore)){
        const filteredPlayers = players.filter(player => player.score >= minScore);
        populateLeaderboard(filteredPlayers);
    } else {
        alert("Please provide a valid input")
    }
}

//On page load
populateLeaderboard(players);
sortLeaderboard(players);