using System.ComponentModel.DataAnnotations;

namespace Models
{
    public class Lecture
    {
        public int Id { get; set; }

        [RegularExpression(@"^(?!\s*$).+", ErrorMessage = "Name cannot be empty or whitespace.")]
        public string LectureRoom { get; set; }
        public int SubjectId { get; set; }
        public int TeacherId { get; set; }
        public Subject Subject { get; set; } = null!;
        public Teacher Teacher { get; set; } = null!;

        public ICollection<Group> Groups { get; set; } = null!;
    }
}
