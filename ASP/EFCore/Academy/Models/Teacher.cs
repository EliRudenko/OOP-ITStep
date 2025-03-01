using System.ComponentModel.DataAnnotations;

namespace Models
{
    public class Teacher
    {
        public int Id { get; set; }


        [RegularExpression(@"^(?!\s*$).+", ErrorMessage = "Name cannot be empty or whitespace.")]
        public string Name { get; set; }

        [RegularExpression(@"^(?!\s*$).+", ErrorMessage = "Name cannot be empty or whitespace.")]
        public string Surname { get; set; }
        public decimal Salary { get; set; }
        public ICollection<Lecture> Lectures { get; set; } = null!;
    }
}
