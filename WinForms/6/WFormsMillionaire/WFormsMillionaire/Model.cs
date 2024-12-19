using System.Media;

namespace WFormsMillionaire
{
    public class Model
    {
        public List<Question> questions;
        public List<Question> finishedQuestions;
        public bool isGameStarted = false;
        public int StablePrize = 0;

        public Model()
        {
            questions = new List<Question>();
            finishedQuestions = new List<Question>();
            CreateQuestions();
        }

        public void CreateQuestions()
        {
            Question tempQ = new Question("Как называется место на берегу, где обитают тюлени?");
            tempQ.AddAnswer("Лежбище", true);
            tempQ.AddAnswer("Стойбище", false);
            tempQ.AddAnswer("Пастбище", false);
            tempQ.AddAnswer("Гульбище", false);
            questions.Add(tempQ);

            tempQ = new Question("Как мировая пресса называла премьер-министра Великобритании Маргарет Тэтчер?");
            tempQ.AddAnswer("Стальная леди", false);
            tempQ.AddAnswer("Железная леди", true);
            tempQ.AddAnswer("Оловянный солдатик", false);
            tempQ.AddAnswer("Крепкий орешек", false);
            questions.Add(tempQ);

            tempQ = new Question("Какой из этих городов южнее остальных?");
            tempQ.AddAnswer("Сан-Франциско", true);
            tempQ.AddAnswer("Мадрид", false);
            tempQ.AddAnswer("Каир", false);
            tempQ.AddAnswer("Токио", false);
            questions.Add(tempQ);

            tempQ = new Question("Через какой город мира проходит нулевой меридиан?");
            tempQ.AddAnswer("Гринвич", true);
            tempQ.AddAnswer("Грозный", false);
            tempQ.AddAnswer("Глазго", false);
            tempQ.AddAnswer("Гронинген", false);
            questions.Add(tempQ);

            tempQ = new Question("Какая птица является символом Новой Зеландии?");
            tempQ.AddAnswer("Казуар", false);
            tempQ.AddAnswer("Киви", true);
            tempQ.AddAnswer("Жако", false);
            tempQ.AddAnswer("Эму", false);
            questions.Add(tempQ);

            tempQ = new Question("Какого короля англичане прозвали \"Львиное сердце\"?");
            tempQ.AddAnswer("Генрих I", false);
            tempQ.AddAnswer("Ричард I", true);
            tempQ.AddAnswer("Вильгельм I", false);
            tempQ.AddAnswer("Георг I", false);
            questions.Add(tempQ);

            tempQ = new Question("Как в народе называются финансовые институты, обещающие вкладчикам золотые горы?");
            tempQ.AddAnswer("Гробницы", false);
            tempQ.AddAnswer("Пирамиды", true);
            tempQ.AddAnswer("Сфинксы", false);
            tempQ.AddAnswer("Захоронения", false);
            questions.Add(tempQ);

            tempQ = new Question("Какая награда вручается вместе с присвоением звания Героя России?");
            tempQ.AddAnswer("Орден мужества", false);
            tempQ.AddAnswer("Медаль \"Золотая Звезда\"", true);
            tempQ.AddAnswer("Медаль \"За отвагу\"", false);
            tempQ.AddAnswer("Орден Суворова", false);
            questions.Add(tempQ);

            tempQ = new Question("В каком городе родился Вольфганг Амадей Моцарт?");
            tempQ.AddAnswer("Прага", false);
            tempQ.AddAnswer("Зальцбург", true);
            tempQ.AddAnswer("Вена", false);
            tempQ.AddAnswer("Веймар", false);
            questions.Add(tempQ);

            tempQ = new Question("Какую реку Юлий Цезарь перешел со словами \"Жребий брошен\"?");
            tempQ.AddAnswer("Рубикон", true);
            tempQ.AddAnswer("Нил", false);
            tempQ.AddAnswer("Припять", false);
            tempQ.AddAnswer("Евфрат", false);
            questions.Add(tempQ);

            tempQ = new Question("Как называется искусство аранжировки цветов?");
            tempQ.AddAnswer("Икебана", true);
            tempQ.AddAnswer("Харакири", false);
            tempQ.AddAnswer("Суши", false);
            tempQ.AddAnswer("Кэндо", false);
            questions.Add(tempQ);

            tempQ = new Question("Какая страна является мировым лидером по производству кофе?");
            tempQ.AddAnswer("Мексика", false);
            tempQ.AddAnswer("Аргентина", false);
            tempQ.AddAnswer("Бразилия", true);
            tempQ.AddAnswer("Венесуэла", false);
            questions.Add(tempQ);

            tempQ = new Question("Что труднее всего дается не трезвому человеку?");
            tempQ.AddAnswer("Вязать лыко", true);
            tempQ.AddAnswer("Витать в облаках", false);
            tempQ.AddAnswer("Трепать нервы", false);
            tempQ.AddAnswer("Бить баклуши", false);
            questions.Add(tempQ);

            tempQ = new Question("Как называют японских мафиози?");
            tempQ.AddAnswer("Джакузи", false);
            tempQ.AddAnswer("Якудза", true);
            tempQ.AddAnswer("Камикадзе", false);
            tempQ.AddAnswer("Коза Ностра", false);
            questions.Add(tempQ);

            tempQ = new Question("Участник какого из перечисленных спортивных состязаний экипирован винтовкой?");
            tempQ.AddAnswer("Биатлон", true);
            tempQ.AddAnswer("Бейсбол", false);
            tempQ.AddAnswer("Бадминтон", false);
            tempQ.AddAnswer("Бобслей", false);
            questions.Add(tempQ);

            tempQ = new Question("В каком канадском городе находится самая высокая в мире телебашня?");
            tempQ.AddAnswer("Монреаль", false);
            tempQ.AddAnswer("Торонто", true);
            tempQ.AddAnswer("Ванкувер", false);
            tempQ.AddAnswer("Оттава", false);
            questions.Add(tempQ);

            tempQ = new Question("Какой из этих романов написал не Хемингуэй?");
            tempQ.AddAnswer("\"По ком звонит колокол\"", false);
            tempQ.AddAnswer("\"Триумфальная арка\"", true);
            tempQ.AddAnswer("\"Фиеста\"", false);
            tempQ.AddAnswer("\"Острова в океане\"", false);
            questions.Add(tempQ);

            tempQ = new Question("В каком виде спорта прославился Евгений Кафельников?");
            tempQ.AddAnswer("Бокс", false);
            tempQ.AddAnswer("Теннис", true);
            tempQ.AddAnswer("Метание ядра", false);
            tempQ.AddAnswer("Охота на лис", false);
            questions.Add(tempQ);

            tempQ = new Question("Как называется пара, присутствующая на церемонии бракосочетания вместе с молодыми?");
            tempQ.AddAnswer("Запасные", false);
            tempQ.AddAnswer("Свидетели", true);
            tempQ.AddAnswer("Соучастники", false);
            tempQ.AddAnswer("Защитники", false);
            questions.Add(tempQ);

            tempQ = new Question("Как звали невесту Эдмона Дантеса, будущего графа Монте-Кристо?");
            tempQ.AddAnswer("Лада", false);
            tempQ.AddAnswer("Мерседес", true);
            tempQ.AddAnswer("Хонда", false);
            tempQ.AddAnswer("Тойота", false);
            questions.Add(tempQ);

            tempQ = new Question("Какой цвет получается при смешении синего и красного?");
            tempQ.AddAnswer("Зеленый", false);
            tempQ.AddAnswer("Фиолетовый", true);
            tempQ.AddAnswer("Коричневый", false);
            tempQ.AddAnswer("Голубой", false);
            questions.Add(tempQ);

            tempQ = new Question("Какая компания в Италии выпускает наибольшее количество автомобилей?");
            tempQ.AddAnswer("Альфа Ромео", false);
            tempQ.AddAnswer("Фиат", true);
            tempQ.AddAnswer("Феррари", false);
            tempQ.AddAnswer("Ламборгини", false);
            questions.Add(tempQ);

            tempQ = new Question("Кто из древних философов, по преданию, жил в бочке?");
            tempQ.AddAnswer("Сократ", false);
            tempQ.AddAnswer("Диоген", true);
            tempQ.AddAnswer("Демокрит", false);
            tempQ.AddAnswer("Платон", false);
            questions.Add(tempQ);

            tempQ = new Question("Каким из этих природных явлений А.Островский назвал свою пьесу?");
            tempQ.AddAnswer("Снегопад", false);
            tempQ.AddAnswer("Гроза", true);
            tempQ.AddAnswer("Шаровая молния", false);
            tempQ.AddAnswer("Гололед", false);
            questions.Add(tempQ);

            tempQ = new Question("Какой туман кажется В.Добрынину похожим на обман в одной из его песен?");
            tempQ.AddAnswer("Утренний", false);
            tempQ.AddAnswer("Синий", false);
            tempQ.AddAnswer("Желтый", true);
            tempQ.AddAnswer("Сиреневый", false);
            questions.Add(tempQ);

            tempQ = new Question("Кому принадлежат строки - пророчества: \"Настанет год, России черный год, Когда царей корона упадет...\"");
            tempQ.AddAnswer("Нострадамус", false);
            tempQ.AddAnswer("Лермонтов", true);
            tempQ.AddAnswer("Пушкин", false);
            tempQ.AddAnswer("Некрасов", false);
            questions.Add(tempQ);

            tempQ = new Question("Как называется маскировочная окраска военной техники и обмундирования?");
            tempQ.AddAnswer("Макияж", false);
            tempQ.AddAnswer("Камуфляж", true);
            tempQ.AddAnswer("Хаки", false);
            tempQ.AddAnswer("Камуфлет", false);
            questions.Add(tempQ);

            tempQ = new Question("Какой материк омывается всеми четырьмя океанами?");
            tempQ.AddAnswer("Австралия", false);
            tempQ.AddAnswer("Евразия", false);
            tempQ.AddAnswer("Южная Америка", true);
            tempQ.AddAnswer("Северная Америка", false);
            questions.Add(tempQ);

            tempQ = new Question("Какие машины предпочитал угонять Юрий Деточкин?");
            tempQ.AddAnswer("Победа", false);
            tempQ.AddAnswer("Жигули", true);
            tempQ.AddAnswer("Иномарки", false);
            tempQ.AddAnswer("Волга", false);
            questions.Add(tempQ);

            tempQ = new Question("Какой остров является самым большим по площади?");
            tempQ.AddAnswer("Гренландия", true);
            tempQ.AddAnswer("Новая Гвинея", false);
            tempQ.AddAnswer("Калифорния", false);
            tempQ.AddAnswer("Мадагаскар", false);
            questions.Add(tempQ);

            tempQ = new Question("Какой язык является официальным в Бразилии?");
            tempQ.AddAnswer("Испанский", false);
            tempQ.AddAnswer("Португальский", true);
            tempQ.AddAnswer("Итальянский", false);
            tempQ.AddAnswer("Французский", false);
            questions.Add(tempQ);

            tempQ = new Question("Кто написал роман \"Преступление и наказание\"?");
            tempQ.AddAnswer("Гоголь", false);
            tempQ.AddAnswer("Достоевский", true);
            tempQ.AddAnswer("Толстой", false);
            tempQ.AddAnswer("Чехов", false);
            questions.Add(tempQ);

            tempQ = new Question("Какая страна считается родиной Олимпийских игр?");
            tempQ.AddAnswer("Италия", false);
            tempQ.AddAnswer("Греция", true);
            tempQ.AddAnswer("Франция", false);
            tempQ.AddAnswer("Испания", false);
            questions.Add(tempQ);

            tempQ = new Question("Какой элемент периодической таблицы имеет символ 'Fe'?");
            tempQ.AddAnswer("Кальций", false);
            tempQ.AddAnswer("Железо", true);
            tempQ.AddAnswer("Цинк", false);
            tempQ.AddAnswer("Медь", false);
            questions.Add(tempQ);

            tempQ = new Question("Какой орган в человеческом теле отвечает за фильтрацию крови?");
            tempQ.AddAnswer("Печень", false);
            tempQ.AddAnswer("Почки", true);
            tempQ.AddAnswer("Легкие", false);
            tempQ.AddAnswer("Сердце", false);
            questions.Add(tempQ);

            tempQ = new Question("Какая страна является самой крупной по площади?");
            tempQ.AddAnswer("Канада", false);
            tempQ.AddAnswer("Россия", true);
            tempQ.AddAnswer("США", false);
            tempQ.AddAnswer("Китай", false);
            questions.Add(tempQ);

            tempQ = new Question("Какой океан самый глубокий?");
            tempQ.AddAnswer("Атлантический", false);
            tempQ.AddAnswer("Тихий", false);
            tempQ.AddAnswer("Индийский", false);
            tempQ.AddAnswer("Южный", true);
            questions.Add(tempQ);

            tempQ = new Question("Что из перечисленного является химическим элементом?");
            tempQ.AddAnswer("Вода", false);
            tempQ.AddAnswer("Кислород", true);
            tempQ.AddAnswer("Соль", false);
            tempQ.AddAnswer("Метан", false);
            questions.Add(tempQ);
        }

        public int PickRand()
        {
            if (questions.Count == 0)
                return -1;

            Random random = new Random();
            return random.Next(0,questions.Count);
        }

        public bool IsAnswerCorrect(Answer answer)
        {
            return answer.IsCorrect;
        }


        public bool IsQuestionFinished(Question question)
        {
            return finishedQuestions.Contains(question);
        }

        public async void Pause()
        {
            await Task.Delay(2000);
        }

        public void StartSound()
        {
            SoundPlayer sp = new SoundPlayer("begin.wav");
            if (isGameStarted)
            {
                sp.Stop();
                return;
            }
            sp.Play();
            isGameStarted = true;
        }


        public void Sound(string path)
        {
            SoundPlayer sp = new SoundPlayer(path);
            sp.Play();
        }

        public void RestartAll()
        {
            finishedQuestions.Clear();
            StablePrize = 0;
        }
        

    }
}
