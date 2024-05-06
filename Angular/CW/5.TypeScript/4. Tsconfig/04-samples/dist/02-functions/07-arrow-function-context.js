function repeatOperation(count, callback) {
    console.log("start");
    for (let i = 0; i < count; i++) {
        callback();
        // контекст данной функции - глобальный объект. Если в функции callback используется контекст он тоже будет ссылаться на глобальный объект.
    }
    console.log("stop");
}
let settings = {
    displayName: "test object",
    test1: function () {
        repeatOperation(3, (function () {
            console.log(this.displayName);
        })); // в данном случае this указывает на объект settings
    },
    test2: function () {
        repeatOperation(3, () => console.log(this.displayName)); // arrow function захватывает контекст, в котором была создана)
    }
};
settings.test1();
settings.test2();
//# sourceMappingURL=07-arrow-function-context.js.map