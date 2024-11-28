using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;

[DataContract]
public class User
{
    [DataMember] public string Login { get; set; }
    [DataMember] public string Password { get; set; }
    [DataMember] public int YearOfBirth { get; set; }
    [DataMember] public List<QuizResult> QuizResults { get; set; } = new();

    public User(string login, string password, int yearOfBirth)
    {
        Login = login;
        Password = password;
        YearOfBirth = yearOfBirth;
    }
}

[DataContract]
public class QuizResult
{
    [DataMember] public string QuizName { get; set; }
    [DataMember] public int CorrectAnswers { get; set; }
    [DataMember] public int TotalQuestions { get; set; }

    public double GetScorePercentage() => (double)CorrectAnswers / TotalQuestions * 100;
}

class Program
{
    private static string usersFile = "users.json";
    private static List<User> users = new();

    static void Main(string[] args)
    {
        LoadUsers();
        EnsureAdminExists();
        Console.WriteLine("Добро пожаловать в Викторину!");

        while (true)
        {
            Console.WriteLine("\n1. Войти\n2. Зарегистрироваться\n3. Выход\nВаш выбор: ");
            string choice = Console.ReadLine();
            switch (choice)
            {
                case "1":
                    Login();
                    break;
                case "2":
                    Register();
                    break;
                case "3":
                    SaveUsers();
                    return;
                default:
                    Console.WriteLine("Неверный выбор.");
                    break;
            }
        }
    }

    private static void Register()
    {
        Console.Write("Введите логин: ");
        string login = Console.ReadLine();
        if (users.Any(u => u.Login == login))
        {
            Console.WriteLine("Пользователь с таким логином уже существует.");
            return;
        }

        Console.Write("Введите пароль: ");
        string password = Console.ReadLine();

        Console.Write("Введите год рождения: ");
        if (!int.TryParse(Console.ReadLine(), out int yearOfBirth))
        {
            Console.WriteLine("Неверный формат года.");
            return;
        }

        users.Add(new User(login, password, yearOfBirth));
        Console.WriteLine("\nРегистрация прошла успешно!\n");
    }

    private static void Login()
    {
        Console.Write("Введите логин: ");
        string login = Console.ReadLine();
        Console.Write("Введите пароль: ");
        string password = Console.ReadLine();

        var user = users.FirstOrDefault(u => u.Login == login && u.Password == password);
        if (user == null)
        {
            Console.WriteLine("Неверный логин или пароль.");
            return;
        }

        if (user.Login == "admin")
        {
            ShowAllUserResults();
        }
        else
        {
            Console.WriteLine($"\nДобро пожаловать, {user.Login}!\n");
            UserMenu(user);
        }
    }

    private static void UserMenu(User user)
    {
        while (true)
        {
            Console.WriteLine("\nМеню\n1. Начать викторину\n2. Посмотреть результаты\n3. Выйти\nВаш выбор: ");
            string choice = Console.ReadLine();
            switch (choice)
            {
                case "1":
                    StartQuiz(user);
                    break;
                case "2":
                    ShowResults(user);
                    break;
                case "3":
                    return;
                default:
                    Console.WriteLine("Неверный выбор.");
                    break;
            }
        }
    }

    private static void StartQuiz(User user)
    {
        Console.WriteLine("\nВыберите раздел викторины: \n1. C++\n2. C#\n3. Выйти\nВаш выбор: ");
        string choice = Console.ReadLine();
        string quizName = choice switch
        {
            "1" => "C++",
            "2" => "C#",
            "3" => null,
            _ => null
        };

        if (quizName == null) return;

        var questions = GenerateQuestions(quizName);
        int correctAnswers = 0;

        foreach (var (question, index) in questions.Select((q, i) => (q, i + 1)))
        {
            Console.WriteLine($"\nВопрос {index}: {question.Text}");
            foreach (var (option, optionIndex) in question.Options.Select((opt, idx) => (opt, idx + 1)))
            {
                Console.WriteLine($"{optionIndex}. {option}");
            }
            Console.Write("Ваш ответ: ");
            string answer = Console.ReadLine();
            if (question.CheckAnswer(answer))
                correctAnswers++;
        }

        user.QuizResults.Add(new QuizResult
        {
            QuizName = quizName,
            CorrectAnswers = correctAnswers,
            TotalQuestions = questions.Count
        });

        Console.WriteLine($"\nВикторина завершена. Правильных ответов: {correctAnswers}/{questions.Count}\n");
    }

    private static void ShowResults(User user)
    {
        Console.WriteLine("\nВаши результаты:");
        if (user.QuizResults.Count == 0)
        {
            Console.WriteLine("Результаты: Не найдены.\n");
            return;
        }

        foreach (var result in user.QuizResults)
        {
            Console.WriteLine($"Викторина по {result.QuizName}: {result.CorrectAnswers}/{result.TotalQuestions} ({result.GetScorePercentage():0}%)");
        }
    }

    private static void ShowAllUserResults()
    {
        Console.WriteLine("\nЛогин пользователя: Результаты всех викторин:");
        foreach (var user in users)
        {
            Console.WriteLine($"{user.Login}:");
            foreach (var result in user.QuizResults)
            {
                Console.WriteLine($"    Викторина {result.QuizName}: {result.CorrectAnswers}/{result.TotalQuestions} ({result.GetScorePercentage():0}%)");
            }
        }
    }

    private static List<Question> GenerateQuestions(string quizName)
    {
        var cPlusPlusQuestions = new List<Question>
        {
            new("Что такое инкапсуляция?", "Сокрытие данных", new[] { "Сокрытие данных", "Передача данных", "Копирование данных" }),
            new("Какой ключевой символ используется для указания указателя?", "*", new[] { "*", "&", "#" }),
            new("Что означает nullptr?", "Пустой указатель", new[] { "Пустой указатель", "Ошибка", "Объект данных" })
        };

        var cSharpQuestions = new List<Question>
        {
            new("Что такое делегат?", "Ссылка на метод", new[] { "Ссылка на метод", "Класс", "Переменная" }),
            new("Как обозначить абстрактный класс?", "abstract", new[] { "abstract", "class", "base" }),
            new("Что делает 'using'?", "Управляет ресурсами", new[] { "Управляет ресурсами", "Объявляет переменную", "Вызывает метод" })
        };

        if (quizName == "C++") return cPlusPlusQuestions;
        if (quizName == "C#") return cSharpQuestions;
        return new List<Question>();
    }

    private static void LoadUsers()
    {
        if (File.Exists(usersFile))
        {
            using var stream = new FileStream(usersFile, FileMode.Open);
            var serializer = new DataContractJsonSerializer(typeof(List<User>));
            users = (List<User>)serializer.ReadObject(stream);
        }
    }

    private static void SaveUsers()
    {
        using var stream = new FileStream(usersFile, FileMode.Create);
        var serializer = new DataContractJsonSerializer(typeof(List<User>));
        serializer.WriteObject(stream, users);
    }

    private static void EnsureAdminExists()
    {
        if (!users.Any(u => u.Login == "admin"))
        {
            users.Add(new User("admin", "admin", 0));
        }
    }
}



[DataContract]
public class Question
{
    [DataMember] public string Text { get; set; }
    [DataMember] public string CorrectAnswer { get; set; }
    [DataMember] public string[] Options { get; set; }

    public Question(string text, string correctAnswer, string[] options)
    {
        Text = text;
        CorrectAnswer = correctAnswer;
        Options = options;
    }

    public bool CheckAnswer(string answer)
    {
        if (int.TryParse(answer, out int index) && index > 0 && index <= Options.Length)
        {
            return Options[index - 1] == CorrectAnswer;
        }
        return false;
    }
}
