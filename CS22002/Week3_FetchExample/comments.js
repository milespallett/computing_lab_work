const params = new URLSearchParams(window.location.search);
const postId = params.get('id');

fetch(`https://dummyjson.com/posts/${postId}`)
    .then(response => response.json())
    .then(data => {
        const postData = document.getElementById('post');
        postData.innerHTML = `
            <h2>${data.title}</h2>
            <p>${data.body}</p>
        `;
    })
    .catch(error => console.error('Error:', error));

fetch(`https://dummyjson.com/posts/${postId}/comments`)
    .then(response => response.json())
    .then(data => {
        const commentsDiv = document.getElementById('comments');
        data.comments.forEach(comment => {
            const commentCard = document.createElement('div');
            commentCard.innerHTML = `
                <p><strong>${comment.user.fullName}: </strong>${comment.body}</p>
            `;
            commentsDiv.appendChild(commentCard);
        });
    })
    .catch(error => console.error('Error:', error));