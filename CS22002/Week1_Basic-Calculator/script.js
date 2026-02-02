function getNumbers(){
    const num1 = parseFloat(document.getElementById('num1').value);
    const num2 = parseFloat(document.getElementById('num2').value);
    return { num1, num2 };
}

function calculate(operation){
    const { num1, num2 } = getNumbers();
    let result;

    if (isNaN(num1) || isNaN(num2)){
        return "Please enter valid numbers. ";
    }

    switch (operation) {
        case 'add':
            result = num1 + num2;
            break;
        case 'subtract':
            result = num1 - num2;
            break;
        case 'multiply':
            result = num1 * num2;
            break;
        case 'divide':
            result = num2 !== 0 ? num1 / num2 : "Cannot divide by zero. ";
            break;
        default:
            result = "Invalid operation. "
    }
    return result;
}

function addToLog(result){
    document.getElementById('log').textContent = `${document.getElementById('log').textContent} ${result}`;
}

document.getElementById('add').addEventListener('click', () => {
    let res = calculate('add');
    document.getElementById('result').textContent = `Result: ${res}`;
    addToLog(res);
});

document.getElementById('subtract').addEventListener('click', () => {
    let res = calculate('subtract');
    document.getElementById('result').textContent = `Result: ${res}`;
    addToLog(res);
});

document.getElementById('multiply').addEventListener('click', () => {
    let res = calculate('multiply');
    document.getElementById('result').textContent = `Result: ${res}`;
    addToLog(res);
});

document.getElementById('divide').addEventListener('click', () => {
    let res = calculate('divide');
    document.getElementById('result').textContent = `Result: ${res}`;
    addToLog(res);
});

document.getElementById('clear').addEventListener('click', () => {
    document.getElementById('result').textContent = `Result: `;
    document.getElementById('num1').value = "";
    document.getElementById('num2').value = "";
});