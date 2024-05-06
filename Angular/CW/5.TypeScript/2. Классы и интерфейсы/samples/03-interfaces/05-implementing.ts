interface Report {
    name: string;
    build: () => string;
}

// implements - ключевое слово для реализации интерфейса в классе
// если члены интерфейса не будут определены в классе компилятор выдаст ошибку
class DailyReport implements Report {
    name: string = "Daily Report";
    build2(a?: string): string {
        return "some daili report data " + a;
    }
    build(): string {
        return "some daili report data " + this.name;
    }
}

class WeaklyReport implements Report {
    name: string = "Weakly Report";

    build(): string {
        return "some weakly report data";
    }
}

console.log(new DailyReport().build2("hello"));
console.log(new WeaklyReport().build());

let ref: Report = new DailyReport();
console.log(ref.name);
console.log(ref.build());

ref = new WeaklyReport();
console.log(ref.name);
console.log(ref.build());
