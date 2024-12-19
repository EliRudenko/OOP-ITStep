using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WFormsMillionaire
{
    public class Question
    {
        public string Text { get; set; } 
        public List<Answer> Answers { get; set; } 

        public Question(string text)
        {
            Text = text;
            Answers = [];
        }

        public void AddAnswer(string answerText, bool isCorrect)
        {
            Answers.Add(new Answer(answerText, isCorrect));
        }

    }
    public class Answer
    {
        public string Text { get; set; } 
        public bool IsCorrect { get; set; } 

        public Answer(string text, bool isCorrect)
        {
            Text = text;
            IsCorrect = isCorrect;
        }
    }

}
