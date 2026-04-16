class ATM {
    constructor(amount, name) {
        this.balance = amount;
        this.name = name;
    }

    deposit(amount) {
        this.balance += amount;
    }

    getData() {
        console.log(`Balance of ${this.name} is: ${this.balance}`);
    }
}

// Creating objects
let a = new ATM(100000, "yash");

// In JS, objects are reference-based → this is NOT a true copy
let b = Object.assign({}, a); // shallow copy

// But this loses class methods, so better way:
let bObj = new ATM(a.balance, a.name); // proper copy

bObj.deposit(1111);
bObj.getData();