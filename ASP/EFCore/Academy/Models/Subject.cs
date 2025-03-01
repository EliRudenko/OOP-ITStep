using System.ComponentModel.DataAnnotations;

namespace Models
{
    public class Subject
    {
        public int Id { get; set; }

        [RegularExpression(@"^(?!\s*$).+", ErrorMessage = "Name cannot be empty or whitespace.")]
        public string Name { get; set; }
        public ICollection<Lecture> Lectures { get; set; }
    }
}
