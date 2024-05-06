function showMessage(message) {
    if (typeof message == "number") {
        switch (message) {
            case 1:
                {
                    console.log("Hello world");
                }
                break;
            case 2:
                {
                    console.log("Привет мир");
                }
                break;
        }
    }
    else if (typeof message == "string") {
        console.log(message);
    }
}
showMessage(1);
showMessage("test");
// showMessage(true); // compile error
//# sourceMappingURL=08-overloads.js.map