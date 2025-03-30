let correctPin = "1234";
let balance = 2000;

function checkPin() {
    let pin = document.getElementById("pinInput").value;
    console.log("Entered PIN:", pin);  // Debugging
    if (pin === correctPin) {
        alert("PIN Correct!");
        document.getElementById("screen").style.display = "none";
        document.getElementById("options").style.display = "block";
    } else {
        alert("Incorrect PIN. Try again.");
    }
}

function showBalance() {
    alert("Your current balance is ₹" + balance);
}

function showWithdrawal() {
    let withdrawAmount = prompt("Enter amount to withdraw:");
    
    if (withdrawAmount === null || withdrawAmount === "") return;  // If user cancels
    withdrawAmount = parseInt(withdrawAmount);

    if (isNaN(withdrawAmount) || withdrawAmount <= 0) {
        alert("Invalid amount. Please enter a valid number.");
    } else if (withdrawAmount % 100 !== 0) {
        alert("Please enter an amount in multiples of 100.");
    } else if (withdrawAmount > balance - 500) {
        alert("Insufficient balance! Minimum ₹500 should be maintained.");
    } else {
        balance -= withdrawAmount;
        alert("₹" + withdrawAmount + " withdrawn successfully! Remaining balance: ₹" + balance);
        document.getElementById("balance").innerText = balance;
    }
}

function showDeposit() {
    let depositAmount = prompt("Enter amount to deposit:");
    
    if (depositAmount === null || depositAmount === "") return;  // If user cancels
    depositAmount = parseInt(depositAmount);

    if (isNaN(depositAmount) || depositAmount <= 0) {
        alert("Invalid amount. Please enter a valid number.");
    } else {
        balance += depositAmount;
        alert("₹" + depositAmount + " deposited successfully! New balance: ₹" + balance);
        document.getElementById("balance").innerText = balance;
    }
}

function exitATM() {
    alert("Thank you for using the ATM!");
    location.reload();
}
